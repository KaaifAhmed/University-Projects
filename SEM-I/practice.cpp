#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

int main () {
    // cout << "QUESTION 2.25\n";
    // cout << "Write a program that reads in three integers and determines and prints if the first two integers are factors of the second.\n\n";

    // int a, b, c;
    // cout << "Enter the three numbers: ";
    // cin >> a >> b >> c;

    // if ((c%a == 0) && (c%b == 0)) {
    //     cout << "Both numbers are the factors of " << c;
    // } else
    // {
    //     cout << "Both numbers are not the factors of " << c;
    // }


    // cout << "QUESTION 5.11\n";
    // cout << "Write an application that finds the smallest of several integers. Assume that the first value read specifies the number of values to input from the user.\n\n";

    // int numOfInts;
    // cout << "Enter the number of integers: ";
    // cin >> numOfInts;
    // int integers[numOfInts];
    // cout << "Enter the integers: ";
    // for (int i = 0; i < numOfInts; i++)
    // {
    //     cin >> integers[i];
    // }
    // int smallest{integers[0]};
    // for (int i = 1; i < numOfInts; i++)
    // {
    //     if (integers[i] < smallest)
    //     {
    //         smallest = integers[i];
    //     }
        
    // }
    
    // cout << "The smallest integer is: " << smallest;
    
    
    // cout << "QUESTION 5.13\n";
    // cout << "Write an application that calculates the factorials of 1 through 10.\n\n";

    // for (int i = 1; i <= 10; i++)
    // {
    //     unsigned long fact = 1;
    //     for (int j = 1; j <= i; j++)
    //     {
    //         fact = fact*j;
    //     }
    //     cout << "\nThe factorial of " << i << " is " << fact;
    // }
    

    // cout << "QUESTION 5.14\n";
    // cout << "Write an application that calculates compound interest for interest rates of 5%, 6%, 7%, 8%, 9%, and 10%.\n\n";

    // float principal;
    // int years;
    // cout << "Enter the principal amount: ";
    // cin >> principal;
    // cout << "Enter the number of years: ";
    // cin >> years;

    // float rate;

    // for (int h = 5; h <= 10; h++)
    // {
    //     rate = h/100.0;
        
    //     cout << "\n\nInterest rate = " << h << "%\n";
    //     cout << "Years" << setw(15) << "Total Amount" << endl;
    //     cout << setprecision(2) << fixed;
    //     for (int i = 1; i <= years; i++)
    //     {
    //         cout << setw(5) << i << setw(15) << (principal*pow((1+rate),i)) << endl;
    //     }
    
    // }


    cout << "QUESTION 5.14\n";
    cout << "Write an application that reads five numbers between 1 and 9. For each number that\'s read, your program should display a double row of the same number repeated as many times as the number read.\n\n";

    int num[5];
    cout << "Enter five numbers between 1 and 9: ";
    cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];

    for (int j = 0; j < 5; j++)
    {
        for (int h = 0; h < 2; h++)
        {
            cout << "\n";
            for (int i = 0; i < num[j]; i++)
            {
                cout << num[j];
            }
        }  
    } 
}