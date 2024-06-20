//where to place it

#include <stdexcept>

[[noreturn]] void foo ()
{
	throw std::runtime_error{"error"};
}

void bar [[noreturn]] ()
{
	throw std::runtime_error{ "error" };
}
