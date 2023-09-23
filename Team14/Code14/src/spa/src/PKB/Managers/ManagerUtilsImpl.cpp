#include "PKB/Managers/ManagerUtils.cpp"
#include "PKB/Relationships/FollowsRelationship.h"
#include "PKB/Relationships/UsesRelationship.h"
#include "PKB/AssignmentPatternStore/Assignment.h"
#include "PKB/AssignmentPatternStore/AssignmentPatternStore.h"
#include "PKB/Relationships/ModifiesRelationship.h"
#include "PKB/Relationships/ParentRelationship.h"

template std::vector<Entity> ManagerUtils::getEntitiesFromRelationshipStore<FollowsRelationship>(std::shared_ptr<RelationshipStore<FollowsRelationship>> store, std::function<bool(FollowsRelationship&)> matcher, std::function<Entity(FollowsRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromRelationshipStore<FollowsRelationship>(std::shared_ptr<RelationshipStore<FollowsRelationship>> store, std::function<bool(FollowsRelationship&)> matcher, std::function<std::vector<Entity>(FollowsRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromRelationshipStore<UsesRelationship>(std::shared_ptr<RelationshipStore<UsesRelationship>> store, std::function<bool(UsesRelationship&)> matcher, std::function<Entity(UsesRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromRelationshipStore<UsesRelationship>(std::shared_ptr<RelationshipStore<UsesRelationship>> store, std::function<bool(UsesRelationship&)> matcher, std::function<std::vector<Entity>(UsesRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromRelationshipStore<ModifiesRelationship>(std::shared_ptr<RelationshipStore<ModifiesRelationship>> store, std::function<bool(ModifiesRelationship&)> matcher, std::function<Entity(ModifiesRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromRelationshipStore<ModifiesRelationship>(std::shared_ptr<RelationshipStore<ModifiesRelationship>> store, std::function<bool(ModifiesRelationship&)> matcher, std::function<std::vector<Entity>(ModifiesRelationship&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromStore<AssignmentPatternStore, Assignment>(std::shared_ptr<AssignmentPatternStore> store, std::function<bool(Assignment&)> matcher, std::function<Entity(Assignment&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromStore<AssignmentPatternStore, Assignment>(std::shared_ptr<AssignmentPatternStore> store, std::function<bool(Assignment&)> matcher, std::function<std::vector<Entity>(Assignment&)> getter);

template std::vector<Entity> ManagerUtils::getEntitiesFromRelationshipStore<ParentRelationship>(std::shared_ptr<RelationshipStore<ParentRelationship>> store, std::function<bool(ParentRelationship&)> matcher, std::function<Entity(ParentRelationship&)> getter);

template std::vector<std::vector<Entity>> ManagerUtils::getEntityPairsFromRelationshipStore<ParentRelationship>(std::shared_ptr<RelationshipStore<ParentRelationship>> store, std::function<bool(ParentRelationship&)> matcher, std::function<std::vector<Entity>(ParentRelationship&)> getter);
