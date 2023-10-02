#pragma once

#include "SuchThatStrategy.h"
#include "QPS/Clauses/SuchThatClause.h"

/**
 * The Strategy class of UsesS in SuchThatClause
 */
class UsesSSuchThatStrategy : public SuchThatStrategy {
public:
    explicit UsesSSuchThatStrategy(std::shared_ptr<PkbReader> pkbReader);
    Result evaluateSynSyn(Ref &leftRef, Ref &rightRef) const override;

    Result evaluateSynIdent(Ref &leftRef, Ref &rightRef) const override;

    Result evaluateSynWild(Ref &leftRef, Ref &rightRef) const override;

    Result evaluateIntSyn(Ref &leftRef, Ref &rightRef) const override;

    Result evaluateIntIdent(Ref &leftRef, Ref &rightRef) const override;

    Result evaluateIntWild(Ref &leftRef, Ref &rightRef) const override;
};
