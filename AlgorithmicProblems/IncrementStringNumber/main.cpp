#include <iostream>
#include <string>
/*
 * Инкркментировать число, переданное в функцию в виде строки
*/
using namespace std;

inline void doIncrement(char &sym, bool &carry){
    if(sym != '9') {
        ++sym;
        carry = false;
    }
    else {
        sym = '0';
        carry = true;
    }
}

void incrementStringNumber(string &strNumber){
    bool carry{false};
    for (auto i = strNumber.size() - 1; i >= 0; --i) {
        doIncrement(strNumber[i], carry);
        if (!carry)
            break;
        else if (i == 0) {
            strNumber.insert(strNumber.begin(), '1');
            break;
        }
    }
}

int main()
{
    string strNumber = "999999999";
    cout << "str before = " << strNumber << endl;
    incrementStringNumber(strNumber);
    cout << "str after = " << strNumber << endl;
    cout << "Hello World!" << endl;
    return 0;
}
