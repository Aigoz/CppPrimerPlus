//vintagePort.cpp -- -- for Chapter13 Exercise04 -- :public port.h
#include "vintagePort.h"
#include "Headers.h"
using std::cout;
using std::endl;

/*
 *      VintagePort Constructors
 */
VintagePort::VintagePort() : Port()
{
    nickname = new char[5];
    strcpy_s(nickname, 5, "none");
    year = 0;
}

VintagePort::VintagePort(const char * br, const char * st, int b, 
    const char * nn, int y) 
    : Port(br, st, b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy_s(nickname, strlen(nn) + 1, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
    year = vp.year;
}

/*
 *      VintagePort Public Methods
 */
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (&vp == this)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::show() const
{
    Port::show();
    cout << "Nickname: " << nickname
        << "\nYear: " << year << endl;
}

/*
 *      VintagePort Friend Methods
 */
ostream & operator<< (ostream & os, const VintagePort & vp)
{
    os << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}