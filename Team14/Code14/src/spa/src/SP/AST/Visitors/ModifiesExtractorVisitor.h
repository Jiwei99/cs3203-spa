#pragma once

#include <functional>

#include "DesignExtractorVisitor.h"
#include "../../AST/Nodes/AssignNode.h"
#include "../../AST/Nodes/ReadNode.h"

class ModifiesExtractorVisitor : public DesignExtractorVisitor,
    public AssignNodeVisitor,
    public ReadNodeVisitor
{
private:
    std::function<void(std::shared_ptr<Statement>, std::shared_ptr<Variable>)> func;
public:
    /*!
     * Constructor for UsesExtractorVisitor
     */
    ModifiesExtractorVisitor(std::shared_ptr<PkbWriter> pkbWriter);

    /*!
     * Visits an AssignNode and add variables used by the Assignment into PKB
     */
    void visitAssignNode(AssignNode* node, std::vector<std::shared_ptr<ASTNode>> parents) const override;

    /*!
     * Visits a ReadNode and add variable used into PKB
     */
    void visitReadNode(ReadNode* node, std::vector<std::shared_ptr<ASTNode>> parents) const override;
};