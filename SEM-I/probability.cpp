#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void resetChoices (bool *arr, int size) {
    for (size_t i = 0; i < size; i++)
    {
        *(arr+i) = 0;
    }
}

void displayChoices (bool *arr, int size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << *(arr+i) << " ";
    }
    cout << endl;
}

int main () {
    srand(time(NULL));
    bool choices[3];
    resetChoices(choices, 3);
    
    int iterator = 10000000;
    int selection, removed, correctNoTrick {0}, correctTrick {0};
    for (size_t i = 0; i < iterator; i++)
    {
        choices[rand()%3] = true;
        selection = rand()%3;
        // displayChoices(choices, 3);
        // cout << selection << endl;

        if (choices[selection])
        {
            correctNoTrick++;
        }

        // cout << endl;

        resetChoices(choices, 3);

        choices[rand()%3] = true;
        selection = rand()%3;
        // displayChoices(choices, 3);
        // cout << selection << endl;

        for (size_t i = 0; i < 3; i++)
        {
            if ((i!=selection)&&!(choices[i]))
            {
                removed = i;
            }
            
        }

        selection = rand()%2;
        // displayChoices(choices, 3);
        // cout << removed << " " << selection << endl;

        if (removed==1)
        {
            selection = (selection?2:0);
        } else if (removed==0)
        {
            selection = (selection?2:1);            
        }
        
        
        

        if (choices[selection])
        {
            correctTrick++;
        }

        // cout << "\n\n";

        resetChoices(choices, 3);

        
        
    }

    float probTrick = static_cast<float> (correctTrick)/iterator;
    float probNoTrick = static_cast<float> (correctNoTrick)/iterator;

    cout << "Trick: " << (correctTrick*100)/iterator << "% No Trick: " << (correctNoTrick*100)/iterator << "%";
    // cout << "\nTrick: " << probTrick << " No Trick: " << probNoTrick;
        
}