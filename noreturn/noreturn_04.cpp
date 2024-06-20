#include <iostream>
#include <stdexcept>

[[noreturn]] void foo()
{
	throw std::runtime_error{ "error" };
}

void baz();

void bar()
{
	foo();
	baz(); //dead code 
}
