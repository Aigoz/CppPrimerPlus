//port.h -- for Chapter13 Exercise04
#ifndef __PORT_H__
#define __PORT_H__

#include <iostream>
using namespace std;

class Port
{
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port() { delete [] brand; }

    Port & operator= (const Port & p);
    Port & operator+= (int b);
    Port & operator-= (int b);
    int bottleCount() const { return bottles; }
    virtual void show() const;
    friend ostream & operator<< (ostream & os, const Port & p);

protected:
private:
    char * brand;
    char style[20];
    int bottles;
};

#endif /*__PORT_H__*/