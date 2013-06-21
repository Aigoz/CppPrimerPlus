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

void exercise06_01()
{
	// use cctype
	char ch;

	while (cin.get(ch) && '@' != ch)
	{
		if (!isdigit(ch))
		{
			if (islower(ch))
				ch = toupper(ch);
			else if (isupper(ch))
				ch = tolower(ch);
			cout << ch;
		}
	}
}

void exercise06_02()
{
	double myDouble[10];
	double mySum = 0.0;
	int gtAverageCount = 0;
	double averageDouble = 0;
	int myCount = 0;

	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (cin >> myDouble[i])
		{
			mySum += myDouble[i];
			myCount++;
		}
		else
			break;
	}

	averageDouble = mySum/myCount;
	while(--myCount)
	{
		if (myDouble[myCount] > averageDouble)
		{
			gtAverageCount++;
		}
	}
	cout << "average = " << averageDouble << "; gtAve = " << gtAverageCount << ".\n";
}

void showMenu_e0603()
{
	cout << "Please enter one of the following choices, I will tell you my favourite: \n"
		"c) carnivore		p) pianist\n"
		"t) tree			g) game\n";
}

void exercise06_03()
{
	char theChoice;

	showMenu_e0603();
	cin >> theChoice;
	while (theChoice != 'c' && theChoice != 'p' && theChoice != 't' && theChoice != 'g')
	{
		cout << "Please enter a character of c,p,t,g: ";
		cin >> theChoice;
	}

	switch (theChoice)
	{
	case 'c':	cout << "Maybe tiger? However, tiger is carnivore at least.\n";
		break;
	case 'p':	cout << "Beethoven. Pathetique.\n";
		break;
	case 't':	cout << "A maple is a tree.\n";
		break;
	case 'g':	cout << "WOW, CS, Dota, War3. Lots.\n";
		break;
	default:	cout << "How did you get here? I must missed something.\n";
		break;
	}
}

struct bop {
	char fullname[STR_SIZE];
	char title[STR_SIZE];
	char bopname[STR_SIZE];
	int preference;	//	0 = fullname, 1 = title, 2 = bopname; 能用常量代替硬编码。
};

void showMenu_e0604()
{
	cout << "Benevolent Order of Programmers Report\n"
		"a. display by name		b. display by title\n"
		"c. display by bopname	d. display by preference\n"
		"q. quit\n";
}

void displayByPreference_e0604(bop theBop)
{
	switch (theBop.preference)
	{
	case 0:	cout << theBop.fullname << endl; break;
	case 1: cout << theBop.title << endl; break;
	case 2: cout << theBop.bopname << endl; break;
	default: cout << "There is something wrong about the preference of "
				 << theBop.fullname << ".\n"; break;
	}
}

void exercise06_04()
{
	char theChoise;
	bop bops[5] = {
		{"Wimp Macho", "CEO", "mAc", 0},
		{"Raki Rhodes", "Junior Programmer", "Ros", 1},
		{"Celia Laiter", "Senior Programmer", "MIPS", 2},
		{"Hoppy Hipman", "Analyst Trainee", "HOP", 1},
		{"Pat Hand", "CTO", "LOOPY", 2}
	};
	int i = 0;

	showMenu_e0604();				// consider spaces, tabs, enters.
	while (cin >> theChoise)		// cin>>theChoise is better than cin.get(theChoise)
	{
		if (theChoise != 'a' && theChoise != 'b' && 
			theChoise != 'c' && theChoise != 'd' && theChoise != 'q')
		{
			cout << "Be nice please. Enter a or b or c or d or q.\n";
			continue;
		}

		if ('q' == theChoise)
		{
			cout << "Bye!\n";
			break;
		}

		switch(theChoise)
		{
		case 'a':
			{
				for (i = 0; i < 5; i++)
					cout << bops[i].fullname << endl;
				break;
			}
		case 'b':
			{
				for (i = 0; i < 5; i++)
					cout << bops[i].title << endl;
				break;
			}
		case 'c':
			{
				for (i = 0; i < 5; i++)
					cout << bops[i].bopname << endl;
				break;
			}
		case 'd':
			{
				for (i = 0; i < 5; i++)
					displayByPreference_e0604(bops[i]);
				break;
			}
		default:	cout << "Get out!\n"; break;
		}
	}
}

void exercise06_05()
{
	double income;
	double tax;

	cout << "enter an income: ";
	while (cin >> income && income >= 0)
	{
		if (income > 35000)
			tax = (income - 35000) * 0.2 + 20000 * 0.15 + 10000 * 0.1;
		else if (income > 15000)
			tax = (income - 15000) * 0.15 + 10000 * 0.1;
		else if (income > 5000)
			tax = (income - 5000) * 0.1;
		else
			tax = 0;

		cout << "tax: " << tax << " tvarps.\n";
		cout << "enter another income: ";
	}
}

struct patron {
	string nameStr;
	double money;
};

void exercise06_06()
{
	int i = 0;
	int patronNumber;
	bool isGrandPatronsNone = true;
	bool isPatronsNone = true;

	cout << "Enter the number of patrons: ";
	while (!(cin >> patronNumber))
	{	//	Enter patron number, and make sure it is a positive int.
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Please enter a positive integer: ";
	}

	//new and init patrons
	patron* patrons = new patron [patronNumber];
	for (i = 0; i < patronNumber; i++)
	{
		// clear the buffer
		while (cin.get() != '\n')
			continue;

		cout << "Patron #" << i+1 << "\n" 
			"Name: ";
		getline(cin, patrons[i].nameStr);
		cout << "Money: ";
		cin >> patrons[i].money;
	}

	//show grand patrons
	cout << "\nGrand Patrons:\n";
	for (i = 0; i < patronNumber; i++)
	{
		if (patrons[i].money > 10000)
		{
			isGrandPatronsNone = false;
			cout << patrons[i].nameStr << "\t\t" << patrons[i].money << endl;
		}
		else
			isPatronsNone = false;
	}
	if (isGrandPatronsNone)
		cout << "None\n";

	//show normal patrons
	cout << "Patrons:\n";
	if (isPatronsNone)
		cout << "None\n";
	else 
		for (i = 0; i < patronNumber; i++)
			if (patrons[i].money < 10000)
				cout << patrons[i].nameStr << "\t\t" << patrons[i].money << endl;

	// end, then delete patrons.
	delete [] patrons;
}

void exercise06_07()
{
	char word[40];
	int countVowel = 0;
	int countConsonant = 0;
	int countOthers = 0;

	cout << "Enter words (q to quit):\n";
	while (cin >> word && strcmp(word, "q"))
	{
		if (!isalpha(word[0]))
			countOthers++;
		else if (word[0] == 'a' || word[0] == 'A' ||word[0] == 'e' || 
				word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || 
				word[0] == 'u' || word[0] == 'U' || word[0] == 'o' || 
				word[0] == 'O')
			countVowel++;
		else
			countConsonant++;
	}

	cout << countVowel << " words beginning with vowels\n"
		<< countConsonant << " words beginning with consonants\n"
		<< countOthers << " others\n";
}

void exercise06_08()
{
	ifstream inputFile;
	char ch;
	char useDefaultFile;
	string filename;
	int wordNumber = 0;

	cout << "Do you want to use the default file(Aigoz0608.txt)?\n"
		"Enter y/n : ";
	
	// Yes or No?
	while (cin.get(useDefaultFile))
	{
		// clear cin buffer
		while (cin.get() != '\n');
		
		if ('y' == useDefaultFile)
		{
			filename = "Aigoz0608.txt";
			break;
		}
		else if ('n' == useDefaultFile)
		{
			cout << "Then enter your filename: ";
			getline(cin, filename);
			break;
		}
		else
			cout << "you need to enter 'y' or 'n' to let me know which file is needed.\n"
			"Enter y/n(y=yes, n=no) :";
	}

	// clear cin buffer
	while (cin.get() != '\n');

	inputFile.open(filename);
	if (!inputFile.is_open())
	{
		cout << "Could not open the file \"" << filename << "\"" <<endl;
		cout << "Please check this file. Terminating.\n";
		exit(EXIT_FAILURE);		// <cstdlib>
	}

	while (inputFile.get(ch) && inputFile.good())
	{
		if ('\n' == ch)
			continue;
		wordNumber++;
	}

	if (inputFile.eof())
		cout << "End of file reched.\n";
	else if (inputFile.fail())
		cout << "Data mismatch" << endl;
	else 
		cout << "Unknow Issue.\n";

	if (wordNumber == 0)
		cout << "There is no word number." << endl;
	else 
		cout << filename << " file has " << wordNumber << " words\n";

	inputFile.close();		// remember close.
}

void exercise06_09()
{
	int i = 0;
	int patronNumber;
	bool isGrandPatronsNone = true;
	bool isPatronsNone = true;
	ifstream patronsInFile;

	// open patrons.txt
	patronsInFile.open("patrons.txt");
	if (!patronsInFile.is_open())
	{
		cout << "Could not open patrons.txt, please check this file!\n"
			"Terminating!\n";
		exit(EXIT_FAILURE);
	}

	while (!(patronsInFile >> patronNumber))
	{
		cout << "Please check first line of patrons.txt.\n"
			"It should be a positive integer.\n"
			"Terminating\n";
		exit(EXIT_FAILURE);
	}

	//new and init patrons
	patron* patrons = new patron [patronNumber];
	for (i = 0; i < patronNumber; i++)
	{
		// clear the Enter\n
		while (patronsInFile.get() != '\n')
			continue;

		getline(patronsInFile, patrons[i].nameStr);
		patronsInFile >> patrons[i].money;
	}

	//show grand patrons
	cout << "\nGrand Patrons:\n";
	for (i = 0; i < patronNumber; i++)
	{
		if (patrons[i].money > 10000)
		{
			isGrandPatronsNone = false;
			cout << patrons[i].nameStr << "\t\t" << patrons[i].money << endl;
		}
		else
			isPatronsNone = false;
	}
	if (isGrandPatronsNone)
		cout << "None\n";

	//show normal patrons
	cout << "Patrons:\n";
	if (isPatronsNone)
		cout << "None\n";
	else 
		for (i = 0; i < patronNumber; i++)
			if (patrons[i].money < 10000)
				cout << patrons[i].nameStr << "\t\t" << patrons[i].money << endl;

	// end, then delete patrons.
	delete [] patrons;
	patronsInFile.close();
}