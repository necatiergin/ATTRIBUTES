#include <iostream>

void commentPlace(int place) 
{
	switch (place) {
		case 1: std::cout << "very "; [[fallthrough]]; 
		case 2: std::cout << "well\n"; break;
		default: std::cout << "OK\n"; break;
	}
}
