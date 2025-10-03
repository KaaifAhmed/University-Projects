#include <iostream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

int a{5};

void printVector(vector<int> a)
{
    for (auto elem : a)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void moveRight(int *i, int *j, int arr[5][5], int right, bool *cont)
{
    if (*j == right)
    {
        *cont = false;
        return;
    }

    for (; *j <= right; (*j)++)
    {
        cout << arr[*i][*j] << " ";
        // cout << " i: " << *i << " j: " << *j << " ";
    }
    (*j)--;
    (*i)++;
    // cout << endl;
}

void moveLeft(int *i, int *j, int arr[5][5], int left, bool *cont)
{
    if (*j == left)
    {
        *cont = false;
        return;
    }

    for (; *j >= left; (*j)--)
    {
        cout << arr[*i][*j] << " ";
        // cout << " i: " << *i << " j: " << *j << " ";
    }
    (*j)++;
    (*i)--;
    // cout << endl;
}

void moveUp(int *i, int *j, int arr[5][5], int top, bool *cont)
{
    cout << " i: " << *i << " top: " << top << " ";

    if (*i == top)
    {
        *cont = false;
        return;
    }
    for (; *i >= top; (*i)--)
    {
        cout << arr[*i][*j] << " ";
        // cout << " i: " << *i << " j: " << *j << " ";
    }
    (*i)++;
    (*j)--;
    // cout << endl;
}

void moveDown(int *i, int *j, int arr[5][5], int bottom, bool *cont)
{
    if (*i == bottom)
    {
        *cont = false;
        return;
    }
    for (; *i <= bottom; (*i)++)
    {
        cout << arr[*i][*j] << " ";
        // cout << " i: " << *i << " j: " << *j << " ";
    }
    (*i)--;
    (*j)--;
    // cout << endl;
}

int main()
{
    // int hours, mins;
    // cout << "Enter the hours and the minutes: ";
    // cin >> hours >> mins;
    // string m = (hours > 12)?" P.M.":" A.M.";
    // hours = hours % 12;

    // cout << hours << ":" << mins << m;

    // const int rows = 5, cols = 5;
    // int arr[rows][cols] = {
    //     {12, 45, 23, 67, 89},
    //     {34, 56, 78, 90, 21},
    //     {11, 22, 33, 44, 55},
    //     {66, 77, 88, 99, 10},
    //     {9, 8, 7, 6, 5}
    // };

    // int sumP {0}, sumS {0};

    // for (size_t i = 0; i < rows; i++)
    // {
    //     sumP += arr[i][i];
    //     cout << i << "," << i <<endl;
    // }

    // for (size_t i = 0; i < rows; i++)
    // {
    //     sumS += arr[i][(cols-1)-i];
    //     cout << i << "," << (cols-1)-i <<endl;

    // }

    // cout << "Primary sum: " << sumP << " Secondary sum: " << sumS;

    // const int rows = 5, cols = 5;
    // int arr[rows][cols] = {
    //     {1, 2, 3, 4, 5},
    //     {16, 17, 18, 19, 6},
    //     {15, 24, 25, 20, 7},
    //     {14, 23, 22, 21, 8},
    //     {13, 12, 11, 10, 9},
    // };

    // for (size_t i = 0; i < rows; i++)
    // {
    //     if (i%2==0)
    //     {
    //         for (int j = 0; j < cols; j++)
    //         {
    //             cout << arr[i][j] << " ";
    //         }
            
    //     }

    //     else {
    //         for (int j = cols-1; j >= 0; j--)
    //         {
    //             cout << arr[i][j] << " ";

    //         }
            
    //     }
        
    // }
    

    // int top = 0, left = 0, bottom = rows-1, right = cols-1;

    // while (top <= bottom && left <= right)
    // {
    //     for (size_t i = left; i <= right; i++)
    //     {
    //         cout << arr[top][i] << " ";
    //     }
    //     top++;

    //     for (size_t i = top; i <= bottom; i++)
    //     {
    //         cout << arr[i][right] << " ";
    //     }
    //     right--;

    //     if (top <= bottom)
    //     {
    //         for (int i = right; i >= left; i--)
    //         {
    //             cout << arr[bottom][i] << " ";
    //         }
    //     bottom--;
            
    //     }

    //     if (left <= right)
    //     {
    //         for (int i = bottom; i >= top; i--)
    //         {
    //             cout << arr[i][left] << " ";
    //         }
    //     left++;
            
    //     }
        
    // }
    

    // cout << "\nEnter a number: ";
    // int n; cin >> n;
    // int m = n;
    // int o = 0;
    // vector<int> digits;
    // while (m != 0)
    // {
    //     digits.push_back(m%10);
    //     m /= 10;
    // }
    // // printVector(digits);

    // for (size_t i = 0; i < digits.size(); i++)
    // {
    //     o += pow(digits[i], digits.size());
    //     // cout << o;
    // }

    // cout << "Given number" << ((o==n)?" is ":" is not ") << "an armstrong number!";

    // cout << "\nEnter a number: ";
    // int n;
    // cin >> n;
    // int m = n;
    // int o = 0;

    // for (size_t i = 0; i < 10; i++)
    // {
    //     o = 0;
    //     while (m != 0)
    //     {
    //         o += pow(m % 10, 2);
    //         m /= 10;
    //     }
    //     if (o==1)
    //     {
    //         cout << "The number is Happy!";
    //         break;
    //     }
    //     m = o;
        
    // }

    // cout << "Given number" << ((o == n) ? " is " : " is not ") << "an armstrong number!";
}