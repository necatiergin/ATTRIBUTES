// nodiscard attribute since C++17

class [[nodiscard]] Nec {
	//...
};

Nec foo();
Nec& func();

int main()
{
	foo();  // compiler warning expected
	func(); // no compiler warning expected
}
