#include <stdexcept>

[[noreturn]] void foo (int x)
{
	if (x == 0)
		throw std::exception{};

	//undefined behavior
}
