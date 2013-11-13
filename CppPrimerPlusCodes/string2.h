//For Chapter12, exercise 2
#ifndef __STRING2_H__
#define __STRING2_H__

#include <iostream>
using std::ostream;
using std::istream;

class String
{
public:
//  constructors
    String(const char * s);
    String();
    String(const String & st);
    ~String();

    int length() const {return len;}
//  overloaded operator methods
    String & operator = (const String & st);
    String & operator = (const char * s);
    char & operator [] (int i);
    const char & operator [] (int i) const;
// overloaded operator friend methods
    friend bool operator < (const String & st, const String & st2);
    friend bool operator > (const String & st, const String & st2);
    friend bool operator == (const String & st, const String & st2);
    friend ostream & operator << (ostream & os, const String & st);
    friend istream & operator >> (istream & is, String & st);
//exercise 2 add methods friends and no-friends
    friend String operator + (const String & st1, const String & st2);
    void stringup();
    void stringlow();
    int has(char c);

//  static function
    static int howMany();
protected:

private:
    char * str;                     //string ptr
    int len;                        //length of str
    static int num_strings;         //number of objects
    static const int CINLIM = 80;   //cin input limit
};

#endif/*__STRING2_H__*/