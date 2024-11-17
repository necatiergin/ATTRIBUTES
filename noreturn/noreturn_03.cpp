#include <stdexcept>
#include <iostream>

[[noreturn]]
void foo()
{
	throw std::runtime_error{ "error..." };
}

void func()
{
	try {
		foo();
		//unreachable code
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught : " << ex.what() << '\n';
		//reachable code
	}
}
