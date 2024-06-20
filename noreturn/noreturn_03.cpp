#include <stdexcept>
#include <iostream>

[[noreturn]]
void foo()
{
	throw std::runtime_error{ "hata" };
}

void func()
{
	try {
		foo();
		//unreachable code
	}
	catch (const std::exception& ex) {
		std::cout << "hata yakalandi : " << ex.what() << '\n';
		//reachable code
	}
}
