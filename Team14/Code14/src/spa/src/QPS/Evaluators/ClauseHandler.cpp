#include <stdexcept>

#include "ClauseHandler.h"

ClauseHandler::ClauseHandler(std::shared_ptr<PkbReader> pkbReader) : pkbReader(pkbReader) {}

void ClauseHandler::setStrategy(std::shared_ptr<Strategy> strategy) {
    this->strategy = std::move(strategy);
}

void ClauseHandler::executeClause(std::shared_ptr<Clause> clause, Result& result) const {
    if (strategy) {
        result = strategy->evaluateClause(clause, pkbReader);
    } else {
        throw std::runtime_error("No strategy set for clause handler");
    }
}