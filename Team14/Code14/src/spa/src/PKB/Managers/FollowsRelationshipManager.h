#pragma once

#include <memory>
#include <vector>
#include <algorithm>

#include "PKB/RelationshipStores/FollowsRelationshipStore.h"
#include "Commons/Entities/Statement.h"
#include "PKB/Managers/StmtToStmtRelationshipManager.h"

/**
 * @class FollowsRelationshipManager is responsible for storing the Follows relationship
 * @brief Manages the Follows relationship
 * @note: A Follows relationship is a relationship between two statements where the first statement is executed before the second statement
 */
class FollowsRelationshipManager : public StmtToStmtRelationshipManager<FollowsRelationshipStore> {
public:
    /**
     * @brief Constructs a FollowsRelationshipManager object
     * @return A FollowsRelationshipManager object
     */
    FollowsRelationshipManager();
};
