#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "Entity.h"
#include "SuchThatClause.h"

class Query {
private:
    std::unordered_map<std::string, std::shared_ptr<Entity>> declarations;
    std::vector<std::shared_ptr<Entity>> selects;
    std::vector<SuchThatClause> such_that_clauses;

public:
    Query();
    void addDeclaration(const std::shared_ptr<Entity>& entity);
    void addSelect(const std::shared_ptr<Entity>& entity);

    void addSuchThatClause(SuchThatClause& clause);
    // void addPatternClause();
    bool hasDeclarations();
    std::shared_ptr<Entity> getEntity(const std::string& syn);
    std::unordered_map<std::string, std::shared_ptr<Entity>> getDeclarations();
    std::vector<std::shared_ptr<Entity>> getSelect();
    std::vector<SuchThatClause> getSuchThat();
};
