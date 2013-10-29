#include "Time.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m /* = 0 */)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h /* = 0 */, int m /* = 0 */)
{
    hours = h;
    minutes = m;
}

//operator overloading
//friend methods
Time operator + (const Time & t1, const Time & t2)
{
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator - (const Time & t1, const Time & t2)
{
    Time diff;
    int tol1, tol2;
    tol1 = t1.minutes + 60 * t1.hours;
    tol2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (tol1 - tol2) % 60;
    diff.hours = (tol1 - tol2) / 60;
    return diff;
}

Time operator * (const Time & t, double n)
{
    Time resultT;
    long totalMinutes = t.hours * n * 60 + t.minutes * n;
    resultT.hours = totalMinutes / 60;
    resultT.minutes = totalMinutes % 60;
    return resultT;
}

std::ostream & operator << (std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}