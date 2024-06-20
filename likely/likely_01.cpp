enum class Color { white, blue, red, brown, black, };

void f_white();
void f_blue();
void f_red();
void f_brown();
void f_black();

void func(Color c)
{
	switch (c) {
	case Color::white: f_white(); break;
	case Color::blue: f_blue(); break;
	[[likely]] case Color::red: f_red(); break;
	case Color::brown: f_brown(); break;
	case Color::black: f_black(); break;
	}
}
