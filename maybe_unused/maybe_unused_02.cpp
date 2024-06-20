#include <cassert>

[[maybe_unused]] static bool isvalid(int x);

void func(int a, [[maybe_unused]] int b)
{
	assert(isvalid(a * b));
	//a is used here
}
