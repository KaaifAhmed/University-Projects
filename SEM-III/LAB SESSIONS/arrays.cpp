#include <iostream>
using namespace std;

int main() {
    int LA[7] = {11, 22, 33, 38, 44, 55};
    int n = 6;

    cout << "TRAVERSING THE ARRAY\n";
    int i = 0;
    while (i < n) { 
        cout << LA[i] << " ";
        i++;
    }    
    
    cout << "\n\nINSERTING ELEMENT TO THE ARRAY";
    cout << "\nBefore insertion:\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        LA[n] = 66;
    }
    n++;
    
    cout << "\nAfter insertion:\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    cout << "\n\nDELETING ELEMENT FROM THE ARRAY";
    int item = 3;
    cout << "\nBefore deletion:\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    for (int i = item; i < n; i++)
    {
        LA[i] = LA[i+1];
    }
    n--;
    
    cout << "\nAfter deletion:\t\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    cout << "\n\nSEARCHING THE ARRAY\n";
    int j = 0, target = 44;
    cout << "Array:\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }
    cout << endl;
    while (j < n) { 
        if (LA[j] == target)
        {
            cout << target << " found at index # " << j << ".";
        }
        
        j++;
    }

    cout << "\n\nUPDATING THE ARRAY";
    int k = 3, new_val = 30;
    cout << "\nBefore update:\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    LA[k-1] = new_val;
    cout << "\nAfter update:\t"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    cout << "\n\nDISPLAYING THE ARRAY\n"; 
    for (int i = 0; i < n; i++) {
        cout << LA[i] << " ";
    }

    return 0;
}