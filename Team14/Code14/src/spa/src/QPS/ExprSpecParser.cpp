#include "ExprSpecParser.h"

ExprSpecParser::ExprSpecParser(std::shared_ptr<Tokenizer> tokenizer) : tokenizer(tokenizer){}

ExpressionSpec ExprSpecParser::extractExpressionSpec() {
    std::shared_ptr<Token> curr = tokenizer->peekToken();
    if (curr->isToken(TokenType::Underscore)) { // WILDCARD OR PARTIAL MATCH
        tokenizer->popToken();
        curr = tokenizer->peekToken();
        if (!curr->isToken(TokenType::Quote)) { //WILDCARD
            return {ExpressionSpecType::Wildcard, ""};
        } else {
            Expression expr = extractExpression();
            curr = tokenizer->popToken(); //consume expected trailing underscore
            if (!curr->isToken(TokenType::Underscore)) {
                throw std::runtime_error("Invalid Expression Spec, missing trailing _");
            }
            return {ExpressionSpecType::PartialMatch,expr};
        }
    } else if (curr->isToken(TokenType::Quote)) { // EXACT MATCH
        Expression expr = extractExpression();
        return {ExpressionSpecType::ExactMatch,expr};
    } else {
        throw std::runtime_error("Invalid Expression Spec");
    }
}

Expression ExprSpecParser::extractExpression() {
    std::shared_ptr<Token> curr = tokenizer->peekToken(); // consume Quote
    if (!curr->isToken(TokenType::Quote)) {
        throw std::runtime_error("Invalid expression spec");
    }
    tokenizer->popToken();

    std::stack<std::shared_ptr<Token>> operators;
    std::stack<std::string> expression;
    std::vector<std::shared_ptr<Token>> tokens;

    curr = tokenizer->popToken();
    while (!curr->isToken(TokenType::Quote)) {
        tokens.push_back(curr);
        if (curr->isOperand()) {
            expression.push("(" + curr->getRep() + ")");
        } else if (curr->isToken(TokenType::Lparenthesis)) {
            operators.push(curr);
        } else if (curr->isOperator()) {
            while (!operators.empty()
                   && !operators.top()->isToken(TokenType::Lparenthesis)
                   && operators.top()->precedes(curr)) {
                if (expression.size() < 2) {
                    throw std::runtime_error("not enough factors");
                }
                auto rightOperand = expression.top();
                expression.pop();
                auto leftOperand = expression.top();
                expression.pop();
                expression.push("(" + leftOperand + operators.top()->getRep() + rightOperand + ")");
                operators.pop();
            }
            operators.push(curr);
        } else if (curr->isToken(TokenType::Rparenthesis)) {
            while (!operators.empty() && !operators.top()->isToken(TokenType::Lparenthesis)) {
                if (expression.size() < 2) {
                    throw std::runtime_error("not enough factors");
                }
                auto rightOperand = expression.top();
                expression.pop();
                auto leftOperand = expression.top();
                expression.pop();
                expression.push("(" + leftOperand + operators.top()->getRep() + rightOperand + ")");
                operators.pop();
            }
            if (!operators.top()->isToken(TokenType::Lparenthesis)){ // pop Lparentheses
                throw std::runtime_error("Invalid expression spec");
            }
            operators.pop();
        } else { //unexpected token
            throw std::runtime_error("Invalid expression spec");
        }
        curr = tokenizer->popToken();
    }
    while(!operators.empty()) {
        if (expression.size() < 2) {
            throw std::runtime_error("not enough factors");
        }
        auto rightOperand = expression.top();
        expression.pop();
        auto leftOperand = expression.top();
        expression.pop();
        expression.push("(" + leftOperand + operators.top()->getRep() + rightOperand + ")");
        operators.pop();
    }

    if (expression.empty() || expression.size() > 1) { // empty expression OR too many factors e.g "x y"
        throw std::runtime_error("Invalid Expression Spec");
    }
    if (!validateExprSyntax(tokens)) {
        throw std::runtime_error("Invalid Expression Spec from VALIDATE");
    }
    return expression.top();
}

bool ExprSpecParser::validateExprSyntax(std::vector<std::shared_ptr<Token>>& input) {
    size_t currIndex = 0;
    return isExpr(input, currIndex) && currIndex == input.size();
}

bool ExprSpecParser::isExpr(std::vector<std::shared_ptr<Token>>& input, size_t& index) {
    if (index >= input.size()) {
        return false;
    }
    if(isTerm(input, index)) {
        while (index < input.size()
               && (input[index]->isToken(TokenType::Plus)
                   || input[index]->isToken(TokenType::Minus))) {
            index++;
            if (!isTerm(input, index)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool ExprSpecParser::isTerm(std::vector<std::shared_ptr<Token>>& input, size_t& index) {
    if (index >= input.size()) {
        return false;
    }
    if (isFactor(input, index)) {
        while (index < input.size()
               && (input[index]->isToken(TokenType::Asterisk)
                   || input[index]->isToken(TokenType::Slash)
                   || input[index]->isToken(TokenType::Percent))) {
            index++;
            if (!isFactor(input, index)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool ExprSpecParser::isFactor(std::vector<std::shared_ptr<Token>>& input, size_t& index) {
    if (index >= input.size()) {
        return false;
    }
    if (input[index]->isIdent() || input[index]->isInteger()) {
        index++;
        return true;
    }
    if (input[index]->isToken(TokenType::Lparenthesis)) {
        index++;
        bool hasValidExpr = isExpr(input, index);
        if (hasValidExpr && index < input.size()) {
            bool hasRParenthesis = input[index]->isToken(TokenType::Rparenthesis);
            index++;
            return hasRParenthesis;
        }
    }
    return false;
}
