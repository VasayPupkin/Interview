#include <iostream>
#include <vector>

/*
 * explicit не позволит конструкцию вида A obj2 = obj1 , она говорит "вызывайте конструктор копирования"
*/

/*
 * Default ctor
Default ctor
Copy ctor
Copy ctor
Copy ctor
Destructor
Hello World!
Destructor
Destructor
Destructor
Destructor
вывод от emplace_back не отличается
*/

using namespace std;

class A
{
public:
    explicit A() { cout << "Default ctor" << endl; }
    explicit A(const A& a) { cout << "Copy ctor" << endl; }
    explicit A(const A&& a) { cout << "Move ctor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A& operator=(const A& a) {
        cout << "Operator =" << endl;
        return *this;
    }
    A& operator=(const A&& a) {
        cout << "Move Operator =" << endl;
        return *this;
    }
};

int main()
{
    vector<A> vectorA(1);
    A obj1;
    A obj2(obj1);
    vectorA.emplace_back(obj2);
    cout << "Hello World!" << endl;
    return 0;
}


