//cd.h -- for Chapter13 Exercise01
#ifndef __CD_H__
#define __CD_H__

//Class Cd
class Cd
{   // represents a CD disk
public:
    Cd(const char * perf, const char * l, int sel, double pt);
//    Cd(const Cd & cd);
    Cd();
    virtual ~Cd();

    virtual void report() const;
    virtual Cd & operator = (const Cd & cd);

protected:
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
};

//Class Classic
class Classic : public Cd
{
public:
    Classic(const char * mw, const char * perf, 
        const char * l, int sel, double pt);
    Classic(const char * mw, const Cd & cd);
//    Classic(const Classic & c);
    Classic();
    virtual ~Classic();

    virtual void report() const;
    virtual Classic & operator = (const Cd & cd);
    virtual Classic & operator = (const Classic & c);

protected:
private:
    char majorWorks[50];
};

#endif /*__CD_H__*/