#pragma once

#include <memory>

#include "Commons/AppConstants.h"
#include "StatementNode.h"
#include "VariableNode.h"
#include "ExpressionNode.h"

class AssignNode; // forward declaration

/**
 * Visitor interface linked to AssignNode, used to implement the Acyclic Visitor pattern.
 */
class AssignNodeVisitor {
public:
    /**
     * Visits the AssignNode for design extraction.
     * @param node AssignNode to be visited
     * @param parents Parents of the AssignNode
     */
    virtual void visitAssignNode(AssignNode* node, std::vector<std::shared_ptr<ASTNode>> parents) const = 0;
};

/**
 * ASTNode to represent an assignment statement.
 * Inherits from the StatementNode abstract class.
 */
class AssignNode : public StatementNode {
private:
    /**
     * The variable that is assigned to.
     */
    std::shared_ptr<VariableNode> var;

    /**
     * The expression that is assigned.
     */
    std::shared_ptr<ExpressionNode> expression;
public:
    /**
     * Creates and initializes an AssignNode.
     * @param statementNumber The statement number of this statement
     * @param var The LHS variable that is assigned to
     * @param expression The RHS expression that is assigned
     */
    explicit AssignNode(StatementNumber statementNumber,
                        std::shared_ptr<VariableNode> var,
                        std::shared_ptr<ExpressionNode> expression);

    /**
     * Returns the variable that is assigned to.
     * @return The variable assigned to, on the LHS of the assignment
     */
    std::shared_ptr<VariableNode> getVar();

    /**
     * Returns the expression that is assigned.
     * @return The expression assigned, on the RHS of the assignment
     */
    std::shared_ptr<ExpressionNode> getExpression();

    void accept(std::shared_ptr<DesignExtractorVisitor> visitor, std::vector<std::shared_ptr<ASTNode>> parents) override;

    std::vector<std::shared_ptr<ASTNode>> getAllChildNodes() override;

    StatementNodeType getStatementType() override;
};
