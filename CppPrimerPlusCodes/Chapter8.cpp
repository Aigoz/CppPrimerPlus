#include "Chapter8.h"
#include "Headers.h"
#include "Chapter4.h"   /* For struct CandyBar  */

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

//  e2
/*CandyBar &*/void setCandy(CandyBar & theCandyBar, 
    const char * cBrand = "Millennium Munch", 
    int cCalorie        = 350, 
    double cWeight      = 2.85);
void showCandy(const CandyBar & theCandyBar);

//  e3
int convertToUppercase(std::string & str);

//  e4
struct stringy 
{
    char * str;
    int ct;         // length of string(not counting '\0'
};
void set(stringy & stry,const char * str);
void show(const stringy & stry, int times = 1);
void show(const char * str, int times = 1);

//  e5
template <typename T>
T max5(const T * T_Array);

//  e6
template <typename T>
T maxn(const T * T_Array, const int aSize);

/*          Notice!!!!!!!!!!!!!!! about const      */
/* the location of const in this declare.
  1. char * const string_array[] <=> const T * T_Array (when T is explicit specialization as "char *")
  beacause T const * T_Array <=> const T * T_Array.

  2. const char * string_array[] is wrong!!!!!!!!!!
  because this <=> char const ** string_array;
    but when T = char *, 
            const T * T_array 
            <=> const (char *) * T_array 
            <=> char * const * T_array 
            <=> char * const T_array[]

OR      

        This is better to implement char*

    3. we can use typedef char * P_CHAR;
    use P_CHAR instead of char *.
    This is better, and it is a good coding habbit.
*/
template <> char * maxn<char *> (char * const string_array[], const int sA_Size);

//  e7
struct debts
{
    char name[50];
    double amount;
};

template <typename T>
void sumArray (const T arr[], const int n);
template <typename T>
void sumArray (T * arr[], const int n);


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
    CandyBar myCandy = {
        "chocolate",
        100,
        1.5
    };

    showCandy(myCandy);
    setCandy(myCandy);
    showCandy(myCandy);
    setCandy(myCandy, "WoW candy", 10, 100.2);
    showCandy(myCandy);
}

void setCandy(CandyBar & theCandyBar, const char * cBrand, int cCalorie, double cWeight)
{
        strcpy_s(theCandyBar.candyBrand, cBrand);
        theCandyBar.candyCalorie = cCalorie;
        theCandyBar.candyWeight = cWeight;
 }

void showCandy(const CandyBar & theCandyBar)
{
    using namespace std;

    cout << "####  CandyBar  ####" << endl;
    cout << "Candy Brand:   " << theCandyBar.candyBrand
        << "\nCandy Calorie:  " << theCandyBar.candyCalorie
        << "\nCandy Weight: " << theCandyBar.candyWeight << endl;
}


void exercise08_03()
{
    using namespace std;

    string str;

    cout << "Enter a string (q to quit): ";
    while (getline(cin, str))
    {
        if (-1 == convertToUppercase(str))
            break;
        else
        {
                cout << str << "\nNext string (q to quit): ";
        }
    }
    cout << "Bye." << endl;
}

int convertToUppercase(std::string & str)
{
    if (str.compare("q") && str.compare("Q"))
    {
        transform(str.begin(), str.end(), str.begin(), toupper);
        return 0;
    }
    else 
        return -1;
}


void exercise08_04()
{
    using namespace std;

    stringy beany;
    char testing[] = "Reality isn't what it used to be. ";

    set(beany, testing);
    show(beany);
    show(beany, 2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done! ");
}

void set(stringy & stry,const char * str)
{
    stry.ct = strlen(str);

    stry.str = new char [stry.ct + 2];
    strcpy_s(stry.str, stry.ct + 1, str);
}

void show(const char * str, int times /* = 1 */)
{
    using namespace std;

    while (times-- > 0)
        cout << str << endl;
}

void show(const stringy & stry, int times /* = 1 */)
{
    using namespace std;

    while (times-- > 0)
        cout << stry.str << endl;
}


void exercise08_05()
{
    using namespace std;

    int intArray[ARRAY_SIZE] = {4, 8, 5, 3, 7};
    double doubleArray[ARRAY_SIZE] = {9.0, 3.0, 4.4, 2.2, 8.99};

    cout << "Max int: " << max5(intArray) << endl;
    cout << "Max double: " << max5(doubleArray) << endl;
}

template <typename T>
T max5(const T * T_Array)
{
    T maxT;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (0 == i)
            maxT = T_Array[i];
        else
            maxT = maxT > T_Array[i] ? maxT : T_Array[i];
    }
    return maxT;
}


void exercise08_06()
{
    using namespace std;

    int intArr[6] = {7,8,2,1,5,3};
    double doubleArr[4] = {9.2, 3.3, 2.2, 5.5};
    char * strArr1[5] = {
        "12345",
        "aabbc",
        "223",
        "1234",
        "12"
    };
    char * strArr2[3] = {
        "12",
        "12345667",
        "4562323"
    };

    cout << "Max int: " << maxn(intArr, 6) << endl;
    cout << "Max Double: " << maxn(doubleArr, 4) << endl;
    cout << "Max string1: " << maxn(strArr1, 5) << endl;
    cout << "Max string2: " << maxn(strArr2, 3) << endl;
}

template <typename T>
T maxn(const T * T_Array, const int aSize)
{
    T maxT;

    for (int i = 0; i < aSize; i++)
    {
        if (0 == i)
            maxT = T_Array[i];
        else
            maxT = maxT > T_Array[i] ? maxT : T_Array[i];
    }
    return maxT;
}

template <> char * maxn<char *> (char * const string_array[], const int sA_Size)
{
    char * maxStr;
    maxStr = string_array[0];

    for (int i = 1; i < sA_Size; i++)
        maxStr = strlen(maxStr) >= strlen(string_array[i]) ? maxStr : string_array[i];

    return maxStr;
}


void exercise08_07()
{
    using namespace std;

    int things[6] = {13,31,103,301,310,130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];

    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    sumArray(things, 6);

    sumArray(pd, 3);
}

template <typename T>
void sumArray (const T arr[], const int n)
{
    using namespace std;
    T sum = arr[0];
    cout << "Template A Sum: ";

    for (int i = 1; i < n; i++)
        sum += arr[i];

    cout << sum << endl;
}

template <typename T>
void sumArray (T * arr[], const int n)
{
    using namespace std;
    T sum = *arr[0];
    cout << "Template B Sum: ";
    for (int i = 1; i < n; i++)
        sum += *arr[i];

    cout << sum << endl;
}