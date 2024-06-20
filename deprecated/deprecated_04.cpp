//[[deprecated]] attribute extended in C++17

enum Color {
	gray = 0,
	grey [[deprecated]] = gray
};

Color c = grey; //compiler diagnostic

namespace [[deprecated]] old_version {
	void legacy_func();
}


int main()
{
	old_version::legacy_func(); //compiler diagnostic
}
