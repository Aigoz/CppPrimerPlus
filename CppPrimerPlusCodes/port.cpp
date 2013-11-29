//port.cpp -- for Chapter13 Exercise04
#include "port.h"
#include "Headers.h"
using std::cout;
using std::endl;
/*
 *      Port Constructors
 */
Port::Port(const char * br /* = "none" */, const char * st /* = "none" */, 
    int b /* = 0 */)
{
    brand = new char[strlen(br) + 1];
    strcpy_s(brand, strlen(br) + 1, br);
    strcpy_s(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy_s(brand, strlen(p.brand) + 1, p.brand);
    strcpy_s(style, p.style);
    bottles = p.bottleCount();
}

/*
 *      Port public methods
 */
Port & Port::operator=(const Port & p)
{
    if (&p == this)
        return *this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy_s(brand, strlen(p.brand) + 1, p.brand);
    strcpy_s(style, p.style);
    bottles = p.bottleCount();
    return *this;
}

Port & Port::operator+=(int b)
{
    if (b < 0)
    {
        cout << "The increase bottles should be positive!" << endl;
        return *this;
    }
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if (b < 0)
    {
        cout << "The decrease bottles should be positive!" << endl;
        return *this;
    }
    else if (b > bottles)
    {
        cout << "There is no enough bottles to decrease " << b << " bottles.\n";
        return *this;
    }
    bottles -= b;
    return *this;
}

void Port::show() const
{
    cout << "Brand: " << brand
        << "\nKind: " << style
        << "\nBottles: " << bottles << endl;
}

/*
 *      Port friend methods
 */
ostream & operator<< (ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
