#include <utility>

#include "ReadNode.h"

ReadNode::ReadNode(StatementNumber statementNumber, std::shared_ptr<VariableNode> var)
    : StatementNode(statementNumber), var(std::move(var)) {}

std::shared_ptr<VariableNode> ReadNode::getVar() { return var; }

std::vector<std::shared_ptr<ASTNode>> ReadNode::getAllChildNodes() {
    std::vector<std::shared_ptr<ASTNode>> children{var};
    return children;
}

StatementNodeType ReadNode::getStatementType() { return StatementNodeType::Read; }

void ReadNode::accept(std::shared_ptr<DesignExtractorVisitor> visitor, std::vector<std::shared_ptr<Statement>> parents,
                      std::shared_ptr<Procedure> proc) {
    if (auto readVisitor = std::dynamic_pointer_cast<ReadNodeVisitor>(visitor)) {
        readVisitor->visitReadNode(std::enable_shared_from_this<ReadNode>::shared_from_this(), parents, proc);
    }
}