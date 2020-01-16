#ifndef expression_tree_parser_hpp
#define expression_tree_parser_hpp

#include <memory>

#include "types.hpp"

namespace stork {
	class node;
	using node_ptr=std::unique_ptr<node>;

	class push_back_stream;

	class compiler_context;

	node_ptr parse_expression_tree(compiler_context& context, push_back_stream& stream,
	                               type_handle type_id, bool lvalue, bool allow_comma);
}

#endif /* expression_tree_parser_hpp */
