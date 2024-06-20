//[[fallthrough]] C++17

enum Color { White, Blue, Red, Black };

Color get_color();

void f_white();
void f_blue();
void f_red();
void f_black();

int main()
{
	switch (get_color()) {
	case White: f_white(); break;
	case Blue: f_white(); [[fallthrough]];
	case Red: f_blue(); break;
	case Black: f_black(); break;
	}
	//...
}
