#pragma once

#include <memory>
#include <stack>
#include <unordered_set>

#include "SP/AST/Nodes/ASTNode.h"
#include "SP/AST/Nodes/ProgramNode.h"

/**
 * An SP subcomponent to validate the semantics of the tokenized source program.
 */
class SemanticValidator {
private:
    /**
     * Reference stack to traverse the AST.
     */
    std::stack<std::shared_ptr<ASTNode>> frontier;

public:
    /**
     * Creates and initialises a SemanticValidator.
     */
    SemanticValidator();

    /**
     * Semantically validate current program
     * 1. A program cannot have two procedures with the same name.
     * 2. A procedure cannot call a non-existing procedure.
     * 3. Recursive and cyclic calls are not allowed. i.e. A-->B-->C-->A or A-->A
     * @param root
     */
    void validate(const std::shared_ptr<ProgramNode> &root);
};
