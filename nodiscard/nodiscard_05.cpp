class List {
public:
	//...
	[[nodiscard("did you intend clear?")]] //string literal usage since C++20
	bool empty()const;
	//...
	bool clear();
};

int main(void)
{
	List ls;

	ls.empty(); //warning: ... did you intend clear?
}
