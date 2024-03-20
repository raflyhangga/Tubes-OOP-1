#include <iostream>

#include "tubesoop1/something1/class1.hpp"
#include "tubesoop1/something2/class2.hpp"

using namespace std;

int main()
{
    cout << "[Welcome to TUBES-OOP-1]" << endl;

    class1 c1;
    class2 c2;
    c1.a = 2;

    int b = 0;
    cin >> b;

    cout << c1.add(b, c1.a) << endl;
    cout << c2.multiply(3, 2) << endl;
    return 0;
}