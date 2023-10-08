#pragma once

#include "SuchThatStrategy.h"

/**
 * The Strategy class of Next* in SuchThatClause
 */
class NextStarSuchThatStrategy : public SuchThatStrategy {
public:
    /**
     * @brief Explicit constructor of NextStarSuchThatStrategy
     * @param pkbReader The shared pointer to the PKB reader
     */
    explicit NextStarSuchThatStrategy(std::shared_ptr<PkbReader> pkbReader);

    /**
     * @brief Evaluates SuchThatClause that follows the syntax Next*(s,s)
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The result of the SuchThatClause evaluation as a Result object
     */
    Result evaluateSynSyn(Ref &leftRef, Ref &rightRef) const override;

    /**
     * @brief Evaluates SuchThatClause that follows the syntax Next*(s, )
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The result of the SuchThatClause evaluation as a Result object
     */
    Result evaluateSynAny(Ref &leftRef, Ref &rightRef) const override;

    /**
     * @brief Evaluates SuchThatClause that follows the syntax Next*( , s)
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The result of the SuchThatClause evaluation as a Result object
     */
    Result evaluateAnySyn(Ref &leftRef, Ref &rightRef) const override;

    /**
     * @brief Evaluates SuchThatClause that results in boolean
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The result of the SuchThatClause evaluation as a Result object
     */
    Result evaluateBoolean(Ref &leftRef, Ref &rightRef) const override;
};
