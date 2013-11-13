#include "Headers.h"
#include "Chapter12.h"
#include "string2.h"    //for exericse 02

/**************************************/
/*          GLOBAL variable           */
/**************************************/


/*************************************
*      	    Private method           *
**************************************/


/*************************************************
*	codes, exercises and draws? --  Definations	 *
*************************************************/
void exercise12_01()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise12_02()
{
    using namespace std;
    String s1(" and I am a C++ student. ");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A') <<
        "'A' characters in it.\n";
    s1 = "red";
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }

        if (success)
            break;
        else
            cout << "Try again!\n";
    }

    cout << "Bye\n";
}

void exercise12_03()
{

}

void exercise12_04()
{

}

void exercise12_05()
{

}

void exercise12_06()
{

}