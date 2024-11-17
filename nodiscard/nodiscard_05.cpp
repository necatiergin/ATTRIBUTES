class List {
public:
	//...
	[[nodiscard("did you intend clear?")]]
	bool empty()const;
	//...
	bool clear();
};

int main(void)
{
	List ls;

	ls.empty(); //warning: ... did you intend clear?
}
