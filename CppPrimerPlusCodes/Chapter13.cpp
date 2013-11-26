#include "Headers.h"
#include "Chapter13.h"
/**************************************/
/*          GLOBAL variable           */
/**************************************/


/*
 *          Private method           
 */
void bravo(const Cd & disk);    // Exercise 01 would use it

/*
 *	codes, exercises and draws? --  Definations
 */
void code13_09()
{
    using std::cout;
    using std::endl;

    Brass piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus hoggy("Horatio Hogg", 382288, 3000.00);
    piggy.viewAcct();
    cout << endl;
    hoggy.viewAcct();
    cout << endl;

//测试有没有virtual的不同多态表现情况。
    Brass * br_ptr1 = &piggy;
    Brass * br_ptr2 = &hoggy;
    br_ptr1->viewAcct();
    cout << endl;
    br_ptr2->viewAcct();
    cout << endl;
    br_ptr1->testShow();
    cout << endl;
    br_ptr2->testShow();
    cout << endl;
}

void exercise13_01()
{
    using namespace std;
    Cd c1( "Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", 
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c1;

    cout << "Using object directly: \n";
    c1.report();
    cout << endl;
    c2.report();
    cout << endl;

    cout << "Using type cd * pointer to object: \n";
    pcd->report();
    cout << endl;
    pcd = &c2;
    pcd->report();
    cout << endl;    

    cout << "Calling a function with a Cd reference argument: \n";
    bravo(c1);
    cout << endl;
    bravo(c2);
    cout << endl;

    cout << "Testing assignment: \n";
    Classic copy;
    copy = c2;
    copy.report();

}

void exercise13_02()
{

}

void exercise13_03()
{

}

void exercise13_04()
{

}


/*
 *          Private Methods Definition
 */
void bravo(const Cd & disk)
{
    disk.report();
}