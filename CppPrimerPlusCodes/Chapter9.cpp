#include "Chapter9.h"
#include "Headers.h"
#include "Golf.h"   //  for pe9-1
#include <new>  // for placement new
#include "Sales.h"  // for pe9-4

// Chapter9::Chapter9(void)
// {
// }
// 
// 
// Chapter9::~Chapter9(void)
// {
// }

/************************************************************************/
/* GLOBAL variable                                                     */
/************************************************************************/
//  pe2
struct chaff {
    char dross[20];
    int slag;
};

//char buffer[200];   //method 1

/*************************************
*	Private method of Chapter8.cpp	 *
**************************************/


/*************************************************
*	codes, exercises and draws? --  Definations	 *
*************************************************/
void exercise09_01()
{
    using namespace std;

    golf ga;
    golf gb;

    setgolf(ga, "G A", 23);
    showgolf(ga);
    handicap(ga, 24);
    showgolf(ga);

    while (setgolf(gb))
        showgolf(gb);

    cout << "Exit exercise 9-1." << endl;
}

void exercise09_02()
{
    std::cout << "No codes of Exercise 0902." << std::endl;
}

void exercise09_03()
{
    using std::cout;
    using std::endl;

    char * buffer = new char[200];  // option2 need delete

    chaff * chaffPtr = NULL;
    chaffPtr = new (buffer) chaff[2];

    strcpy_s(chaffPtr[0].dross, "Dross1");
    chaffPtr[0].slag = 1;
    strcpy_s(chaffPtr[1].dross, "Dross2");
    chaffPtr[1].slag = 2;

    for (int i = 0; i < 2; i++)
    {
        cout << chaffPtr[i].dross << ": " << chaffPtr[i].slag << endl;
    }

    delete [] buffer;   // option 2
    //Do Not delete chaffPtr, because chaffPtr uses buffer.
    //If you delete both buffer and chaffPtr, it will crash.
}

void exercise09_04()
{
    using SALES::setSales;

    double dArr[3] = {-1.5, 2.3, 99.9};
    SALES::Sales msales;

    setSales(msales, dArr, 3);
    SALES::showSales(msales);
    setSales(msales);
    SALES::showSales(msales);
}