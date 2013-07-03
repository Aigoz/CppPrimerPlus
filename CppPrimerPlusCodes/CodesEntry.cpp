#include "CodesEntry.h"
#include "Headers.h"
#include "Chapter4.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "Chapter7.h"
#include "Chapter8.h"

using namespace std;

void showChapter4CodesMenu();
void showChapter5CodesMenu();
void showChapter6CodesMenu();
void showChapter7CodesMenu();
void showChapter8CodesMenu();

int chooseFunction();

typedef void (*cFuntionsPtr)();
cFuntionsPtr getCFunctionEntryPtr(int theChapter, int functionsId);

/*  GLOBAL VARIABLE */
//  function pointer
cFuntionsPtr functionPtr;
int theFunctionId;


/****************************************
               Definitions 
****************************************/
int letItGo0()
{
    cout << "There are just 17 chapters.\n";
    return 0;
}

int letItGo4() 
{
    showChapter4CodesMenu();
	while (theFunctionId = chooseFunction())
    {
        functionPtr = getCFunctionEntryPtr(4, theFunctionId);
        if (functionPtr)
        {
            (*functionPtr)();
        }
        else
            cout << "There is no codes at id " << theFunctionId <<". Repick one\n";
    }

	return 0;
}

int letItGo5()
{
    showChapter5CodesMenu();
    while (theFunctionId = chooseFunction())
    {
        functionPtr = getCFunctionEntryPtr(5, theFunctionId);
        if (functionPtr)
        {
            (*functionPtr)();
        }
        else
            cout << "There is no codes at id " << theFunctionId <<". Repick one\n";
    }

	return 0;
}

int letItGo6()
{
    showChapter6CodesMenu();
    while (theFunctionId = chooseFunction())
    {
        functionPtr = getCFunctionEntryPtr(6, theFunctionId);
        if (functionPtr)
        {
            (*functionPtr)();
        }
        else
            cout << "There is no codes at id " << theFunctionId <<". Repick one\n";
    }

	return 0;
}

int letItGo7()
{
    showChapter7CodesMenu();
    while (theFunctionId = chooseFunction())
    {
        functionPtr = getCFunctionEntryPtr(7, theFunctionId);
        if (functionPtr)
        {
            (*functionPtr)();
        }
        else
            cout << "There is no codes at id " << theFunctionId <<". Repick one\n";
    }

	return 0;
}

int letItGo8()
{
    showChapter8CodesMenu();
    while (theFunctionId = chooseFunction())
    {
        functionPtr = getCFunctionEntryPtr(8, theFunctionId);
        if (functionPtr)
        {
            (*functionPtr)();
        }
        else
            cout << "There is no codes at id " << theFunctionId <<". Repick one\n";
    }
    return 0;
}

//******************************************************************//

void showChapter4CodesMenu()
{
    cout << "THis is codes of Chapter 4\n"
        "Enter the id number to pick up the function to run.\n"
        "1. Exercise 01         2. Exercise 02\n"
        "3. Exercise 03         4. Exercise 04\n"
        "5. Exercise 05         6. Exercise 06\n"
        "7. Exercise 07         8. Exercise 08\n"
        "9. Exercise 09         0. Exit\n";
}

void showChapter5CodesMenu()
{
    cout << "THis is codes of Chapter 5\n"
        "Enter the id number to pick up the function to run.\n"
        "1. Exercise 01         2. Exercise 02\n"
        "3. Exercise 03         4. Exercise 04\n"
        "5. Exercise 05         6. Exercise 06\n"
        "7. Exercise 07         8. Exercise 08\n"
        "9. Exercise 09         0. Exit\n";
}

void showChapter6CodesMenu()
{
    cout << "THis is codes of Chapter 6\n"
        "Enter the id number to pick up the function to run.\n"
        "1. Exercise 01         2. Exercise 02\n"
        "3. Exercise 03         4. Exercise 04\n"
        "5. Exercise 05         6. Exercise 06\n"
        "7. Exercise 07         8. Exercise 08\n"
        "9. Exercise 09         10.Codes    02\n"
        "11.Codes    14         12.Codes    15\n"
        "0. Exit\n";
}

void showChapter7CodesMenu()
{
    cout << "THis is codes of Chapter 7\n"
        "Enter the id number to pick up the function to run.\n"
        "1. Exercise 01         2. Exercise 02\n"
        "3. Exercise 03         4. Exercise 04\n"
        "5. Exercise 05         6. Exercise 06\n"
        "7. Exercise 07         8. Exercise 08\n"
        "9. Exercise 09         10.Codes    16\n"
        "11.Draw - functionPointer()\n"
        "0. Exit\n";
}

void showChapter8CodesMenu()
{
    cout << "THis is codes of Chapter 8\n"
        "Enter the id number to pick up the function to run.\n"
        "1. Exercise 01         2. Exercise 02\n"
        "3. Exercise 03         4. Exercise 04\n"
        "5. Exercise 05         6. Exercise 06\n"
        "7. Exercise 07         0. Exit\n";
}

int chooseFunction()
{
    int theFunction;
    cout << "\nEnter a function: ";

    while (!(cin >> theFunction))
    {
        cout << "\nPlease enter the function id: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    //clear the buffer
    while (cin.get() != '\n');

    return theFunction;
}

cFuntionsPtr getCFunctionEntryPtr(int theChapter, int functionsId)
{
    if (theChapter < 0 || theChapter > CHAPTER_NUM || 
        functionsId < 0 || functionsId > MAX_CODES_NUM)
        return NULL;

    cFuntionsPtr funcEntries[MAX_CODES_NUM + 1] = {NULL};
    if (4 == theChapter)
    {
        funcEntries[1] = Exercise04_01;
        funcEntries[2] = Exercise04_02;
        funcEntries[3] = Exercise04_03;
        funcEntries[4] = Exercise04_04;
        funcEntries[5] = Exercise04_05;
        funcEntries[6] = Exercise04_06;
        funcEntries[7] = Exercise04_07;
        funcEntries[8] = Exercise04_08;
        funcEntries[9] = Exercise04_09;
    }
    else if (5 == theChapter)
    {
        funcEntries[1] = Exercise05_01;
        funcEntries[2] = Exercise05_02;
        funcEntries[3] = Exercise05_03;
        funcEntries[4] = Exercise05_04;
        funcEntries[5] = Exercise05_05;
        funcEntries[6] = Exercise05_06;
        funcEntries[7] = Exercise05_07;
        funcEntries[8] = Exercise05_08;
        funcEntries[9] = Exercise05_09;
    }
    else if (6 == theChapter)
    {
        funcEntries[1] = exercise06_01;
        funcEntries[2] = exercise06_02;
        funcEntries[3] = exercise06_03;
        funcEntries[4] = exercise06_04;
        funcEntries[5] = exercise06_05;
        funcEntries[6] = exercise06_06;
        funcEntries[7] = exercise06_07;
        funcEntries[8] = exercise06_08;
        funcEntries[9] = exercise06_09;
        funcEntries[10]= codes06_02;
        funcEntries[11]= codes06_14;
        funcEntries[12]= codes06_15;
    }
    else if (7 == theChapter)
    {
        funcEntries[1] = exercise07_01;
        funcEntries[2] = exercise07_02;
        funcEntries[3] = exercise07_03;
        funcEntries[4] = exercise07_04;
        funcEntries[5] = exercise07_05;
        funcEntries[6] = exercise07_06;
        funcEntries[7] = exercise07_07;
        funcEntries[8] = exercise07_08;
        funcEntries[9] = exercise07_09;
        funcEntries[10]= codes07_16;
        funcEntries[11]= functionPointer;
    }
    else if (8 == theChapter)
    {
        funcEntries[1] = exercise08_01;
        funcEntries[2] = exercise08_02;
        funcEntries[3] = exercise08_03;
        funcEntries[4] = exercise08_04;
        funcEntries[5] = exercise08_05;
        funcEntries[6] = exercise08_06;
        funcEntries[7] = exercise08_07;
    }
    else
        return NULL;

    return funcEntries[functionsId];
}