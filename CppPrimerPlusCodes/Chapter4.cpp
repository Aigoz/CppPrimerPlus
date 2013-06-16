#include "Chapter4.h"
#include "Headers.h"

using namespace std;

void Exercise04_01()
{
	//	string fName;
	char fName[40];
	char lName[40];
	char grade;
	unsigned int age = 0;

	cout << "What is your first name? ";
	// 	getline(cin, fName);
	// 	cin.get();
	cin.getline(fName, 40);
	cout << "What is your last name? ";
	cin.getline(lName, 40);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	cout << "What is your age? ";
	cin >> age;

	cout << "Name:	" << lName << ", " << fName <<endl;
	cout << "Grade:	" << (char)(grade + 1) <<endl;
	cout <<	"Age:	" << age << endl;
}

void Exercise04_02()
{
	string name;
	string dessert;

	cout << "Enter your name: \n";
	getline(cin, name);
	cout << "Enter your favorite dessert: " << endl;
	getline(cin, dessert);
	cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
}

void Exercise04_03()
{
	char firstName[NameSize];
	char lastName[NameSize];
	char fullName[2*NameSize + 2];

	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;

	strcpy_s(fullName, NameSize, firstName);
	strcat_s(fullName, NameSize, ",");
	strncat(fullName, lastName, NameSize);

	cout << "Here's the information in a single string: " << fullName << endl;
}

void Exercise04_04()
{
	string firstName;
	string lastName;
	string fullName;

	cout << "This is Chapter 4, Exercise 04." << endl;

	cout << "Enter your first name: ";
	getline(cin, firstName);
	cout << "Enter your last name: ";
	getline(cin, lastName);

	fullName = firstName + ", " + lastName;

	cout << "Here's the information in a single string: " << fullName << endl;
}

struct CandyBar {
	//string	candyBrand;			// an error will be reported on vc6.0 when snack was initialzing using "string" type.
	char	candyBrand[40];
	int		candyCalorie;
	double	candyWeight;
};

void Exercise04_05()
{
	CandyBar snack = 
	{
		"Mocha Munch",
		350,
		2.3
	};

	cout << "snack brand: " << snack.candyBrand << "\nsnack weight: "
		<< snack.candyWeight << "\nsnack calorie: " << snack.candyCalorie<<endl;
}

void Exercise04_06()
{
	struct CandyBar snacks[3] = 
	{
		{"Mocha1", 111, 1.1},
		{"Mocha2", 222, 2.2},
		{"Mocha3", 333, 3.3}
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "Mocha" << i+1 << ":	" << snacks[i].candyBrand << "	" 
			<< snacks[i].candyWeight << "	" << snacks[i].candyCalorie << endl;
	}
}

struct PizzaCompany
{
	string companyName;
	double pizzaDiameter;
	double pizzaWeight;
};

void Exercise04_07()
{
	struct PizzaCompany yourCompany;

	cout << "Record your pizza company now!\nInput your company name: ";
	getline(cin, yourCompany.companyName);
	cout << "Input your company's pizza diameter: ";
	cin >> yourCompany.pizzaDiameter;
	cout << "Input your compyan's pizza weight: ";
	cin >> yourCompany.pizzaWeight;

	cout << "\n\nOK! Now, please check your company information.\nCompany Name: "
		<< yourCompany.companyName << "\nPizza Diameter: " << yourCompany.pizzaDiameter
		<< "\nPizza Weight: " << yourCompany.pizzaWeight <<endl;
}

void Exercise04_08()
{
	PizzaCompany* yourCompany_ptr = new PizzaCompany;

	cout << "Record your pizza company now!\nInput your company's pizza diameter: ";
	cin >> yourCompany_ptr->pizzaDiameter;
	getchar();
	cout << "Input your company name: ";
	getline(cin, yourCompany_ptr->companyName);
	cout << "Input your compyan's pizza weight: ";
	cin >> yourCompany_ptr->pizzaWeight;

	cout << "\n\nOK! Now, please check your company information.\nCompany Name: "
		<< yourCompany_ptr->companyName << "\nPizza Diameter: " << yourCompany_ptr->pizzaDiameter
		<< "\nPizza Weight: " << yourCompany_ptr->pizzaWeight <<endl;

	delete yourCompany_ptr;		// Do not forget delete.
}

void Exercise04_09()
{
	CandyBar* yourCandy = new CandyBar [3];
	strcpy_s(yourCandy[0].candyBrand, 40, "Mocha1");
	yourCandy[0].candyCalorie = 111;
	yourCandy[0].candyWeight = 1.1;

	strcpy_s((yourCandy+1)->candyBrand, 40, "Mocha2");
	yourCandy[1].candyCalorie = 222;
	yourCandy[1].candyWeight = 2.2;

	strcpy_s((*(yourCandy+2)).candyBrand, 40, "Mocha3");
	yourCandy[2].candyCalorie = 333;
	(yourCandy+2)->candyWeight = 3.3;

	for (int i = 0; i < 3; i++)
	{
		cout << "Mocha" << i+1 << ":	" << yourCandy[i].candyBrand << "	" 
			<< yourCandy[i].candyWeight << "	" << yourCandy[i].candyCalorie << endl;
	}

	delete [] yourCandy;		// Do not forget delete. I forgot at the first time.
}