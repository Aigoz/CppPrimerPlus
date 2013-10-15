#include "Headers.h"
#include "Chapter10.h"
#include "C10Stocks.h"  //code10_03
#include "Person.h" //exercise02
#include "ListSimple.h"

/**************************************/
/*          GLOBAL variable           */
/**************************************/


/*************************************
*      	    Private method           *
**************************************/
template <typename T>
void showListItem(T & theItem);

/*************************************************
*	codes, exercises and draws? --  Definations	 *
*************************************************/
void code10_03()
{
    using std::cout;
    using std::ios_base;
    using std::endl;

//     Stock stock1;
//     stock1.acquire("NanoSmart", 20, 12.50);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    cout.setf(ios_base::showpoint);

//     stock1.show();
//     stock1.buy(15, 18.25);
//     stock1.show();
//     stock1.sell(400, 20.00);
//     stock1.show();
    cout << "***Using default constructor to create stock1.***" << endl;
    Stock stock1;
    stock1.show();
    cout << "***Set stock1 some values.***" << endl;
    stock1.acquire("NanoSmart", 12, 20.0);
    stock1.show();

    cout << "***Using no-default constructor to create stock2.***" << endl;
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);
    stock2.show();

    cout << "***Assigning stock1 to stock2.***\n";
    stock2 = stock1;
    cout << "***Assign done. Then Listing them.***\n";
    stock1.show();
    stock2.show();

    cout << "***Using a constructor to reset an object.***\n"
        "***And watch when the old object would destructor.***\n";
    stock1 = Stock("Nifty Foods", 10, 50.0);
    stock1.show();
    cout << "***Finished!***\n";
}

void code10_09()
{
    using std::cout;
    using std::ios_base;
    using std::endl;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    cout.setf(ios_base::showpoint);

    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout << "Listing Stocks:\n";
    int st = 0;
    for (st = 0; st < STKS; st++)
    {
        stocks[st].show();
    }

    Stock top = stocks[0];
    for (st = 1; st < STKS; st++)
    {
        top = top.topStock(stocks[st]);
    }
    cout << "\nThe top valuable Stock is:\n";
    top.show();
}

void exercise10_01()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise10_02()
{
    Person Yht_P = Person("Haitao", "Yang");
    Person aMan;
    Person heyMan("Banana");

    Yht_P.show();
    Yht_P.formalShow();
    aMan.show();
    heyMan.show();
}

void exercise10_03()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise10_04()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise10_05()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise10_06()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise10_07()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise10_08()
{
    ListSimple<int> myList(10);
    myList.addItem(22);
    myList.addItemAtIndex(33,1);
    myList.addItemAtIndex(99,0);
    myList.addItemAtIndex(88,999);
    myList.addItem(22);
    myList.addItem(44);
    std::cout << "Now we have " << myList.getListCount() << " items.\n";
    myList.addItem(22);
    myList.visit(showListItem);
    std::cout << "---Call removeItem()\n";
    myList.removeItem();
    myList.visit(showListItem);
    std::cout << "---Call removeItem(22)\n";
    myList.removeItem(22);
    myList.visit(showListItem);
    std::cout << "---Call emptyList()\n";
    myList.emptyList();
    myList.visit(showListItem);
}

template <typename T>
void showListItem(T & theItem)
{
    std::cout << "The item is " << theItem << std::endl;
}