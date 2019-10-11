//#include <iostream>
//#include <vector>

///*
// * explicit не позволит конструкцию вида A obj2 = obj1 , она говорит "вызывайте конструктор копирования"
//*/

///*
// * Default ctor
//Default ctor
//Copy ctor
//Copy ctor
//Copy ctor
//Destructor
//Hello World!
//Destructor
//Destructor
//Destructor
//Destructor
//вывод от emplace_back не отличается
//*/

//using namespace std;

//class A
//{
//public:
//    explicit A() { cout << "Default ctor" << endl; }
//    explicit A(const A& a) { cout << "Copy ctor" << endl; }
//    explicit A(const A&& a) { cout << "Move ctor" << endl; }
//    ~A() { cout << "Destructor" << endl; }
//    A& operator=(const A& a) {
//        cout << "Operator =" << endl;
//        return *this;
//    }
//    A& operator=(const A&& a) {
//        cout << "Move Operator =" << endl;
//        return *this;
//    }
//};

//int main()
//{
//    vector<A> vectorA(1);
//    A obj1;
//    A obj2(obj1);
//    vectorA.emplace_back(obj2);
//    cout << "Hello World!" << endl;
//    return 0;
//}

/*
 * если определен перемещающий конструктор
 * emplace_back:
I am being constructed.

push_back:
I am being constructed.
I am being moved.

если есть только конструктор копирования

*/

#include <vector>
#include <string>
#include <iostream>

struct President
{
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
    President(const President& other)
        : name(other.name), country(other.country), year(other.year)
    {
        std::cout << "I am being copied.\n";
    }
//    President(President&& other)
//        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
//    {
//        std::cout << "I am being moved.\n";
//    }
    President& operator=(const President& other) = default;
};

int main()
{
    std::vector<President> elections;
    std::cout << "emplace_back:\n";
    elections.emplace_back("Nelson Mandela", "South Africa", 1994);

    std::vector<President> reElections;
    std::cout << "\npush_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));

    std::cout << "\nContents:\n";
    for (President const& president: elections) {
        std::cout << president.name << " was elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
    for (President const& president: reElections) {
        std::cout << president.name << " was re-elected president of "
                  << president.country << " in " << president.year << ".\n";
    }
}


