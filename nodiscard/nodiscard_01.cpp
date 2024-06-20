[[nodiscard]]
int sum_square(int a, int b)
{
	return a * a + b * b;
}


void func(int x, int y)
{
	sum_square(x, y); //compiler warning expected
	//...
}
