#include <iostream>

class B : public A {
   public:
    B() : A(42), b(17) { std::cout << "CTOR A(int): " << b << "\n"; }
    ~B() { std::cout << "DTOR ~A()\n"; }
    void foo() const override { std::cout << "A::foo()\n"; }

   private:
    int b;
};