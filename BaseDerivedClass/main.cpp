#include <iostream>

using namespace std;

class B
{
public:
    B() {}
    virtual ~B(){}

    virtual void printData() {
        cout << "From Base class "<< data << endl;
    }

    int data = 10;
};

class D : public B
{
public:
    D() {
        data *=2;
    }

    virtual void printData() override {
        cout << "From Derived class "<< data << endl;
    }
};

void printByObject(B obj) {
    obj.printData();
    cout << obj.data << endl;
}

int main()
{
    D derived;
    B *base = &derived;
    printByObject(*base);
    cout << "Hello World!" << endl;
    return 0;
}
