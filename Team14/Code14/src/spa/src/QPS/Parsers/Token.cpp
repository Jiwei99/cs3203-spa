#include "Token.h"
#include "QPS/QPSUtil.h"

#include <regex>
#include <string>
#include <unordered_map>

std::unordered_map<TokenType, int> operatorPrecedence = {
        {TokenType::Asterisk, 1}, {TokenType::Slash, 1}, {TokenType::Percent, 1},
        {TokenType::Plus, 0},     {TokenType::Minus, 0},
};

Token::Token(const std::string &input) {
    this->rep = input;
    if (QPSUtil::strToTokenTypeMap.find(rep) != QPSUtil::strToTokenTypeMap.end()) {
        this->type = QPSUtil::strToTokenTypeMap[rep];
    } else if (!rep.empty()) {
        this->type = TokenType::Word;
    } else {
        this->type = TokenType::Empty;
    }
}

std::string Token::getRep() { return rep; }

TokenType Token::getType() { return type; }

bool Token::isInteger() {
    std::regex pattern("^(0|[1-9]\\d*)$");
    return std::regex_match(rep, pattern);
}

bool Token::isToken(const std::string &str) { return rep == str && type == TokenType::Word; }

bool Token::isToken(TokenType ttype) { return type == ttype; }

bool Token::isDesignEntity() {
    return type == TokenType::Word && QPSUtil::designEntities.find(rep) != QPSUtil::designEntities.end();
}

bool Token::isAttrName() {
    return type == TokenType::Word && (QPSUtil::strToAttrNameMap.find(rep) != QPSUtil::strToAttrNameMap.end());
}

bool Token::isIdent() {
    std::regex pattern("[a-zA-Z][a-zA-Z0-9]*");
    return std::regex_match(rep, pattern);
}

bool Token::isOperand() { return isIdent() || isInteger(); }

bool Token::isOperator() {
    return (isToken(TokenType::Plus) || isToken(TokenType::Minus) || isToken(TokenType::Asterisk) ||
            isToken(TokenType::Slash) || isToken(TokenType::Percent));
}

bool Token::precedes(const std::shared_ptr<Token> other) {
    return operatorPrecedence[type] >= operatorPrecedence[other->getType()];
}
