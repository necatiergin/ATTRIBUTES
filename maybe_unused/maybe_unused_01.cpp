//compiler may generate warning message if func is not called in the translation unit
static void func()
{
	//...
}

[[maybe_unused]] static void foo()
{

} // no compiler warning expected if foo is not called in the translation unit


int main()
{
	int x = 42; //compiler may generate warrning message if x is not used
	[[maybe_unused]] int y = 42; //no compiler warning expected if y is not used
}
