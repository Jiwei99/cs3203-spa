#pragma once

#include "Strategy.h"

/**
 * @class The SuchThatStrategy base class to evaluate SuchThatClause
 */
class SuchThatStrategy : public Strategy {
protected:
    /**
     * Shared pointer to the PKB reader which retrieves the required information for query evaluation
     */
    std::shared_ptr<PkbReader> pkbReader;

public:
    /**
     * @brief Explicit constructor of SuchThatStrategy
     * @param pkbReader The shared pointer to the PKB reader
     */
    explicit SuchThatStrategy(std::shared_ptr<PkbReader> pkbReader);

    /**
     * @brief Evaluates SuchThatClause that has synonyms in both parameters
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The shared pointer to result of the SuchThatClause evaluation
     */
    virtual std::shared_ptr<Result> evaluateSynSyn(Ref &leftRef, Ref &rightRef) const = 0;

    /**
     * @brief Evaluates SuchThatClause that has a synonym as the first parameter
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The shared pointer to result of the SuchThatClause evaluation
     */
    virtual std::shared_ptr<Result> evaluateSynAny(Ref &leftRef, Ref &rightRef) const = 0;

    /**
     * @brief Evaluates SuchThatClause that has a synonym as the second parameter
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The shared pointer to result of the SuchThatClause evaluation
     */
    virtual std::shared_ptr<Result> evaluateAnySyn(Ref &leftRef, Ref &rightRef) const = 0;

    /**
     * @brief Evaluates SuchThatClause that evaluates to a boolean value
     * @param leftRef The first parameter of the SuchThatClause to evaluate
     * @param rightRef The second parameter of the SuchThatClause to evaluate
     * @return The shared pointer to result of the SuchThatClause evaluation
     */
    virtual std::shared_ptr<Result> evaluateBoolean(Ref &leftRef, Ref &rightRef) const = 0;

    /**
     * @brief Evaluates SuchThatClause and returns a Result
     * @param clause The SuchThatClause to evaluate
     * @return The shared pointer to result of the SuchThatClause evaluation
     */
    std::shared_ptr<Result> evaluateClause(std::shared_ptr<Clause> clause) const override;
};
