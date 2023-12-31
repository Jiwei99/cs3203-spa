#include "WithClause.h"

WithClause::WithClause() : Clause() { this->setType(ClauseType::With); }

void WithClause::setSecondParam(Ref &ref) { secondParam = ref; }

Ref &WithClause::getSecondParam() { return secondParam; }

std::vector<Synonym> WithClause::getSynonyms() const {
    std::vector<Synonym> synonyms;
    if (firstParam.getRootType() == RootType::AttrRef) { synonyms.push_back(firstParam.getRep()); }
    // only add RHS synonym if it is different from LHS
    if (secondParam.getRootType() == RootType::AttrRef && !(firstParam == secondParam)) {
        synonyms.push_back(secondParam.getRep());
    }
    return synonyms;
}

bool WithClause::isEqual(const Clause &other) const {
    const auto &otherWith = dynamic_cast<const WithClause &>(other);
    return (secondParam == otherWith.secondParam);
};