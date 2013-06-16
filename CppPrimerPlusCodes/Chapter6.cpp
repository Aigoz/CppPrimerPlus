#include "Chapter6.h"
#include "Headers.h"

using namespace std;

void codes06_02()
{
	char ch;

	cout << "Type, and I shall repeat.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if ('\n' == ch)
			cout << ch;
		else
			cout << (char)(ch+1);
		cin.get(ch);
	}
}

void codes06_14()
{
	int golf[MAX];
	cout << "You must enter " << MAX << " rounds.\n";

	int i;
	for (i = 0; i < MAX; i++)
	{
		cout << "round #" << i+1 << ": ";
		while ( !(cin >> golf[i]) )
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "Please enter a number: ";
		}
	}

	double total = 0.0;
	for (i = 0; i < MAX; i++)
	{
		total += golf[i];
	}
	cout << total/MAX << " = average score " << MAX << "rounds\n";

}

void codes06_15()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// print information on screen using cout
	cout << fixed;	// print double like 0.01, not 1e-2
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	//outFile instead of cout
	outFile << fixed;	// print double like 0.01, not 1e-2
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;

	outFile.close();	// remember close
}