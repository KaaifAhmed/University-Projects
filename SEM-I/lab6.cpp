#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main () {
    cout << "QUIZ NUMBER 2\n";
    int students, courses;
    float marks, total{0};
    cout << "Number of students: ";
    cin >> students;
    cout << "Number of courses: ";
    cin >> courses;

    for (size_t i = 1; i <= students; i++)
    {
        cout << "\nMarks for Student #" << i;
        for (size_t j = 1; j <= courses; j++)
        {
            cout << "\nEnter marks in course #" << j << ": ";
            cin >> marks;
            total += marks;
        }
        cout << "\nAverage marks of Student #" << i << " are: " << (total/courses);
        total = 0;
    }

    

    cout << "DICE ROLLING GAME";
    string pname1, pname2;
    int rounds, target;
    int ppts1{0}, ppts2{0};

    cout << "\nEnter name of player 1: ";
    cin >> pname1;
    cout << "Enter name of player 2: ";
    cin >> pname2;

    cout << "Enter the number of rounds: ";
    cin >> rounds;

    cout << "Enter the target number: ";
    cin >> target;

    srand(time(0));

    for (size_t i = 0; i < rounds; i++)
    {
        int a, b, c, d;

        a = 1 + rand()%6;
        b = 1 + rand()%6;
        c = 1 + rand()%6;
        d = 1 + rand()%6;

        if ((a+b) == target)
        {
            ppts1++;
        }
        cout << "\n\n" << pname1 << " rolled " << a << " and " << b << ". Total: " << a+b; 
        if ((c+d) == target)
        {
            ppts2++;
        }
        cout << "\n" << pname2 << " rolled " << c << " and " << d << ". Total: " << c+d;
        
        cout << "\nPlayer 1 Points: " << ppts1;
        cout << "\nPlayer 2 Points: " << ppts2;
    }

    if (ppts1 > ppts2)
    {
        cout << "\n" << pname1 << " wins!";
    } else if (ppts1 < ppts2)
    {
        cout << "\n" << pname2 << " wins!";
    } else
    {
        cout << "\nDraw!";
    }
    
    
    cout << "\n\n\nSELECTION SORTING";
    int num;
    cout << "\nEnter number of elements in the array: ";
    cin >> num;

    int arr[num];

    for (size_t i = 0; i < num; i++)
    {
        cout << "Enter element #" << i+1 << " ";
        cin >> arr[i];
    }

    cout << "The array: \" ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\"";

    for (size_t i = 0; i < (num-1); i++)
    {
        for (size_t j = i+1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            
        }
        
    }

    cout << "\nThe sorted array: \" ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\"";
    
    
}