#include <iostream>
#include <array>

using namespace std;

void printArray (int arr[], int size) {
    cout << "\n";

    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << " ";
    }
    
    cout << "\n";
    
}

int main () {
    const int size = 5;
    int num[size] = {55, 66, 33, 22, 11};
    cout << "Unsorted array: ";
    printArray(num, size);

    for (size_t i = 0; i < (size-1); i++)
    {
        cout << "\nIteration: " << i;

        for (size_t j = 0; j < (size-i-1); j++)
        {
            if (num[j] > num[j+1])
            {
                num[j] += num[j+1];
                num[j+1] = num[j] - num[j+1];
                num[j] = num[j] - num[j+1];
            }

            printArray(num, size);
            
        }
        
    }

    cout << "\n\nSorted array: ";
    printArray(num, size);
    
}