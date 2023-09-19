#include "RelativeExpressionNode.h"

RelativeExpressionNode::RelativeExpressionNode(
        ComparisonOperatorType comparisonOperatorType,
        std::shared_ptr<ExpressionNode> leftExpression,
        std::shared_ptr<ExpressionNode> rightExpression)
        : comparisonOperatorType(comparisonOperatorType),
        leftExpression(std::move(leftExpression)),
        rightExpression(std::move(rightExpression)) {}

ComparisonOperatorType RelativeExpressionNode::getComparisonOperatorType() {
    return comparisonOperatorType;
}

std::shared_ptr<ExpressionNode> RelativeExpressionNode::getLeftExpression() {
    return leftExpression;
}

std::shared_ptr<ExpressionNode> RelativeExpressionNode::getRightExpression() {
    return rightExpression;
}

std::vector<std::shared_ptr<ASTNode>> RelativeExpressionNode::getAllChildNodes() {
    std::vector<std::shared_ptr<ASTNode>> children { leftExpression, rightExpression };
    return children;
}

void RelativeExpressionNode::accept(std::shared_ptr<DesignExtractorVisitor> visitor) {
    if (auto relativeExpressionVisitor = std::dynamic_pointer_cast<RelativeExpressionNodeVisitor>(visitor)) {
        relativeExpressionVisitor->visitRelativeExpressionNode(this);
    }
}