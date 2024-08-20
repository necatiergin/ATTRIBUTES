int foo();
int bar();
int baz();

int func (int x) 
{
    switch (x) {
    case 0: return foo();
    case 1: return bar();
    case 2: return baz();
    default:
        // default case is unreachable.
        [[assume(false)]];
        return 0;
    }
}
