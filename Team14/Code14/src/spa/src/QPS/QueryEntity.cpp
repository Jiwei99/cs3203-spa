#include "QueryEntity.h"

#include <string>

QueryEntity::QueryEntity(QueryEntityType type, const Synonym &synonym) : type(type), synonym(synonym) {}

bool QueryEntity::operator==(const QueryEntity& other) const {
    return (type == other.type) && (synonym == other.synonym);
}

std::string QueryEntity::getSynonym() {
    return synonym;
}

QueryEntityType QueryEntity::getType() {
    return type;
}