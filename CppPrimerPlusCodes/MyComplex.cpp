#include "MyComplex.h"

MyComplex::MyComplex()
{
    real = 0;
    imaginary = 0;
}

MyComplex::MyComplex(double r, double i /* = 0 */)
{
    real = r;
    imaginary = i;
}

MyComplex MyComplex::operator + (const MyComplex & c) const
{
    MyComplex mc;
    mc.real = this->real + c.real;
    mc.imaginary = this->imaginary + c.imaginary;
    return mc;
}

MyComplex MyComplex::operator - (const MyComplex & c) const
{
    MyComplex mc;
    mc.real = this->real - c.real;
    mc.imaginary = this->imaginary - c.imaginary;
    return mc;
}

MyComplex MyComplex::operator * (const MyComplex & c) const
{
    MyComplex mc;
    mc.real = this->real * c.real - this->imaginary * c.imaginary;
    mc.imaginary = this->real * c.imaginary + this->imaginary * c.real;
    return mc;
}

MyComplex MyComplex::operator * (double x) const
{
    MyComplex mc;
    mc.real = this->real * x;
    mc.imaginary = this->imaginary * x;
    return mc;
}

MyComplex MyComplex::operator ~ () const
{
    MyComplex mc;
    mc.real = this->real;
    mc.imaginary = -this->imaginary;
    return mc;
}

//operator overloading
//friend methods
MyComplex operator * (double x, const MyComplex & c)
{
    return c * x;
}

std::ostream & operator << (std::ostream & os, const MyComplex & c)
{
    os << "(" << c.real << ", " << c.imaginary << "i)";
    return os;
}

std::istream & operator >> (std::istream & is, MyComplex & c)
{
    std::cout << "real: ";
    if (is >> c.real)
    {
        std::cout << "imaginary: ";
        is >> c.imaginary;
    }
    return is;
}