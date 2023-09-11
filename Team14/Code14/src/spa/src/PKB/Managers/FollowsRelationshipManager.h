#pragma once

#include <memory>

#include "PKB/RelationshipStorage/FollowsRelationshipStore.h"
#include "Commons/Entities/Statement.h"

class FollowsRelationshipManager {
private:
    std::shared_ptr<FollowsRelationshipStore> followsRelationshipStore;
public:
    FollowsRelationshipManager(std::shared_ptr<FollowsRelationshipStore> followsRelationshipStore);

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Statement>>>>> getAllFollowsStatementPair() const;

    std::shared_ptr<Statement> getFollowsByStatement(std::shared_ptr<Statement> statement) const; // Returns statement followed by (ahead) given statement

    std::shared_ptr<Statement> getFollowingStatement(std::shared_ptr<Statement> statement) const; // Returns statement following (behind) given statement

    bool getIsFollows(std::shared_ptr<Statement> statement1, std::shared_ptr<Statement> statement2) const; // Returns true if statement1 follows statement2


};
