/*
Chapter7::Chapter7(void)
{
}


Chapter7::~Chapter7(void)
{
}
*/

#include "Chapter7.h"
#include "Headers.h"

/*using namespace std;*/	//try to use namespace in each method, good habit.

/*************************************
*	Private method of Chapter7.cpp	 *
**************************************/
//codes07_16
void subDivide(char ar[], int low, int high, int level);


// recursion
void codes07_16()
{
	char ruler[LEN];
	int i;
	for (i = 1; i < LEN - 2; i++)
		ruler[i] = ' ';
	ruler[LEN - 1] = '\0';
	int max = LEN - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;

	for (i = 1; i <= DIVS; i++)
	{
		subDivide(ruler, min, max, i);
		std::cout << ruler	<< std::endl;
		//reset ruler
		for (int j = 1; j < LEN - 2; j++)
			ruler[j] = ' ';
	}
}

void subDivide(char ar[], int low, int high, int level)
{
	if (0 == level)
		return;
	else
	{
		int middle = (low + high) / 2;
		ar[middle] = '|';
		subDivide(ar, low, middle, level - 1);
		subDivide(ar, middle, high, level - 1);
	}
}

