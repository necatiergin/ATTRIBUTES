[[deprecated]] int x = 0;
[[deprecated]] typedef int Int32;
using BYTE [[deprecated]] = unsigned char;

struct [[deprecated]] Data {
	int x, y, z;
};

enum Color {
	White,
	Gray,
	Blue,
	[[deprecated]] Brown,
	Black,
};

class Nec {
	int mx;
	[[deprecated]] int y;
};
