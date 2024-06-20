//assume - c++23

void func(int x)
{
	[[assume(x > 0)]];
	//...
}
