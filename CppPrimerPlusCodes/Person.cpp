#include "Person.h"
#include "Headers.h"

Person::Person(const std::string & ln, const char * fn /* = "HeyJu" */)
{
    lName = ln;
    std::strncpy(fNmae, fn, LIMIT);
    fNmae[LIMIT] = '\0';
}

Person::~Person()
{

}

void Person::show() const
{
    std::cout << "\nThis is: " << fNmae << " " << lName << ".\n";
}

void Person::formalShow() const
{
    std::cout << "\n This is: " << lName << ", " << fNmae << ".\n";
}