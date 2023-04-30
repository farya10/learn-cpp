#include <iostream>

using namespace std;

class A { public: void f() { cout << " A"; } };

class C : public virtual A { public: void f() { cout << " C"; } };

class B : public virtual A, public virtual C { public: void f() { cout << " B"; } };

class E : public virtual C { public: void f() { cout << " E"; } };

class D : public virtual B, public virtual E { public: void f() { cout << " D"; } };

class F : public virtual D, public virtual E { public: void f() { cout << " F"; }; };

int main()
{
    F object; object.f();
    object.A::f();
    object.B::f();
    object.C::f();
    object.D::f();
    object.E::f();

}