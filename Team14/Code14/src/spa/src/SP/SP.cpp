#include "SP.h"
#include "SPTokenizer.h"
#include "SPParser.h"
#include "SyntacticValidator.h"
#include "SP/AST/Visitors/EntityExtractorVisitor.h"
#include "SP/AST/Visitors/FollowsExtractorVisitor.h"
#include "SP/AST/Visitors/UsesExtractorVisitor.h"
#include "SP/AST/Traverser/Traverser.h"

SP::SP(std::shared_ptr<PkbWriter> pkbWriter) : pkbWriter(pkbWriter) {}

void SP::startSPProcessing(std::string& input) {
	//Tokenize the string input
	SPTokenizer tokenizer = SPTokenizer(input);
	std::vector<SPToken> tokens = tokenizer.tokenize();

	//Syntactic Validator takes in tokens
	SyntacticValidator syntacticValidator = SyntacticValidator(tokens);
	syntacticValidator.validate();

	//Parse the tokens
	SPParser parser = SPParser();
	std::shared_ptr<ProgramNode> root = parser.parse(tokens);

	//Instantiate all visitors to be used
	std::shared_ptr<EntityExtractorVisitor> entityExtractor = std::make_shared<EntityExtractorVisitor>(pkbWriter);
	std::shared_ptr<FollowsExtractorVisitor> followsExtractor = std::make_shared<FollowsExtractorVisitor>(pkbWriter);
	std::shared_ptr<UsesExtractorVisitor> usesExtractor = std::make_shared<UsesExtractorVisitor>(pkbWriter);

	std::vector<std::shared_ptr<DesignExtractorVisitor>> visitors = { entityExtractor, followsExtractor, usesExtractor };

	//Traverse the AST from root node
	Traverser traverser = Traverser(visitors);
	traverser.traverse(root);
}