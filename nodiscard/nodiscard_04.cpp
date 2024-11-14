class Myclass {
public:
	[[nodiscard]] Myclass(int);
};

int main()
{
	int ival{ 10 };

	static_cast<Myclass>(ival); //warning
	(Myclass) ival; //warning
}
