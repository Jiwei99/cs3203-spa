#include <fstream>

#include "PKB/Pkb.h"
#include "QPS/QPS.h"
#include "SP/SP.h"
#include "TestWrapper.h"

// implementation code of WrapperFactory - do NOT modify the next 5 lines
AbstractWrapper *WrapperFactory::wrapper = 0;
AbstractWrapper *WrapperFactory::createWrapper() {
    if (wrapper == 0) wrapper = new TestWrapper;
    return wrapper;
}
// Do not modify the following line
volatile bool AbstractWrapper::GlobalStop = false;

// a default constructor
TestWrapper::TestWrapper() {
    // create any objects here as instance variables of this class
    // as well as any initialization required for your spa program
    auto pkb = Pkb();
    this->pkbWriter = pkb.createPkbWriter();
    this->pkbReader = pkb.createPkbReader();
}

// method for parsing the SIMPLE source
void TestWrapper::parse(std::string filename) {
    // call your parser to do the parsing
    // ...rest of your code...

    std::ifstream inputFile(filename);

    // read the content of the file into a string
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    // Close the file
    inputFile.close();

    SP sP = SP(this->pkbWriter);
    sP.startSPProcessing(fileContent);
}

// method to evaluating a query
void TestWrapper::evaluate(std::string query, std::list<std::string> &results) {
    // call your evaluator to evaluate the query here
    // ...code to evaluate query...
    // store the answers to the query in the results list (it is initially empty)
    // each result must be a string.
    QPS qps = QPS(this->pkbReader);
    qps.evaluate(query, results);
    this->pkbWriter->clearCache();
}
