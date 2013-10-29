//For Chapter 11, exericse 7
#ifndef __MYCOMPLEX_H__
#define __MYCOMPLEX_H__

#include <iostream>

class MyComplex
{
public:
    MyComplex();
    MyComplex(double r, double i = 0);
    MyComplex operator + (const MyComplex & c) const;
    MyComplex operator - (const MyComplex & c) const;
    MyComplex operator * (const MyComplex & c) const;
    MyComplex operator * (double x) const;
    MyComplex operator ~ () const;

    friend MyComplex operator * (double x, const MyComplex & c);
    friend std::ostream & operator << (std::ostream & os, const MyComplex & c);
    friend std::istream & operator >> (std::istream & is, MyComplex & c);

protected:

private:
    double real;
    double imaginary;
};

#endif /*__MYCOMPLEX_H__*/