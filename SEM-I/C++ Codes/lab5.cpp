#include <iostream>
#include <array>
#include <ctime>
#include <iomanip>


using namespace std;

int main () {
    cout << "EXERCISE 1\n";
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int numbers[size];

    for (size_t i = 0; i < size; i++)
    {
        cout << "Enter value #" << i+1 << ": ";
        cin >> numbers[i];
    }

    int evenCount{0};

    for (size_t i = 0; i < size; i++)
    {
        if ((numbers[i] % 2) == 0)
        {
            evenCount++;
        }
        
    }

    cout << "The array has " << (static_cast <float> (evenCount)/size)*100 << "% even numbers.";

    
    cout << "\n\n\nEXERCISE NUMBER 2\n\n";

    array<char, 100> randChars;
    srand(time(NULL));

    for (size_t i = 0; i < randChars.size(); i++)
    {
        randChars[i] = 97 + rand()%26;
    }

    // for (size_t i = 0; i < randChars.size(); i++)
    // {
    //     cout << "Index # " << i << ": " << randChars[i] << endl;
    // }

    array<int, 26> charOcc;   // For some reasons it's not storing 0 as intial value, but garbage value. So, I'm initializing it to 0.

    for (size_t i = 0; i < charOcc.size(); i++)
    {
        charOcc[i] = 0;
    }
    

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        for (size_t i = 0; i < randChars.size(); i++)
        {
            if (randChars[i] == ch)
            {
                charOcc[ch-97]++;
            }
            
        }
        
    }

    for (size_t i = 0; i < charOcc.size(); i++)
    {
        cout << "The letter \"" << static_cast<char> (i+97) << "\" is found " << charOcc[i] << " times. " << endl;
    }
    
    
    cout << "\n\nEXERCISE NUMBER 3\n";

    array<int, 10> randGrades;

    for (size_t i = 0; i < randGrades.size(); i++)
    {
        randGrades[i] = rand()%101;
    }    

    array<int, 11> gradeDis;

    for (size_t i = 0; i < gradeDis.size(); i++)
    {
        gradeDis[i] = 0;
    }

    for (size_t i = 0; i < randGrades.size(); i++)
    {
        // cout << " Heya " << randGrades[i];
        if (randGrades[i] == 100)
        {
            gradeDis[10]++;
        } else if (randGrades[i] >= 90)
        {
            gradeDis[9]++;
        } else if (randGrades[i] >= 80)
        {
            gradeDis[8]++;
        } else if (randGrades[i] >= 70)
        {
            gradeDis[7]++;
        } else if (randGrades[i] >= 60)
        {
            gradeDis[6]++;
        } else if (randGrades[i] >= 50)
        {
            gradeDis[5]++;
        } else if (randGrades[i] >= 40)
        {
            gradeDis[4]++;
        } else if (randGrades[i] >= 30)
        {
            gradeDis[3]++;
        } else if (randGrades[i] >= 20)
        {
            gradeDis[2]++;
        } else if (randGrades[i] >= 10)
        {
            gradeDis[1]++;
        } else if (randGrades[i] >= 0)
        {
            gradeDis[0]++;
        }
    }
    
    cout << "\nGrade Distribution:";

    cout << "\n" << setw(7) << "0-9: ";
    for (size_t i = 0; i < gradeDis[0]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "10-19: ";
    for (size_t i = 0; i < gradeDis[1]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "20-29: ";
    for (size_t i = 0; i < gradeDis[2]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "30-39: ";
    for (size_t i = 0; i < gradeDis[3]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "40-49: ";
    for (size_t i = 0; i < gradeDis[4]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "50-59: ";
    for (size_t i = 0; i < gradeDis[5]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "60-69: ";
    for (size_t i = 0; i < gradeDis[6]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "70-79: ";
    for (size_t i = 0; i < gradeDis[7]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "80-89: ";
    for (size_t i = 0; i < gradeDis[8]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "90-99: ";
    for (size_t i = 0; i < gradeDis[9]; i++)
    {
        cout << "*";
    }
    cout << "\n" << setw(7) << "100: ";
    for (size_t i = 0; i < gradeDis[10]; i++)
    {
        cout << "*";
    }


    cout << "\n\n\nEXERCISE NUMBER 4\n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "| Feature               | Built-in Arrays     | Object Arrays               |\n";
    cout << "-----------------------------------------------------------------------------\n";
    
    cout << "| Size Awareness        | No size method      | Has .size() method.         |\n";
    cout << "| Assignment            | Cannot be assigned  | Supports assignment         |\n";
    cout << "| Standard Library      | No STL support      | Full STL support            |\n";
    cout << "| Size Definition       | Can use variable    | Requires constant           |\n";
    cout << "| Member Functions      | None                | Many like .fill(), .swap()  |\n";
    cout << "| Performance           | Slightly faster     | Minor overhead, safer       |\n";
    
    cout << "-----------------------------------------------------------------------------\n";
    
    
}