#pragma once

#include <memory>

#include "Clause.h"

/**
 * @brief WithClause class that extends from Clause
 */
class WithClause : public Clause {
private:
    /**
     * @brief The second parameter of the WithClause
     */
    Ref secondParam;

    /**
     * @brief Returns true if the WithClause object is equal to the other WithClause object, false otherwise
     * @param other The other WithClause object to compare against
     * @return True if the WithClause object is equal to the other WithClause object
     */
    bool isEqual(const Clause &other) const override;

public:
    /**
     * @brief The constructor of WithClause
     */
    WithClause();

    /**
     * @brief The setter of the second parameter of the WithClause
     * @param ref the Ref reference of the second parameter
     */
    void setSecondParam(Ref &ref);

    /**
     * @brief The getter of the second parameter of the WithClause
     * @return The Ref reference of the second parameter
     */
    Ref &getSecondParam();

    /**
     * @brief returns the list of synonyms present in the with clause, used for
     * defining the corresponding Result table header of the clause
     * @return vector of Synonyms
     */
    std::vector<Synonym> getSynonyms() const override;
};
