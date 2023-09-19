#pragma once

#include <string>
#include <vector>
#include "SPToken.h"

class SyntacticValidator {
public:
    SyntacticValidator(const std::vector<SPToken>& tokens);
    std::vector<SPToken> validate();

private:
    int curr;
    std::vector<SPToken> tokens;

    void validateProcedure();

    void validateStmtLst();

    void validateRead();
    void validatePrint();
    void validateCall();
    void validateAssign();

    void validateExpr();
    void validateTerm();

    void validateWhile();
    void validateIf();
    void validateThen();
    void validateElse();
    void validateConditionalExpression();
    void validateRelationalExpression();

    void validateName(); // var_name or proc_name
    void validateInteger();
    void validateOpenRoundParan();
    void validateCloseRoundParan();
    void validateOpenCurlyParan();
    void validateCloseCurlyParan();
    void validateSemicolon();
    void validateEquals();
    void validateArithmeticOperator();
    void validateAndOrOperator();
    void validateRelationalOperator();

    SPToken peekToken();
    SPToken peekNextToken();
    SPToken popToken();
    bool isCurrValid();
};