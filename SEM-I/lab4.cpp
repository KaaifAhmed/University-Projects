#include <iostream>

using namespace std;

int main () {
    cout << "EXERCISE ONE\n";
    int a;
    cout << "Enter the number: ";
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        int sum{1};
        cout << "1";
        for (int j = 2; j <= i; j++)
        {
            cout << " + " << j;
            sum += j;
        }
        cout << " = " << sum << "\n";
        
    }

    cout << "\n\nEXERCISE TWO\n";
    int isOddNum;
    cout << "Enter the number: ";
    cin >> isOddNum;
    bool isOdd = true;

    while (isOddNum != 0) {
        int x = isOddNum%10;
        if ((x%2)==0)
        {
            // cout << "\nThe entered number contains an even number";
            isOdd = false;
        }
        isOddNum /= 10;
    }
    cout << (isOdd?"\nYes, it only contains odd numbers!":"\nNo, it contains even number(s) as well!");
    
    cout << "\n\nEXERCISE THREE\n";

    char x;
    cout << "Enter the hexadecimal digit: ";
    cin >> x;
    int y = x-55;
    if (y>=10)
    {
        cout << y;
    } else {
        cout << x;
    }

    cout << "\n\nEXERCISE FOUR\n";
    cout << "Enter the number: ";
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= (a-i); j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = (i-1); j > 0; j--)
        {
            cout << j;
            
        }
        
        cout << "\n";
        
    }
    
}