#include "Chapter5.h"
#include "Headers.h"

using namespace std;

void Exercise05_01()
{
	int smallInt, largeInt, tmpInt;
	cout << "Input the first integer: ";
	cin >> smallInt;
	cout << "Input the second integer: ";
	cin >> largeInt;

	tmpInt = largeInt+smallInt;
	smallInt = smallInt <= largeInt ? smallInt : largeInt;
	largeInt = tmpInt - smallInt;

	for (tmpInt=0; largeInt>=smallInt; smallInt++)
	{
		tmpInt += smallInt;
	}

	cout << "sum integer: " << tmpInt << endl;
}

void Exercise05_03()
{
	double investmentDaphne = 100.0, investmentCleo = 100.0;
	int years = 0;
	//  
	//		第一种理解是本息什么时候超过
	// 	while (investmentDaphne >= investmentCleo)
	// 	{
	// 		investmentDaphne += 10.0;
	// 		investmentCleo += investmentCleo * 0.05;
	// 		years++;
	// 	}

	//		第二种理解是利息什么时候超过
	while (investmentCleo*0.05 <= 10)
	{
		investmentCleo += investmentCleo * 0.05;
		years++;
	}

	cout << years << endl;
}

void Exercise05_04()
{

}

struct Car 
{
	string manufacturer;		//manufacture		制造，生产
	int yearOfManufacturing;
};

void Exercise05_06()
{
	int carQuantity = 0;

	cout << "How many cars do you wish to catalog? ";
	cin >> carQuantity;
	//	getchar();			// cin >> (int)foo;   need a getchar() or cin.get() to get the Enter char.

	// this one is better than a single getchar() or cin.get(). Also get other redundant char(like space).
	while (cin.get() != '\n');		

	struct Car* cars= new Car [carQuantity];

	int i = 0;
	for (i=0; i<carQuantity; i++)
	{
		cout << "Car #" << i+1 << ": \nPlease enter the make: ";
		getline(cin, cars[i].manufacturer);
		cout << "Please enter the year made: ";
		cin >> cars[i].yearOfManufacturing;
		//cin.get();
		while (cin.get() != '\n');
	}

	cout << "Here is your collection:\n";
	for (i=0; i<carQuantity; i++)
	{
		cout << cars[i].yearOfManufacturing << " " << cars[i].manufacturer << endl;
	}

	delete [] cars;
}

void Exercise05_07()
{
	const int WORD_SIZE = 40;

	char word[WORD_SIZE];
	int count = 0, countStr = 0;
	string wordStr;

	cout << "Enter words (to stop, type the word done):" << endl;

	// 
	while ( (cin >> word) && strcmp(word, "done") )
	{
		++count;
	}
	cout << "You entered a total of " << count << " words." << endl;

	//important
	while (cin.get() != '\n');

	while ( (cin >> wordStr) && wordStr != "done")
	{
		++countStr;
	}
	cout << "You entered a total of " << countStr << " words.";
}

void Exercise05_08()
{
	Exercise05_07();
}

void Exercise05_09()
{
	int row = 0;
	int enterRow = 0;
	int dots = 0;
	int starts = 0;

	cout << "Enter number of rows: ";
	cin >> enterRow;

	for (row = 1; row <= enterRow; row++)
	{
		dots = enterRow - row;
		starts = row;

		while (dots--)
			cout << ".";
		while (starts--)
			cout << "*";
		cout << endl;
	}
}