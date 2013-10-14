#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person
{
private:
    static const int LIMIT = 25;
    std::string lName;
    char fNmae[LIMIT];
    
public:
    Person() {lName = ""; fNmae[0] = '\0';}
    Person(const std::string & ln, const char * fn = "HeyJu");
    ~Person();
    
    void show() const;          //firstname lastname format
    void formalShow() const;    //lastname, firstname format
};

#endif/*__PERSON_H__*/