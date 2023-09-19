#pragma once

#include <vector>

#include "ASTNode.h"
#include "StatementNode.h"

class StatementListNode; // forward declaration
class StatementListNodeVisitor {
public:
    virtual void visitStatementListNode(StatementListNode* node) const = 0;
};

class StatementListNode : public ASTNode {
private:
    std::vector<std::shared_ptr<StatementNode>> statements;
public:
    explicit StatementListNode(std::vector<std::shared_ptr<StatementNode>> statements);
    std::vector<std::shared_ptr<StatementNode>> getStatements();
    void accept(std::shared_ptr<DesignExtractorVisitor> visitor) override;
    std::vector<std::shared_ptr<ASTNode>> getAllChildNodes() override;
};