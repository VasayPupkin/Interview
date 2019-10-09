#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    A() { cout << "Default ctor" << endl; }
    A(const A& a) { cout << "Copy ctor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A& operator=(const A& a) {
        cout << "Operator =" << endl;
        return *this;
    }
};

int main()
{
    vector<A> vectorA(1);
    A obj1;
    A obj2(obj1);
    vectorA.push_back(obj2);
    cout << "Hello World!" << endl;
    return 0;
}
