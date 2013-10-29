/************************************************************************/
/*                          Time.h                                      */
/*  For Chapter11, exercise 04                                          */
/************************************************************************/
#ifndef __TIME_H__
#define __TIME_H__
#include <iostream>

class Time
{
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator + (const Time & t1, const Time & t2);
    friend Time operator - (const Time & t1, const Time & t2);
    friend Time operator * (const Time & t, double n);
    friend Time operator * (double n, const Time & t) {return t*n;}
    friend std::ostream & operator << (std::ostream & os, const Time & t);

protected:

private:
    int hours;
    int minutes;
};
#endif