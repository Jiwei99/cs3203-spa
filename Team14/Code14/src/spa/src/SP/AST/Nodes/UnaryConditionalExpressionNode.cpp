#include "UnaryConditionalExpressionNode.h"

UnaryConditionalExpressionNode::UnaryConditionalExpressionNode(
        std::shared_ptr<ConditionalExpressionNode> conditionalExpression)
    : conditionalExpression(std::move(conditionalExpression)) {}

std::shared_ptr<ConditionalExpressionNode> UnaryConditionalExpressionNode::getConditionalExpression() {
    return conditionalExpression;
}

std::vector<std::shared_ptr<ASTNode>> UnaryConditionalExpressionNode::getAllChildNodes() {
    std::vector<std::shared_ptr<ASTNode>> children{conditionalExpression};
    return children;
}

void UnaryConditionalExpressionNode::accept(std::shared_ptr<DesignExtractorVisitor> visitor,
                                            std::vector<std::shared_ptr<Statement>> parents,
                                            std::shared_ptr<Procedure> proc) {
    if (auto uceVisitor = std::dynamic_pointer_cast<UnaryConditionalExpressionNodeVisitor>(visitor)) {
        uceVisitor->visitUnaryConditionalExpressionNode(
                std::enable_shared_from_this<UnaryConditionalExpressionNode>::shared_from_this(), parents, proc);
    }
}