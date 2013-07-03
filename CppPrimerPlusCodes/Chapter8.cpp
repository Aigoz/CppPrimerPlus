#include "Chapter8.h"
#include "Headers.h"

// 
// Chapter8::Chapter8(void)
// {
// }
// 
// 
// Chapter8::~Chapter8(void)
// {
// }

/*************************************
*	Private method of Chapter8.cpp	 *
**************************************/
//  e1
void showString_0801(const char * str, int foo = 0);




/*************************************************
*	codes, exercises and draws? --  Definations	 *
*************************************************/

void exercise08_01()
{
    using namespace std;

    char * myStr = "This is exercise 0801";
    int i = 0;

    for (i = 0; i < 3; i++)
    {
        cout << "i = " << i << ":" <<endl;
        showString_0801(myStr, i);
    }

    i = 6;
    cout << "i = " << i << ".\n";
    showString_0801(myStr, i);
}

void showString_0801(const char * str, int foo)
{
    using namespace std;

    static int count_0801;
    count_0801++;

    if (0 == foo)
        cout << str << endl;
    else
        for (int i = 0; i < count_0801; i++)
            cout << str << endl;
}

void exercise08_02()
{

}

void exercise08_03()
{

}

void exercise08_04()
{

}

void exercise08_05()
{

}

void exercise08_06()
{

}

void exercise08_07()
{

}