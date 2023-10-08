#pragma once

#include <string>
#include <utility>

#include "QPS/Query.h"
#include "QPS/QueryEntity.h"
#include "QPS/QPSTypes.h"


class PqlSemanticValidator {
public:
    explicit PqlSemanticValidator();

    /**
     * @brief Validates the selected entity, throws a Semantic exception if synonym is undeclared
     * @param query the query object
     * @param syn the synonym selected in the query
     */
    void validateSelectSemantics(const Query& query, const Synonym& syn);

    /**
     * @brief Validates SuchThatClause semantically, throws a SemanticException if semantically invalid
     * @param query the Query object
     * @param clause the shared pointer of SuchThatClause to validate
     */
    void validateClauseSemantics(const Query& query, std::shared_ptr<SuchThatClause> clause);

    /**
     * @brief Validates PatternClause semantically, throws a SemanticException if semantically invalid
     * @param query the Query object
     * @param clause the shared pointer of PatternClause to validate
     */
    void validateClauseSemantics(const Query& query, std::shared_ptr<PatternClause> clause);

};
