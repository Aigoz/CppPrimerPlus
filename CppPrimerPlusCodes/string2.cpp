#include "string2.h"
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;
using std::strlen;
using std::strcpy;
using std::strcmp;
using std::strcat;
using std::tolower;
using std::toupper;

int String::num_strings = 0;

int String::howMany()
{
    return num_strings;
}

//  constructor methods
String::String(const char * s)
{
    len = strlen(s);
    str = new char [len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char [1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st)
{
    len = st.len;
    str = new char [len + 1];
    strcpy(str, st.str);
    num_strings++;
}

String::~String()
{
    --num_strings;
    delete [] str;
}

//  Overloaded operator methods
String & String::operator = (const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char [len + 1];
    strcpy(str, st.str);
    return *this;
}

String & String::operator = (const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new char [len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator [] (int i)
{
    return str[i];
}

const char & String::operator [] (int i) const
{
    return str[i];
}

//Overloaded operator friend methods
bool operator < (const String & st, const String & st2)
{
    return (strcmp(st.str, st2.str) < 0);
}

bool operator > (const String & st, const String & st2)
{
    return (strcmp(st.str, st2.str) > 0);
}

bool operator == (const String & st, const String & st2)
{
    return (strcmp(st.str, st2.str) == 0);
}

ostream & operator << (ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator >> (istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);

    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

//exercise 2 add methods friends and no-friends
/*  friend method
 *  Both "charStr" + String and String + String are use this method.
 *  Because, "charStr" + String, "charStr" will use String(const cahr *) to turn
 *  to String, then use this method.
*/
String operator + (const String & st1, const String & st2)
{
    char * tempStr = new char [st1.len + st2.len + 1];
    strcpy(tempStr, st1.str);
    strcat(tempStr, st2.str);

    String newSt = String(tempStr);
    return newSt;
}

void String::stringup()
{
    for (int i = 0; i < len; i++)
    {
        this->str[i] = toupper(this->str[i]);
    }
}

void String::stringlow()
{
    for (int i = 0; i < len; i++)
    {
        this->str[i] = tolower(this->str[i]);
    }
}

int String::has(char c)
{
    int charCount = 0;
    char * tempChar = this->str;
    while (*tempChar != '\0')
    {
        if (c == *tempChar)
            charCount++;
        tempChar++;
    }
    return charCount;
}