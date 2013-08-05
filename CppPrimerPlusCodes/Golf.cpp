//  golf.cpp    ----    this file is for pe9-1
#include "golf.h"
#include "Headers.h"

void setgolf(golf & g, const char * name, int hc)
{
    if (name)
        strcpy_s(g.fullname, LEN, name);
    else
    {
        std::cout << "No name entered, set name as empty string." << std::endl;
        strcpy_s(g.fullname, LEN, "");
    }
    g.handicap = hc;
}

int setgolf(golf & g)
{
    std::cout << "Enter name: ";
    std::cin.getline(g.fullname, LEN);
    if (strlen(g.fullname) == 0)
        return 0;

    std::cout << "Enter handicap: ";
    while (!(std::cin >> g.handicap))
    {
        std::cout << "\nEnter an integer Pls: ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }

    while (std::cin.get() != '\n');

    return 1;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    using namespace std;
    cout << "============Show a Golf============"
          "\nName: " << g.fullname <<
          "\nHandicap: " << g.handicap <<
          "\n==================================" <<endl;
}