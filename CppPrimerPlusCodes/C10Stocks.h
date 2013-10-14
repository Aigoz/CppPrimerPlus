#ifndef __C10STOCKS_H__
#define __C10STOCKS_H__

class Stock
{
public:
    Stock();
    Stock(const char * co, int n = 0, double pr = 0.0);
    ~Stock();

    void acquire(const char * co, int n, double pr);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show() const;
    const Stock & topStock(const Stock & s) const;

private:
    static const int COMPANY_NAME_LENGTH = 30;

    char company[COMPANY_NAME_LENGTH + 1];
    int shares;
    double share_val;
    double total_val;
    /*inline*/ void set_tot(){ total_val = shares * share_val;}
    //There is no need to add inline in class definition.
    //Complier will inline set_tot() automatically. <<C++ Primer>>
};

#endif /*__C10STOCKS_H__*/