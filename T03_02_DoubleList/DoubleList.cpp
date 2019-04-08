#include <iostream>
#include "DoubleList.hpp"

using namespace std;


int main(int argc, char** argv)
{
    DoubleList<char> doubleList;
    for (int i = 0; i < 10; i++) {
        doubleList.AppendLink('a' + i);
    }
    doubleList.InsertLink(11, 's');
    cout << "Length =" << doubleList.Length() << endl;
    doubleList.PrintLink();
    doubleList.DeleteNode('s');
    doubleList.PrintLink();
    cout << "Length =" << doubleList.Length() << endl;
    getchar();
    return 0;
}