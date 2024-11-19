struct Empty {};
struct NonEmpty { int member; };

template <typename M>
struct Nec {
    M member;
    int v;
};


template <typename M>
struct CompNec {
    [[msvc::no_unique_address]] M member;
    int v;
};

template <typename M>
struct MaybeEmpty {
    [[msvc::no_unique_address]] M member;
};

#include <iostream>

int main()
{
    std::cout << "sizeof(Nec<Empty>) = " << sizeof(Nec<Empty>) << '\n';
    std::cout << "sizeof(Nec<NonEmpty>) = " << sizeof(Nec<NonEmpty>) << '\n';
    std::cout << "sizeof(CompNec<Empty>) = " << sizeof(CompNec<Empty>) << '\n';
    std::cout << "sizeof(CompNec<NonEmpty>) = " << sizeof(CompNec<NonEmpty>) << '\n';
    std::cout << "sizeof(MaybeEmpty<Empty>) = " << sizeof(MaybeEmpty<Empty>) << '\n';
    std::cout << "sizeof(MaybeEmpty<NonEmpty>) = " << sizeof(MaybeEmpty<NonEmpty>) << '\n';
}
