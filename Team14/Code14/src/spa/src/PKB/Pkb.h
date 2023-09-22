#pragma once

#include <memory>

#include "PKB/Managers/AssignmentManager.h"
#include "PKB/AssignmentPatternStore/AssignmentPatternStore.h"
#include "PKB/Managers/EntitiesManager.h"
#include "PKB/RelationshipStores/FollowsRelationshipStore.h"
#include "PKB/RelationshipStores/UsesRelationshipStore.h"
#include "PKB/Managers/UsesRelationshipManager.h"
#include "PKB/Managers/FollowsRelationshipManager.h"
#include "PKB/Managers/ModifiesRelationshipManager.h"
#include "PKB/Managers/ParentRelationshipManager.h"
#include "PKB/Managers/PkbReaderManager.h"
#include "PKB/Managers/PkbWriterManager.h"
#include "PKB/PkbReader.h"
#include "PKB/PkbWriter.h"

class Pkb {
private:
    std::shared_ptr<AssignmentManager> assignmentManager;

    std::shared_ptr<EntitiesManager> entitiesManager;

    std::shared_ptr<UsesRelationshipManager> usesRelationshipManager;
    std::shared_ptr<FollowsRelationshipManager> followsRelationshipManager;
    std::shared_ptr<ModifiesRelationshipManager> modifiesRelationshipManager;
    std::shared_ptr<ParentRelationshipManager> parentRelationshipManager;

    std::shared_ptr<PkbReaderManager> pkbReaderManager;
    std::shared_ptr<PkbWriterManager> pkbWriterManager;

public:
    Pkb();

    std::shared_ptr<PkbReader> createPkbReader();

    std::shared_ptr<PkbWriter> createPkbWriter();
};