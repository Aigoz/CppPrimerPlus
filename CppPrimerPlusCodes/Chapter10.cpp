#include "Headers.h"
#include "Chapter10.h"
#include "C10Stocks.h"  //code10_03

/**************************************/
/*          GLOBAL variable           */
/**************************************/


/*************************************
*      	    Private method           *
**************************************/


/*************************************************
*	codes, exercises and draws? --  Definations	 *
*************************************************/
void code10_03()
{
    using std::cout;
    using std::ios_base;

    Stock stock1;
    stock1.acquire("NanoSmart", 20, 12.50);
    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout.setf(ios_base::showpoint);

    stock1.show();
    stock1.buy(15, 18.25);
    stock1.show();
    stock1.sell(400, 20.00);
    stock1.show();
}

void exercise10_01()
{

}

void exercise10_02()
{

}

void exercise10_03()
{

}

void exercise10_04()
{

}

void exercise10_05()
{

}

void exercise10_06()
{

}

void exercise10_07()
{

}

void exercise10_08()
{

}