#include <iostream>

using namespace std;

typedef struct complex
{
    int real;
    int imaginary;
} c;

int main()
{
    c num1;
    c num2;

    cout << "Enter the real parts of the numbers: ";
    cin >> num1.real >> num2.real;

    cout << "Enter the imaginary parts of the number: ";
    cin >> num1.imaginary >> num2.imaginary;

    int sum_real = num1.real + num2.real;
    int sum_ima = num1.imaginary + num2.imaginary;

    cout << "The final sum is: " << sum_real << " + " << sum_ima << "i";
    return 0;
}