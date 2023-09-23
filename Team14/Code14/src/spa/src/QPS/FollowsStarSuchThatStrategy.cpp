#include "FollowsStarSuchThatStrategy.h"
#include "Commons/Entities/Statement.h"
#include "Commons/Entities/StatementType.h"

Result FollowsStarSuchThatStrategy::evaluateClause(std::shared_ptr<Clause> clause, std::shared_ptr<PkbReader> pkbReader) const {
    std::shared_ptr<SuchThatClause> suchThat = std::dynamic_pointer_cast<SuchThatClause>(clause);
    Ref leftRef = suchThat->getFirstParam();
    RootType leftRootType = leftRef.getRootType();
    QueryEntityType leftEntityType = leftRef.getEntityType();
    Ref rightRef = suchThat->getSecondParam();
    RootType rightRootType = rightRef.getRootType();
    QueryEntityType rightEntityType = rightRef.getEntityType();
    Result res;

    if (leftRootType == RootType::Synonym && rightRootType == RootType::Synonym) { // Follows*(s1,s2)
        std::string leftSyn = leftRef.getRep();
        std::string rightSyn = rightRef.getRep();
        res.setTuples(pkbReader->getFollowsStarPair(stmtMap.at(leftEntityType), stmtMap.at(rightEntityType)));

        std::unordered_map<std::string, int> indices {{leftSyn, 0}, {rightSyn, 1}};
        res.setSynIndices(indices);

    } else if (leftRootType == RootType::Synonym && rightRootType == RootType::Integer) { // Follows*(s,1)
        std::string syn = leftRef.getRep();
        Statement s = Statement(stoi(rightRef.getRep()), StatementType::Stmt);
        res.setTuples(pkbReader->getFollowsStarTypeStmt(stmtMap.at(leftEntityType), s));

        std::unordered_map<std::string, int> indices{{syn, 0}};
        res.setSynIndices(indices);

    } else if (leftRootType == RootType::Synonym && rightRootType == RootType::Wildcard) { // Follows*(s,_)
        std::string syn = leftRef.getRep();
        res.setTuples(pkbReader->getFollowsStarTypeWildcard(stmtMap.at(leftEntityType)));

        std::unordered_map<std::string, int> indices{{syn, 0}};
        res.setSynIndices(indices);

    } else if (leftRootType == RootType::Integer && rightRootType == RootType::Synonym) { // Follows*(1,s)
        std::string syn = rightRef.getRep();
        Statement s = Statement(stoi(leftRef.getRep()), StatementType::Stmt);
        res.setTuples(pkbReader->getFollowsStarStmtType(s, stmtMap.at(rightEntityType)));

        std::unordered_map<std::string, int> indices{{syn, 0}};
        res.setSynIndices(indices);

    } else if (leftRootType == RootType::Wildcard && rightRootType == RootType::Synonym) { // Follows*(_,s)
        std::string syn = rightRef.getRep();
        auto data = pkbReader->getFollowsStarWildcardType(stmtMap.at(rightEntityType));

        std::unordered_map<std::string, int> indices{{syn, 0}};
        res.setSynIndices(indices);

    } else if (leftRootType == RootType::Integer && rightRootType == RootType::Wildcard) { // Follows*(1,_)
        Statement s = Statement(stoi(leftRef.getRep()), StatementType::Stmt);
        res.setBoolResult(pkbReader->hasLatterStarStmt(s));

    } else if (leftRootType == RootType::Wildcard && rightRootType == RootType::Integer) { // Follows*(_,1)
        Statement s = Statement(stoi(rightRef.getRep()), StatementType::Stmt);
        res.setBoolResult(pkbReader->hasFormerStarStmt(s));

    } else if (leftRootType == RootType::Integer && rightRootType == RootType::Integer) { // Follows*(1,2)
        Statement s1 = Statement(stoi(leftRef.getRep()), StatementType::Stmt);
        Statement s2 = Statement(stoi(rightRef.getRep()), StatementType::Stmt);
        res.setBoolResult(pkbReader->isFollowsStar(s1, s2));

    } else if (leftRootType == RootType::Wildcard && rightRootType == RootType::Wildcard) { // Follows*(_,_)
        res.setBoolResult(pkbReader->hasFollowsStar());

    }

    return res;
}