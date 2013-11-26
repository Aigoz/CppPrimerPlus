//brass.h -- for Chapter13 code 13.7
#ifndef __BRASS_H__
#define __BRASS_H__

class Brass
{
public:
    Brass (const char * s = "Nullbody", long an = -1, double bal = 0.0);
    void deposit(double amt);
    virtual void withdraw(double amt);
    double Balance() const;
    virtual void viewAcct() const;
    virtual ~Brass() {}
    // without virtual redefined
    void testShow();
    
protected:
private:
    enum {MAX = 35};
    char fullName[MAX];
    long acctNum;
    double balance;
};

//Brass Plus
class BrassPlus : public Brass
{
public:
    BrassPlus(const char * s = "Nullbody", long an = -1, double bal = 0.0,
        double ml = 500, double r = 0.0);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
    virtual void viewAcct() const;
    virtual void withdraw(double amt);
    void resetMax(double m) { maxLoan = m; }
    void resetRate(double r) { rate = r; }
    void resetOwes() { owesBank = 0; }
    // without virtual redefined
    void testShow();

protected:
private:
    double maxLoan;
    double rate;
    double owesBank;
};

#endif/*__BRASS_H__*/