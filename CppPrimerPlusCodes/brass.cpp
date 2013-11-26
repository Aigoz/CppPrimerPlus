//brass.cpp - for Chapter13 code13.8
#include "Headers.h"
#include "brass.h"

using std::cout;
using std::ios_base;
using std::endl;

//Brass Method
Brass::Brass(const char * s /* = "Nullbody" */, long an /* = -1 */, 
    double bal /* = 0.0 */)
{
    std::strncpy(fullName, s, MAX - 1);
    fullName[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}

void Brass::deposit(double amt)
{
    if (amt < 0)
        cout << "Please deposit a positive amount;\n"
            << "Deposit is canceled.\n";
    else
        balance += amt;
}

void Brass::withdraw(double amt)
{
    if (amt < 0)
        cout << "Please withdrawal a positive amount;"
        <<"\nWithdrawal is canceled.\n";
    else if (amt > balance)
        cout << "Withdrawal amount is $" << amt 
            << " exceeds your balance.\n"
            << "Deposit is canceled.\n";
    else
        balance -= amt;
}

double Brass::Balance() const
{
    return balance;
}

void Brass::viewAcct() const
{
    ios_base::fmtflags originalState = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    cout.setf(originalState);
}

// without virtual redefined
void Brass::testShow()
{
    cout << "Brass Show!" << endl;
}

//BrassPlus Methods
BrassPlus::BrassPlus (const char * s /* = "Nullbody" */, long an /* = -1 */, 
    double bal /* = 0.0 */, double ml /* = 500 */, double r /* = 0.0 */)
    : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus (const Brass & ba, double ml /* = 500 */, 
    double r /* = 0.1 */) : Brass(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::viewAcct() const
{
    ios_base::fmtflags originalState = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    Brass::viewAcct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
    cout.setf(originalState);
}

void BrassPlus::withdraw(double amt)
{
    ios_base::fmtflags originalState = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    double bal  = Balance();
    if (amt <= bal)
        Brass::withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        deposit(advance);
        Brass::withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction canceled.\n";

    cout.setf(originalState);
}

// without virtual redefined
void BrassPlus::testShow()
{
    cout << "BrassPlus Show!" << endl;
}