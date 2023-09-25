#include <iostream>
#include "module.hpp"
#include "standard_functions.hpp"

int main() {
	std::string path = __FILE__;
	for (int i = 0; i < 3; ++i)
		path = path.substr(0, path.find_last_of("/\\"));
	path += "/examples/test.stk";

	using namespace stork;

	stork_module m;

	add_standard_functions(m);

	m.add_external_function("greater", std::function<number(number, number)>([](number x, number y){
		return x > y;
	}));

	auto s_main = m.create_public_function_caller<void>("main");

	if (m.try_load(path.c_str(), &std::cerr)) {
		s_main();
	}

	return 0;
}