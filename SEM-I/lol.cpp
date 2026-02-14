#include <iostream>
#include <random>
using namespace std;

int main()
{
    int noofstd = 8;
    int mcq = 10;
    char arr[noofstd][mcq];
    char key[mcq] = {'A', 'B', 'C', 'D', 'E', 'E', 'D', 'A', 'C', 'B'};

    srand(time(NULL));
    for (int i = 0; i < noofstd; i++)
    {
        for (int j = 0; j < mcq; j++)
        {

            arr[i][j] = 65 + rand() % 5;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int correct[noofstd];

    for (size_t i = 0; i < noofstd; i++)
    {
        correct[i] = 0;
    }
    for (int i = 0; i < noofstd; i++)
    {
        for (int j = 0; j < mcq; j++)
        {
            if (arr[i][j] == key[j])
            {
                correct[i]++;
            }
        }
    }

    cout << '\n';

    for (size_t i = 0; i < noofstd; i++)
    {
        cout << correct[i] << " ";
    }

    float total{0}, avg{0};

    for (size_t i = 0; i < noofstd; i++)
    {
        total += correct[i];
    }

    avg = total/noofstd;

    cout << "\nThe average is: " << avg;
    
    

    return 0;
}