//vintagePort.h -- for Chapter13 Exercise04 -- :public port.h
#ifndef __VINTAGEPORT_H__
#define __VINTAGEPORT_H__

#include <iostream>
#include "port.h"
using namespace std;

class VintagePort : public Port
{
public:
    VintagePort();
    VintagePort(const char * br, const char * st, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    virtual ~VintagePort() { delete [] nickname; }

    VintagePort & operator= (const VintagePort & vp);
    virtual void show() const;
    friend ostream & operator<< (ostream & os, const VintagePort & vp);

protected:
private:
    char * nickname;
    int year;
};

#endif /*__VINTAGEPORT_H__*/