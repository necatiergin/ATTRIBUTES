enum [[nodiscard]] Color {White, Red, Blue, Black};

Color get_color(void);

int main()
{
	get_color(); //warning
}
