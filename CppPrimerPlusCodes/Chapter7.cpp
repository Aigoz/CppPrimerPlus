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