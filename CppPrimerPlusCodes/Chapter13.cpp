#include "Headers.h"
#include "Chapter13.h"
#include "brass.h"
#include "cd.h"
#include "port.h"
#include "vintagePort.h"
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
    exercise13_01();
}

void exercise13_03()
{
    std::cout << "Coming soon or never here~" << std::endl;
}

void exercise13_04()
{
    using namespace std;
    Port p_one = Port("Potter", "ruby", 10);
    VintagePort vp_one = VintagePort("Venter", "vintage", 20, "Vince", 100);
    VintagePort vp_none;
    Port * p_ptr = &p_one;
    VintagePort * vp_ptr = &vp_one;

    p_one.show();
    cout << *p_ptr << endl;
    vp_one.show();
    cout << *vp_ptr << endl;
    vp_none.show();
    cout << endl;

    *p_ptr += 22;
    p_ptr->show();
    *p_ptr -= 12;
    p_ptr->show();
    cout << endl;

    p_ptr = &vp_one;
    *p_ptr += 22;
    p_ptr->show();
    *p_ptr -= 12;
    p_ptr->show();
    cout << *p_ptr << endl;
    cout << *(VintagePort*)p_ptr << endl;
    cout << endl;

    vp_none = vp_one;
    vp_none.show();
    cout << endl;
}

void myTest01()
{
    // For details, please visit my bolg: http://kobe82680.blog.163.com/blog/static/168285706201310279321781/
    // to see why I made this test.
    using namespace std;
    Cd c1( "Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", 
        "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c2;

    pcd->operator=(c1);
    pcd->operator=(c2);
    pcd = &c1;
    pcd->operator=(c1);
    pcd->operator=(c2);
}


/*
 *          Private Methods Definition
 */
void bravo(const Cd & disk)
{
    disk.report();
}