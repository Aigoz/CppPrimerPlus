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

//e1
double harmonicMean(double a, double b);

//e3
struct box 
{
    char maker[40];
    double height;
    double width;
    double length;
    double volume;
};
void showBoxMenbers(box a);
void setBoxVolume(box* a);

//e5
double factorialOf(int number);

//e6
int Fill_array(double a[], int length);
void Show_arrary(const double a[], int length);
void Reverse_array(double a[], int length);

//e8
const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
bool isBlankLine(char* str);
int getinfo(student pa[], int n);
void display1(student st);
void display2(student* ps);
void display3(const student pa[], int n);

//e9
double myAdd(double x, double y);
double calculate(double x, double y, double (* fp)(double x, double y));



/*************************************
*	codes, exercises and draws? 	 *
**************************************/
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


void exercise07_01()
{
    double a,b;

    std::cout << "Enter two integer: ";
    while (std::cin >> a >> b && (0 != a) && (0 != b))   //  (0 != a) && (0 != b) <=> a*b != 0
        std::cout << a << " and " << b << " harmonic mean is " 
            << harmonicMean(a, b) << std::endl;

    std::cout << "end\n";
}

double harmonicMean(double a, double b)
{
    return 2.0 * a * b / (a + b);
}


void exercise07_02()
{

}


void exercise07_03()
{
    box aBox = {
        "Aigoz",
        180,
        50,
        10,
        0
    };

    showBoxMenbers(aBox);
    setBoxVolume(&aBox);
    showBoxMenbers(aBox);
}

void showBoxMenbers(box a)
{
    std::cout << "maker: " << a.maker
        << "\nheight: " << a.height
        << "\nwidth: " << a.width
        << "\nlength: " << a.length
        << "\nvolume: " << a.volume << std::endl;
}

void setBoxVolume(box* a)
{
    a->volume = a->height * a->length * a->width;
}


void exercise07_04()
{

}


void exercise07_05()
{
    int num = 0;
    
    std::cout << "enter an integer: ";
    while (std::cin >> num)
    {
        std::cout << "Factorial of "<< num << " is "<< factorialOf(num) << ".\n";
        std::cout << "enter another integer.\n";
    }
}

double factorialOf(int number)
{
    double result = 0.0;
    if (number == 0)
        return 1.0;
    else
        return (double)(number * factorialOf(number - 1));
}


void exercise07_06()
{
    double myDouble[10];
    int length = 10;

    length = Fill_array(myDouble, length);
    Show_arrary(myDouble, length);

    Reverse_array(myDouble, length);
    Show_arrary(myDouble, length);

    Reverse_array(myDouble+1, length-2);
    Show_arrary(myDouble, length);
}

int Fill_array(double a[], int length)
{
    int count = 0;

    std::cout << "Now fill the array\n";

    for (int i = 0; i < length; i++)
    {
        std::cout << "Please enter a doulbe number to array[" << i << "]: ";
        if (!(std::cin >> a[i]))
        {
            std::cout << "Stop to enter\n";
            break;
        }
        count++;
    }

    std::cin.clear();
    while (std::cin.get() != '\n');

    return count;
}

void Show_arrary(const double a[], int length)
{
    std::cout << "Now display each number of this array.\n";
    for (int i = 0; i < length; i++)
        std::cout << "array[" << i << "]: " << a[i] << "\n";
}

void Reverse_array(double a[], int length)
{
    double temp;
    std::cout << "It's time to reverse the array.\n";
    for (int i = 0; i < length/2; i++)
    {
        temp = a[i];
        a[i] = a[length - i - 1];
        a[length - i - 1] = temp;
    }

    std::cout << "done!\n";
}


void exercise07_07()
{

}


void exercise07_08()
{
    using namespace std;

    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n');

    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu,class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete [] ptr_stu;
    cout << "Done!\n";
}

//blank line return true, otherwise return flase.
bool isBlankLine(char* str)
{
    while (*str)    // if str has no character, it will skip this and return true.
    {
        if (*str != ' ' && *str != '\n')
            return false;
        str++;
    }

    return true;
}

int getinfo(student pa[], int n)
{
    using namespace std;
    cout << "Now fill the students! \n";
    char tempStr[SLEN];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student[" << i << "]'s name: ";
        if (cin.getline(tempStr, SLEN) && !isBlankLine(tempStr))
        {
            strcpy_s(pa[i].fullname, tempStr);

            cout << "Enter student[" << i << "]'s hobby: ";
            cin >> tempStr;
            strcpy_s(pa[i].hobby, tempStr);

            cout << "Enter student[" << i << "]'s ooplevel(int): ";
            while (!(cin >> pa[i].ooplevel))
            {
                cout << "Enter an integer: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            while (cin.get() != '\n');
        }
        else
            break;

        count++;
    }

    return count;
}

void display1(student st)
{
    using namespace std;
    cout << "Display a student using display1.\n";
    
    cout << "Full name: " << st.fullname <<
        "\nHobby: " << st.hobby <<
        "\nooplevel: " << st.ooplevel << endl;
}

void display2(student* ps)
{
    using namespace std;
    cout << "Display a student using display2.\n";

    cout << "Full name: " << ps->fullname <<
        "\nHobby: " << ps->hobby <<
        "\nooplevel: " << ps->ooplevel << endl;
}       

void display3(const student pa[], int n)
{
    using namespace std;
    cout << "Display all students using display3.\n";

    if (0 == n)
    {
        cout << "There is no student." <<endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Student[" << i << "]'s info.\n"
            << "\tFull name: " << pa[i].fullname
            << "\n\tHobby: " << pa[i].hobby
            << "\n\tooplevel: " << pa[i].ooplevel << endl;
    }
}


void exercise07_09()
{// 关于第九题的拓展，可以见main.cpp
    using namespace std;
    double a, b, sum;

    cout << "Enter two double number, will quit when not double number was entered: ";
    while (cin >> a >> b)
    {
        sum = calculate(a, b, myAdd);
        cout << "Sum = " << sum <<endl;
        cout << "Two doule number: ";
    }
}

double myAdd(double x, double y)
{
    return x + y;
}

double calculate(double x, double y, double (* fp)(double x, double y))
{
    return (* fp)(x,y);
}


/************************************************************************/
/* function pointer                                                     */
/************************************************************************/
int fpSum(int a, int b)
{
    return (a + b);
}

void functionPointer()
{
    // There is an example of function pointer in main.cpp(function return function pointer)
    int (* fp1)(int a, int b);
    
    typedef int (* fpSumT)(int a, int b);
    fpSumT fp2;

    int a = 1;
    int b = 2;
    int result1 = 0;
    int result2 = 0;

    fp1 = fpSum;
    fp2 = fpSum;

    result1 = (*fp1)(a, b);
    result2 = (*fp2)(a, b);

    std::cout << "fp1 return value: " << result1 << std::endl;
    std::cout << "fp2 return value: " << result2 << std::endl;
}