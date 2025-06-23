#include <iostream>

int safe_divide(int x, int y) 
{
    [[assume(y != 0)]];
    return x / y; // u.b.  if y == 0
}
