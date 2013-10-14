#include "C10Stocks.h"
#include "Headers.h"

//  Constructors
Stock::Stock()
{
//     std::cout << "Default Constructor Called\n";
    std::strncpy(company, "No Name", COMPANY_NAME_LENGTH);
    company[COMPANY_NAME_LENGTH] = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, int n /* = 0 */, double pr /* = 0.0 */)
{
//     std::cout << "Constructor using " << co << " called.\n";

    // same with acquire(). We can just use acquire(co, n, pr); instead.
    std::strncpy(company, co, COMPANY_NAME_LENGTH);
    company[COMPANY_NAME_LENGTH] = '\0';
    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative." << company
            << "shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;

    share_val = pr;
    set_tot();
}

// Destructor
Stock::~Stock()
{
//     std::cout << "Display this line to see when destructor was called.\n"
//         "Bye, " << company << "!\n";
}

void Stock::acquire(const char * co, int n, double pr)
{
    std::strncpy(company, co, COMPANY_NAME_LENGTH);
    company[COMPANY_NAME_LENGTH] = '\0';
    if (n < 0)
    {
        std::cerr << "Number of shares can't be negative." << company
        << "shares set to 0.\n";
            shares = 0;
    }
    else
        shares = n;

    share_val = pr;
    set_tot();
}

void Stock::buy(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "Number of shares purchased can't be negative."
            << "Transaction is aborted.\n";
        std::cout << "You want buy: " << num << ". If you want to sell shares,"
            "you need to use sell function!\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    using std::cerr;
    using std::cout;
    if (num < 0)
    {
        cerr << "Number of shares sold can't be negative."
            << "Transaction is aborted.\n";
        cout << "You want sell: " << num << ". If you want to purchase shares,"
            "you need to use buy function!\n";
    }
    else if (num > shares)
    {
        cerr << "You can't sell more than you have!"
            << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using namespace std;
    cout << "Company: " << company
        << "\n  Shares: " << shares 
        << "\n  Share Price: ￥" << share_val
        << "\n  Total Worth: ￥" << total_val << endl;
}

const Stock & Stock::topStock(const Stock & s) const 
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}