#include "Headers.h"
#include "Chapter11.h"
#include "Time.h"   // For exercise04
#include "MyComplex.h"  //For exercise07

/**************************************/
/*          GLOBAL variable           */
/**************************************/


/*************************************
*      	    Private method           *
**************************************/


/*************************************************
*	codes, exercises and draws? --  Definations	 *
*************************************************/
void exercise11_01()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise11_02()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise11_03()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise11_04()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2,48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10 * Tosca: " << 10 * tosca << endl;


}

void exercise11_05()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise11_06()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise11_07()
{
    using namespace std;
    MyComplex a (3.0, 4.0);
    MyComplex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "comlex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit): \n";
    }
    cout << "Done!\n";
}