#include <cstdlib>
#include <stdexcept>

[[noreturn]] void foo()
{
	//...
	std::exit(EXIT_SUCCESS);
}

[[noreturn]] void bar()
{
	//...

	for (;;) {			
		// infinite loop
	}
}

[[noreturn]] void baz()
{
	//...

	throw std::runtime_error("baz error!");
}
