#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "Commons/Entities/Procedure.h"
#include "PKB/Managers/ManagerUtils.h"

/**
 * @class ProcToProcRelationshipManager is responsible for storing and retrieving the relationships
 * between procedure and procedure.
 * This class is a template class that is inherited by the Relationship Managers
 * @tparam S The type of the relationship store
 * @tparam R The type of the relationship
 */
template<typename S>
class ProcToProcRelationshipManager {
private:
    /**
     * @brief The relationship store
     */
    std::shared_ptr<S> relationshipStore;
    std::shared_ptr<S> starRelationshipStore;

public:
    /**
     * @brief Constructs a ProcToProcRelationshipManager object
     * @return A ProcToProcRelationshipManager object
     */
    ProcToProcRelationshipManager();

    /**
     * Stores a new relationship into PKB via the Manager
     * @param procedure1 The former procedure
     * @param procedure2 The latter procedure
     * @param isDirect A boolean value indicating if the relationship is direct
     */
    void storeRelationship(std::shared_ptr<Procedure> procedure1, std::shared_ptr<Procedure> procedure2, bool isDirect);

    /**
     * Returns an unordered_set of Procedure, Procedure pair where the first procedure is related to the second
     * procedure.
     * @param requireDirect A boolean value indicating if a direct relationship is required
     * @return An unordered_set of Procedure, Procedure pair stored in a vector
     */
    EntityPairSet getRelationshipPair(bool requireDirect) const;

    /**
     * Returns an unordered_set of procedure which is related to the given procedure. The procedure given is the latter
     * procedure
     * @param latterProcedure The procedure that is related to the procedure to be retrieved
     * @param requireDirect A boolean value indicating if a direct relationship is required
     * @return An unordered_set of procedures
     */
    EntitySet getRelationshipFormer(Procedure &latterProcedure, bool requireDirect) const;

    /**
     * Returns an unordered_set of procedures which is related to any procedures. The procedures retrieved are the
     * former procedures
     * @return An unordered_set of procedures
     */
    EntitySet getRelationshipFormer() const;

    /**
     * Returns an unordered_set of procedures which is related to the given procedure. The procedure given is the former
     * procedure
     * @param formerProcedure The procedure that is related to the procedures to be retrieved
     * @param requireDirect A boolean value indicating if a direct relationship is required
     * @return An unordered_set of procedures
     */
    EntitySet getRelationshipLatter(Procedure &formerProcedure, bool requireDirect) const;

    /**
     * Returns an unordered_set of procedures which is related to any procedure. The procedures retrieved are the latter
     * procedure
     * @return An unordered_set of procedures
     */
    EntitySet getRelationshipLatter() const;

    /**
     * Returns true if procedure1 is related to procedure2, false otherwise
     * @param procedure1 The former procedure
     * @param procedure2 The latter procedure
     * @param requireDirect A boolean value indicating if a direct relationship is required
     * @return True if procedure1 is related to procedure2, false otherwise
     */
    bool isRelationship(Procedure &procedure1, Procedure &procedure2, bool requireDirect) const;

    /**
     * Returns true if there are any relationships stored, false otherwise
     * @return True if there are any relationships stored, false otherwise
     */
    bool hasRelationship() const;

    /**
     * Returns true if there exists a relationship where the given procedure is the former procedure, false otherwise
     * @param procdure The procedure to be checked
     * @return True if there exists a relationship where the given procedure is the former procedure, false otherwise
     */
    bool isFormer(Procedure &procedure) const;

    /**
     * Returns true if there exists a relationship where the given procedure is the latter procedure, false otherwise
     * @param procedure The procedure to be checked
     * @return True if there exists a relationship where the given procedure is the latter procedure, false otherwise
     */
    bool isLatter(Procedure &procedure) const;

    /**
     * Populates the starRelationshipStore based on transitivity calculation of the relationshipStore.
     */
    void calculateTransitiveRelationship();

    /**
     * Returns a set of procedures which is related to the given procedure i.e. the given procedure is the latter
     * procedure.
     * @param latterProcedure The procedure that is the latter procedure.
     * @return A set of procedures that are the former procedures
     */
    std::shared_ptr<EntityStore<Procedure>> getRelationshipFormerStarAsProcedure(Procedure &latterProcedure) const;
};

#include "ProcToProcRelationshipManager.hpp"