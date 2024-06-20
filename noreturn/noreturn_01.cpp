// noreturn attribute - since C++11
//Bildirilen ya da tanımlanan fonksiyon çağıran koda geri dönüş sağlamayacak.

[[noreturn]] void exit(int status);


/*
In order to return functions, compilers have to include some machine instructions in the generated code. For example, in many processors the machine instruction "ret" is used to return a function. However, this "ret" machine instruction alone may not be sufficient. The compiler may have to reload some registers with the input values before returning. 
Therefore, the compiler, realizing that the function will not return, may not add this code to the function. This means more efficient code generation. 
On the other hand, if the compiler realizes that the code will not return in the function call, it can make some optimizations there as well. 
[[noreturn]] is also useful for understanding the code.

*/
