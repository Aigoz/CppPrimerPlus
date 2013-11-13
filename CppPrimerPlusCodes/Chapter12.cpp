#include "Headers.h"
#include "Chapter12.h"
#include "string2.h"    //for exercise 02
#include "stack.h"      //for exercise 04

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
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise12_04()
{
        using namespace std;
//         Stack st(3); // create a stack of po numbers
//         unsigned long temp;
//         char c;
// 
//         cout << "Please enter A to add a PO,\n"
//             << "P to process a PO, and Q to quit.\n";
//         while (cin >> c && (c = toupper(c)) != 'Q')
//         {
//             while (cin.get() != '\n')
//                 continue;
//             if (c != 'A' && c != 'P')
//             {
//                 cout << "Please respond with A, P, or Q: ";
//                 continue;
//             }
//             switch (c)
//             {
//             case 'A': if (st.isfull())
//                           cout << "stack already full\n";
//                       else
//                       {
//                           cout << "Enter PO number: ";
//                           cin >> temp;
//                           st.push(temp);
//                       }
//                       break;
//             case 'P': if (st.isempty())
//                           cout << "stack already empty\n";
//                       else {
//                           st.pop(temp);
//                           cout << "Processing PO " << temp << '\n';
//                       }
//                       break;
//             default: cout << "Whoops! Programming error!\n";
//             }
//             cout << "Please enter A to add a customer,\n"
//                 << "P to process a customer, and Q to quit.\n";
//         }
//         cout << "Done!\n";

        Stack st(20);
        Stack st1 = Stack(2);
        while (st.push(1));
        while (st1.push(2));
        cout << "pop st1\n";
        Item tempItem = 0;
        while (st1.pop(tempItem))
            cout << "st1: " << tempItem << endl;
        st1 = st;
        cout << "pop st1=st\n";
        while (st1.pop(tempItem))
            cout << "st1: " << tempItem << endl;
        cout << "pop st\n";
        while (st.pop(tempItem))
            cout << "st: " << tempItem << endl;
}

void exercise12_05()
{
    std::cout << "There is no code need here~" << std::endl;
}

void exercise12_06()
{
    std::cout << "Coming soon or never here~" << std::endl;
}