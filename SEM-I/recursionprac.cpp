#include <iostream>
#include <array>

using namespace std;

// Helpful Funcs

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive Functions
int Sum (int arr[], int n) {
    if (n==0)
    {
        return arr[n];
    }

    return arr[n] + Sum(arr, n-1);
    
}

int prod (int a, int b) {
    if (b == 1)
    {
        return a;
    }
    
    return a + prod (a, b-1);
    
}

int power (int a, int b) {
    if (b == 1)
    {
        return a;
    }
    
    
    return a * power (a, b-1);
    
}

int sumDigs (int n, int m=0) {
    if (n == 0)
    {
        return m;
    }
    return m + sumDigs(n/10, n%10);
    
}

string revStr (string str, int i) {
    int n = (str.length()-1);
    if (i == n/2)
    {
        swap(&(str[n-i]), &(str[i]));
        return str;
    }
    swap(&(str[n-i]), &(str[i]));
    str = revStr(str, ++i);
    return str;
    
}

bool isPalindrome (string str, int i) {
    string lol = str;
    int n = (str.length()-1);
    if (i == n/2)
    {
        swap(&(str[n-i]), &(str[i]));
        return true;
    }
    swap(&(str[n-i]), &(str[i]));
    str = revStr(str, ++i);
    return str==lol;
    
}

int main () {
    // int arr[] {5, 5, 5, 5, 5, 5};
    // cout << Sum(arr, 5);

    // cout << prod(4, 0);

    // cout << sumDigs(9146);

    // cout << power(4, 3);

    // cout << revStr("kaaif", 0);

    // cout << isPalindrome("accba", 0);

    struct Dumb {
        string name;
        int age;
        float gpa;
    };

    Dumb kaaif {"Bubs", .gpa=5.0};

    Dumb * kptr = &kaaif;

    cout << (*kptr).name;
    cout << kptr->name;
    cout << kptr->age;

}