#include <iostream>
#include "CircleList.hpp"

using namespace std;


int main(int argc, char** argv)
{
    CircleList* circleList = nullptr;
    circleList->CreateLinkList(10);
    circleList->TraverseLinkList();

    circleList->InsertNode(3, 6);
    circleList->TraverseLinkList();

    circleList->DeleteNode(5);
    circleList->TraverseLinkList();

    getchar();
    return 0;
}