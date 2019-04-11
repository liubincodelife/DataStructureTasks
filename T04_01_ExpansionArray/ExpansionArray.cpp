#include <iostream>
#include "ExpansionArray.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ExpansionArray<int> expansionArray;
    for (int i = 1; i <= 10; i++)
    {
        expansionArray.appendData(i);
    }
    expansionArray.print();
    expansionArray.appendData(12);
    expansionArray.print();
    getchar();
    return 0;
}