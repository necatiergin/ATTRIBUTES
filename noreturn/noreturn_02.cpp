#include <iostream>

[[noreturn]] void foo();

int main()
{
	foo();
	std::cout << "necati"; //compiler may generate warning message
}
