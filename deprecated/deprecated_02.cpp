[[deprecated]] int x = 0;
[[deprecated]] typedef int Int32;
using BYTE [[deprecated]] = unsigned char;

struct [[deprecated]] Data {
	int x, y, z;
};

class Nec {
	int mx;
	[[deprecated]] int y;
};

enum Color {
	White,
	Gray,
	Blue,
	Brown [[deprecated]],
	Black,
};
