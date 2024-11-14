#include <cassert>

[[maybe_unused]] void foo([[maybe_unused]] int x, [[maybe_unused]] int y)
{
    [[maybe_unused]] debug:  // for labels since C++26
    [[maybe_unused]] int val = x + y;
    assert(val > 0); 
    
} 

int main() 
{
}
