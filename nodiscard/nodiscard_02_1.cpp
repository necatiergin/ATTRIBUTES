class [[nodiscard]] Myclass {
public:
	Myclass(int);
};


int main(void)
{
	int i{ 567 };

	static_cast<Myclass>(i); //warning
}
