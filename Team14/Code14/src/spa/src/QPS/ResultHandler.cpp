#include "ResultHandler.h"

#include <unordered_set>

ResultHandler::ResultHandler() {};

Result ResultHandler::getCombined(Result& r1, Result& r2) {
    if ((r1.getType() == ResultType::Invalid) ||
            (r1.getType() == ResultType::Boolean && r1.getBoolResult()) ||
            (r2.getType() == ResultType::Boolean && !r2.getBoolResult())) {
        return r2;
    }
    if (r2.getType() == ResultType::Invalid ||
            (r1.getType() == ResultType::Boolean && !r1.getBoolResult()) ||
            (r2.getType() == ResultType::Boolean && r2.getBoolResult())) {
        return r1;
    }
//    if (r1.getType() == ResultType::Boolean && r1.getBoolResult()) {
//        return r2;
//    }
//    if (r1.getType() == ResultType::Boolean && !r1.getBoolResult()) {
//        return r1;
//    }
//    if (r2.getType() == ResultType::Boolean && r2.getBoolResult()) {
//        return r1;
//    }
//    if (r2.getType() == ResultType::Boolean && !r2.getBoolResult()) {
//        return r2;
//    }

    return join(r1, r2);
}

Result ResultHandler::join(Result& r1, Result& r2) {
    Result final;
    ResultTuples finalTuples;

    // find common columns
    std::unordered_map<int, int> common = getCommonColumns(r1, r2);
    SynonymMap synIndices = buildSynIndices(r1, r2);
    std::vector<Synonym> header = getHeader(synIndices);
    final.setSynIndices(synIndices);

    auto tuples1 = r1.getTuples();
    auto tuples2 = r2.getTuples();

    for (const auto& row1 : tuples1){
        for (const auto& row2 : tuples2) {
            if (isMatch(row1, row2, common)){
                //build row and add to final's tuples
                std::vector<Entity> newRow;
                auto map1 = r1.getSynIndices();
                auto map2 = r2.getSynIndices();
                for (const auto& colName : header) {
                    if (map1.count(colName)){ //if found in r1, add to vector
                        int index = map1[colName];
                        newRow.push_back(row1[index]);
                        continue;
                    }
                    //add from r2
                    int index = map2[colName];
                    newRow.push_back(row2[index]);
                }
                finalTuples.push_back(newRow);
            }
        }
    }
    final.setTuples(finalTuples);
    ResultType type = ResultType::Tuples;
    final.setType(type);
    return final;
}

// returns mapping of {index in r1: index in r2} for common cols
std::unordered_map<int, int> ResultHandler::getCommonColumns(Result& r1, Result& r2) {
    std::unordered_map<int, int> commonIndices;
    auto map1 = r1.getSynIndices();
    auto map2 = r2.getSynIndices();

    for (auto& it: map1) {
        Synonym key = it.first;
        if (map2.count(key)) {
            commonIndices[map1[key]] = map2[key];
        }

    }
    return commonIndices;
}

// get combined synIndices
SynonymMap ResultHandler::buildSynIndices(Result& r1, Result& r2) {
    SynonymMap combined = r1.getSynIndices();
    SynonymMap other = r2.getSynIndices();
    int mapSize = combined.size();

    for (auto& it: other) {
        Synonym key = it.first;
        if (combined.count(key) == 0) {
            combined[it.first] = mapSize;
            mapSize += 1;
        }
    }
    return combined;
}

std::vector<Synonym> ResultHandler::getHeader(SynonymMap map) {
    std::vector<Synonym> header(map.size());
    for (auto& it: map) {
        header[it.second] = it.first;
    }
    return header;
}


bool ResultHandler::isMatch(const std::vector<Entity>& row1,
                           const std::vector<Entity>& row2,
                           const std::unordered_map<int, int>& commons) {
    for (auto& it: commons) {
        if (row1[it.first] == row2[it.second]){
            continue;
        }
        return false;
    }
    return true;
}