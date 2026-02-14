#include <iostream>
#include <cmath>

using namespace std;

int factorial (int num);
bool isPandigital (int num);

int main () {
    // cout << "Enter the number: ";
    // int a;
    // cin >> a;
    // cout << boolalpha;
    // cout << isPandigital(a);
    
    cout << "Enter x and n: ";
    int x, n;
    cin >> x >> n;
    double sum = 1.0;
    

    for (size_t i = 1; i < n; i++)
    {
        sum += (pow(x, i))/factorial(i);
    }

    cout << "The sum is " << sum;
    

}

int factorial (int num) {
    int fact = 1;
    for (size_t j = num; j > 0; j--)
    {
        fact *= j;
    }
    return fact;
}

bool isPandigital (int num) {
    int n = 0;
    int m = num;
    while (m != 0)
    {
        m /= 10;
        n++;
    }

    int occ[n];

    for (size_t i = 0; i < n; i++)
    {
        occ[i] = 0;
    }

    while (num != 0)
    {
        int x = num%10;
        // cout << x;
        if (x > n)
        {
            return false;
        }
        
        num /= 10;
        occ[x-1]++;
    }
    
    
    for (size_t i = 0; i < n; i++)
    {
        if (occ[i] != 1)
        {
            return false;
        }
        
    }

    return true;
    
    
    
}