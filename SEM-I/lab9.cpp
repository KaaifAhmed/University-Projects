#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int count7 (int n);
bool isFactor (int a, int b);
bool isDudeny (unsigned int a);
int freq (string sentence, char ch);

int main () {

    cout << "\nEXERCISE # 1\n\n";
    int x;
    cout << "Enter the number: ";
    cin >> x;

    cout << "7 is present in the number " << x << " " << count7(x) << " times.";


    cout << "\n\n\nEXERCISE # 2\n\n";
    cout << "Enter the numbers to check their factors.\n";
    
    for (size_t i = 0; i < 3; i++)
    {
        int a, b;
        cout << "Enter number 1: ";
        cin >> a;
        cout << "Enter number 2: ";
        cin >> b;
        cout << "\nThe number " << (isFactor(a, b)?"is":"is not") << " a factor.\n";
    }
    

    cout << "\n\n\nEXERCISE # 3\n\n";

    int count {0};
    for (size_t i = 0; count < 7; i++)
    {
        if (isDudeny(i))
        {
            cout << "\n" << i;
            count++;
        }
        
    }


    cout << "\n\n\nEXERCISE # 4\n\n";

    char ch;
    string sentence;

    cout << "Enter the sentence: ";
    getline(cin, sentence);
    cout << "\nEnter the character to look for: ";
    cin >> ch;

    cout << "\n\nThe character " << ch << " has been found " << (freq(sentence, ch)) << " times.";
    


}

// Finds the number of times '7' is repeated in a number
int count7 (int n) {
    int count = 0;
    int a;

    while (n != 0)
    {
        a = n%10;
        n = n/10;
        
        if (a == 7)
        {
            count++;
        }
        
    }
    
    return count;
}

// Checks if the second is the factor of the first
bool isFactor (int a, int b) {
    return ((b%a)==0);
}


// Checks if the entered number is a Dudeny number
bool isDudeny (unsigned int a) {
    if ((cbrt(a) - (int) cbrt(a)) == 0.00)
    {
        int c = 0;
        int d = cbrt(a);

        while (a != 0)
        {
            c += a%10;
            a /= 10;
        }
        
        return (c == d);
    } else {
        return false;
    }
    
}


// Finds the frequency of a character in a string

int freq (string sentence, char ch) {
    int count {0};

    // cout << "\n..." << sentence.length() << endl;

    for (size_t i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ch)
        {
            count++;
        }
        
    }

    return count;
    
}