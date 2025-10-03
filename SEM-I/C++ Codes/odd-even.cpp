#include <iostream>

using namespace std;

int main () {
    int num, evens{0}, i{1};
    cout << "Enter the number: ";
    cin >> num;

    while (num == 0)
    {
        int a = num % 10;
        if ((a%2) != 0)
        {
            evens += a*i;
            i *= 10;
            // cout << i;
        }
        num /= 10;
        
    }

    cout << "The even numbers from the number are: " << evens;
    
}