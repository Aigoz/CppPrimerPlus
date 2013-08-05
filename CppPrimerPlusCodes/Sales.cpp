//pe9-4
#include "Sales.h"
#include "Headers.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        int i = 0;
        double sum = 0;
        s.average = 0;
        s.max = ar[0];
        s.min = ar[0];
        n = n<QUARTERS ? n : QUARTERS;

        // set ar[] to s.sales[]
        for (i = 0; i < n; i++)
        {
            s.sales[i] = ar[i];
            sum += s.sales[i];
            s.max = s.max>s.sales[i] ? s.max : s.sales[i];
            s.min = s.min<s.sales[i] ? s.min : s.sales[i];
        }
        s.average = sum / i;

        // set remaining ar[] to 0
        for (i = n; i >= (QUARTERS-1); i--)
        {
            s.sales[i] = 0;
        }
    }

    void setSales(Sales & s)
    {
        using std::cin;
        using std::cout;
        using std::endl;

        double sum = 0;
        s.max = DBL_MIN;
        s.min = DBL_MAX;

        cout << "You need to enter " << QUARTERS <<" sales." << endl;
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "Sales " << i+1 << ":";
            while (!(cin >> s.sales[i]))
            {
                cout << "\nPlease enter a double: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            while (cin.get() != '\n');
            
            sum += s.sales[i];
            s.max = s.max>s.sales[i] ? s.max : s.sales[i];
            s.min = s.min<s.sales[i] ? s.min : s.sales[i];
        }
        s.average = sum / QUARTERS;

        cout << "Finished!" << endl;
    }

    void showSales(const Sales & s)
    {
        using namespace std;

        cout << "======Show Sales======\n"
            "Average: " << s.average <<
            "\nMax: " << s.max << 
            "\nMin: " << s.min << endl;
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << "Sales "<< i << ": " << s.sales[i] << endl;
        }
        cout << "=========Ends========" << endl;
    }
}