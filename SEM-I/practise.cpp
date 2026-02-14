#include <iostream>
#include <stdlib.h>

using namespace std;

bool checkIfPrime(int n);

int findHighestPrime(int n);

int main()
{
    // float principal, rate, interest;
    // int duration;
    // cout << "Finding compound interest";
    // cout << "\nEnter the principal amount: ";
    // cin >> principal;
    // cout << "\nEnter the interest rate: ";
    // cin >> rate;
    // cout << "\nEnter the duration: ";
    // cin >> duration;

    // for (int i = 0; i < duration; i++)
    // {
    //     interest = principal*(rate/100);
    //     principal += interest;

    // cout << "!!Interest: " << interest << endl;
    // cout << "!!Total amount: " << principal;
    // }

    // cout << "Interest: " << interest << endl;
    // cout << "Total amount: " << principal;

    // cout << "\n\nFINDING PERFECT NUMBERS BETWEEN 1 TO N\n";
    // cout << "Enter the limit: ";
    // int n;
    // cin >> n;

    // for (size_t i = 1; i <= n; i++)
    // {
    //     int total = 0;

    //     for (size_t j = 1; j <= i/2; j++)
    //     {
    //         if (i%j==0)
    //         {
    //             total += j;
    //         }

    //     }

    //     if (total == i)
    //     {
    //         cout << i << "\n";
    //     }

    // }

    // cout << "\n\nCHECK IF A NUMBER CAN BE REPRESENTED AS SUM OF PRIME NUMBERS\n";

    // int lowestPrime{2}, number;
    // bool canBeRepresented = false;

    // cout << "Enter the number: ";
    // cin >> number;

    // for (size_t i = 2; i < number; i++)
    // {
    //     if (checkIfPrime(i) && checkIfPrime(number-i))
    //     {
    //         cout << i << " + " << number-i << " = " << number << endl;
    //         cout << "The number can be represented as a sum of two prime numbers";
    //         canBeRepresented = true;
    //         break;
    //     }
    // }
    
    // if (!canBeRepresented)
    // {
    //     cout << "\nThe number can't be represented as a sum of two prime numbers";
    // }

    int n,c;
    cout<<"Enter Fibonacci series of nth term: ";
    cin>>n;
    
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    
    for (int i=0;i<(n-2);i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    cout<<endl;
    
    

    
}

bool checkIfPrime(int n)
{
    bool isPrime = true;
    for (size_t j = 2; j <= n / 2; j++)
    {
        if (n % j == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int findHighestPrime(int n)
{
    int highest = 2;
    for (size_t i = 2; i < n; i++)
    {
        bool isPrime = checkIfPrime(i);

        if (isPrime)
        {
            highest = i;
        }
    }

    return highest;
}