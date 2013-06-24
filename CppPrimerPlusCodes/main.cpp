/*
Main Entry
Creation Date:  2013-5-23 18:31
Update Record:  2013-6-14 9:42      1. Add Chapter4 Exercises From ALU PC.
				2013-6-14 10:00     2. Modify function letItGo4() Input Parameters. For my future update.
                2013-6-14 10:46     3. Add Chapter5.h and Chapter5.cpp, Map Chapter5 Exercises Codes From ALU PC.
                                    Also change C4 and C5 function name. Use strcpy_s and strcat_s instead of strcpy
                                    and strcat. (use a safer method)
							
*/

#include "CodesEntry.h"
#include "Headers.h"

using namespace std;

const int CHAPTER_NUM = 17;

void showChapterMenu();
int chooseChapter();
//function pointer   用到函数指针
// <C++ Primer> page 237&238 
typedef int (*functionPtr)();                 // use typedef is much more clearly
functionPtr chapterEntryPtr(int theChapter);    
//int (* chapterEntryPtr(int theChapter))();  //  NOTICE!! the place of function name

int main() {

//	letItGo7(NULL);
    int theChapter = 0;
    functionPtr codesEntryPtr;

    showChapterMenu();
    while (theChapter = chooseChapter())
    {
        codesEntryPtr = chapterEntryPtr(theChapter);
        if (codesEntryPtr)
        {
            (*codesEntryPtr)();
        }
        else
            cout << "There is no codes in Chapter " << theChapter << ".\n";
    }

	return 0;
}

void showChapterMenu()
{
    cout << "Choose one chapter:"
            "1. Chapter One         2. Chapter Two\n"
            "3. Chapter Three       4. Chapter Four\n"
            "5. Chapter Five        6. Chapter Six\n"
            "7. Chapter Seven       8. Chapter Eight\n"
            "0. Exit\n";
}

int chooseChapter()
{
    int theChapter;
    cout << "Your Chapter: ";

    while (!(cin >> theChapter))
    {
        cout << "Please enter the chapter id: ";
        cin.clear();
        while (cin.get() != '\n');
    }
    //clear the buffer
    while (cin.get() != '\n');

    return theChapter;
}

functionPtr chapterEntryPtr(int theChapter)
{
    int (*codesEntries[CHAPTER_NUM + 1])() = {
        letItGo0, NULL, NULL, NULL, letItGo4, letItGo5,
        letItGo6, letItGo7, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL,
        NULL, NULL
    };

    if (theChapter > 0 && theChapter <= 17)
        return *codesEntries[theChapter];
    else
        return *codesEntries[0];    // Entry 0 for the error message.
}