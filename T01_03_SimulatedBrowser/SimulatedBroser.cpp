#include <iostream>
#include "LinkStack.hpp"
#include <string>

using namespace std;

LinkStack<string> backStack;
LinkStack<string> forwardStack;
string currentPage;

bool visitNewPage(string pageUri)
{
    while (forwardStack.getSize() > 0)
    {
        string tempPage = forwardStack.top();
        forwardStack.pop();
        cout << "clear pages in forwardStack :" << tempPage << endl;
    }
    currentPage = pageUri;
    backStack.push(pageUri);
    cout << "current page is :" << currentPage << endl;

    return true;
}

bool gotoBackPage()
{
    currentPage = backStack.top();
    backStack.pop();
    forwardStack.push(currentPage);
    currentPage = backStack.top();
    cout << "current page is :" << currentPage << endl;
    return true;
}

bool gotoForwardPage()
{
    currentPage = forwardStack.top();
    forwardStack.pop();
    backStack.push(currentPage);
    cout << "current page is :" << currentPage << endl;

    return true;
}

int main(int argc, char** argv)
{
    string homePage = "www.google.com";
    cout << "visit home page first..." << endl;
    string currentPage = homePage;
    visitNewPage(currentPage);
    cout << "visit a new page 01..." << endl;
    currentPage = "www.google.com/uri_001";
    visitNewPage(currentPage);
    cout << "visit a new page 02..." << endl;
    currentPage = "www.google.com/uri_002";
    visitNewPage(currentPage);

    cout << "go back to previous page 01..." << endl;
    gotoBackPage();

    cout << "go forward to next page 01..." << endl;
    gotoForwardPage();

    cout << "go back to previous page 02..." << endl;
    gotoBackPage();

    cout << "go back to previous page 03..." << endl;
    gotoBackPage();

    cout << "visit a new page 03..." << endl;
    currentPage = "www.google.com/uri_003";
    visitNewPage(currentPage);

    cout << "go back to previous page 04..." << endl;
    gotoBackPage();
    
    getchar();
    return 0;
}