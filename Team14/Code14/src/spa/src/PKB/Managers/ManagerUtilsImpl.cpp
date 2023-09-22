#include "PKB/Managers/ManagerUtils.cpp"
#include "PKB/Relationships/FollowsRelationship.h"
#include "PKB/RelationshipStores/FollowsRelationshipStore.h"
#include "PKB/Relationships/UsesRelationship.h"
#include "PKB/RelationshipStores/UsesRelationshipStore.h"
#include "PKB/AssignmentPatternStore/Assignment.h"
#include "PKB/AssignmentPatternStore/AssignmentPatternStore.h"
#include "PKB/Relationships/ModifiesRelationship.h"
#include "PKB/RelationshipStores/ModifiesRelationshipStore.h"
#include "PKB/Relationships/ParentRelationship.h"
#include "PKB/RelationshipStores/ParentRelationshipStore.h"
#include "Commons/Entities/Constant.h"
#include "PKB/EntityStores/ConstantStore.h"
#include "Commons/Entities/Procedure.h"
#include "PKB/EntityStores/ProcedureStore.h"
#include "Commons/Entities/Statement.h"
#include "PKB/EntityStores/StatementStore.h"
#include "Commons/Entities/Variable.h"
#include "PKB/EntityStores/VariableStore.h"

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<FollowsRelationshipStore, FollowsRelationship>(std::shared_ptr<FollowsRelationshipStore> store, std::function<bool(FollowsRelationship&)> matcher, std::function<Entity(FollowsRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromStore<FollowsRelationshipStore, FollowsRelationship>(std::shared_ptr<FollowsRelationshipStore> store, std::function<bool(FollowsRelationship&)> matcher, std::function<std::vector<Entity>(FollowsRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<UsesRelationshipStore, UsesRelationship>(std::shared_ptr<UsesRelationshipStore> store, std::function<bool(UsesRelationship&)> matcher, std::function<Entity(UsesRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromStore<UsesRelationshipStore, UsesRelationship>(std::shared_ptr<UsesRelationshipStore> store, std::function<bool(UsesRelationship&)> matcher, std::function<std::vector<Entity>(UsesRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<ModifiesRelationshipStore, ModifiesRelationship>(std::shared_ptr<ModifiesRelationshipStore> store, std::function<bool(ModifiesRelationship&)> matcher, std::function<Entity(ModifiesRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromStore<ModifiesRelationshipStore, ModifiesRelationship>(std::shared_ptr<ModifiesRelationshipStore> store, std::function<bool(ModifiesRelationship&)> matcher, std::function<std::vector<Entity>(ModifiesRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<AssignmentPatternStore, Assignment>(std::shared_ptr<AssignmentPatternStore> store, std::function<bool(Assignment&)> matcher, std::function<Entity(Assignment&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromStore<AssignmentPatternStore, Assignment>(std::shared_ptr<AssignmentPatternStore> store, std::function<bool(Assignment&)> matcher, std::function<std::vector<Entity>(Assignment&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<ParentRelationshipStore, ParentRelationship>(std::shared_ptr<ParentRelationshipStore> store, std::function<bool(ParentRelationship&)> matcher, std::function<Entity(ParentRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromStore<ParentRelationshipStore, ParentRelationship>(std::shared_ptr<ParentRelationshipStore> store, std::function<bool(ParentRelationship&)> matcher, std::function<std::vector<Entity>(ParentRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<ConstantStore, Constant>(std::shared_ptr<ConstantStore> store, std::function<bool(Constant&)> matcher, std::function<Entity(Constant&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<ProcedureStore, Procedure>(std::shared_ptr<ProcedureStore> store, std::function<bool(Procedure&)> matcher, std::function<Entity(Procedure&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<StatementStore, Statement>(std::shared_ptr<StatementStore> store, std::function<bool(Statement&)> matcher, std::function<Entity(Statement&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<VariableStore, Variable>(std::shared_ptr<VariableStore> store, std::function<bool(Variable&)> matcher, std::function<Entity(Variable&)> getter);

