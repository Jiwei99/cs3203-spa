#pragma once

#include <memory>

#include "PKB/Managers/AssignmentManager.h"
#include "PKB/EntityStores/ConstantStore.h"
#include "PKB/EntityStores/ProcedureStore.h"
#include "PKB/EntityStores/StatementStore.h"
#include "PKB/EntityStores/VariableStore.h"
#include "PKB/RelationshipStores/FollowsRelationshipStore.h"
#include "PKB/RelationshipStores/UsesRelationshipStore.h"
#include "../Commons/Entities/Constant.h"
#include "../Commons/Entities/Procedure.h"
#include "../Commons/Entities/Variable.h"
#include "../Commons/Entities/Statement.h"
#include "PKB/Managers/PkbWriterManager.h"

class PkbWriter {
private:
    std::shared_ptr<PkbWriterManager> writerManager;
public:
    PkbWriter(std::shared_ptr<PkbWriterManager> writerManager);

    void addConstant(std::shared_ptr<Constant> c);
    void addVariable(std::shared_ptr<Variable> v);
    void addProcedure(std::shared_ptr<Procedure> p);

    void addPrintStatement(std::shared_ptr<Statement> s);
    void addReadStatement(std::shared_ptr<Statement> s);
    void addAssignStatement(std::shared_ptr<Statement> s, std::shared_ptr<Variable> lhs, std::shared_ptr<std::string> rhs);

    void addFollowsRelationship(std::shared_ptr<Statement> s1, std::shared_ptr<Statement> s2);
    void addUsesRelationship(std::shared_ptr<Statement> s, std::shared_ptr<Variable> v);
};