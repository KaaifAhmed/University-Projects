#include <iostream>
using namespace std;

int fib(int n);
int countZeros(int n);
int fact(int n);
string removeX(string s);
float sumTo(int n);
void printNums(int n);
void swap(int *a, int *b);
int countGreaterThan(int *arr, int size, int threshold);

int main()
{
    cout << "EXERCISE # 1\n\n";
    int arr1[5] = {4, 6, 2, 7, 3};
    int *arrPtr1 = &arr1[0];
    for (size_t i = 0; i < 5; i++)
    {
        cout << *arrPtr1 << " ";
        arrPtr1++;
    }
    int a{9}, b{7};
    cout << "\na: " << a << ", b: " << b;
    swap(&a, &b);
    cout << "\na: " << a << ", b: " << b;
    cout << "\nEnter the threshold value: ";
    int thresh1;
    cin >> thresh1;
    cout << "\n"
         << countGreaterThan(arr1, 5, thresh1) << " values greater than " << thresh1 << endl;

    cout << "\n\nEXERCISE # 2\n\n";
    cout << "Enter the number for factorial: ";
    int num2;
    cin >> num2;
    cout << "The factorial of " << num2 << " is " << fact(num2) << endl;

    cout << "\n\nEXERCISE # 3\n\n";
    cout << "Enter the the fibonacci index: ";
    int ind3;
    cin >> ind3;
    cout << "The fibonacci number at index " << ind3 << " is " << fib(ind3) << endl;

    cout << "\n\nEXERCISE # 4\n\n";
    cout << "Enter the number: ";
    int num4;
    cin >> num4;
    cout << "The sum upto " << num4 << " is " << sumTo(num4) << endl;

    cout << "\n\nEXERCISE # 5\n\n";
    cout << "Enter the number: ";
    int num5;
    cin >> num5;
    cout << "There are " << countZeros(num5) << " zeros in " << num5 << endl;

    cout << "\n\nEXERCISE # 6\n\n";
    cout << "Enter the number: ";
    int num6;
    cin >> num6;
    printNums(num6);

    cout << "\n\nEXERCISE # 6\n\n";
    cout << "Enter the string: ";
    string str;
    cin >> str;
    cout << "\nString without \'x\': " << removeX(str);

}

int countGreaterThan(int *arr, int size, int threshold)
{
    int greater = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > threshold)
        {
            greater++;
        }
    }
    return greater;
}

void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

string removeX(string s)
{
    if (s[0] == '\0')
    {
        return "";
    }

    if (s[0] == 'x' || s[0] == 'X')
    {
        s.erase(0, 1);
        return removeX(s);

    } else {
        char ch = s[0];
        s.erase(0, 1);
        return ch + removeX(s);
    }
}

void printNums(int n)
{
    string names[] = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
    if (n < 10)
    {
        cout << names[n];
        return;
    }
    printNums(n / 10);
    printNums(n % 10);
    return;
}

float sumTo(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }

    return (1.0 / n) + sumTo(n - 1);
}

int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int countZeros(int n)
{
    if (n < 10)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return countZeros(n % 10) + countZeros(n / 10);
}
