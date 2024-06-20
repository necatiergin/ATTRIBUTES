enum class City {
	Berlin = 0,
	NewYork = 1,
	Mumbai = 2,
	Bombay [[deprecated]] = Mumbai,
};


City mycity{ City::Bombay }; //compiler warning expected
