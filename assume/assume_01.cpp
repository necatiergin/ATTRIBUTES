//assume - C++23

void func(int x)
{
	[[assume(x > 0)]];  //assumption
	//...
}
