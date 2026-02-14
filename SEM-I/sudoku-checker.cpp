#include <iostream>

using namespace std;

int occ[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

bool checkRow(int[9][9]);
bool checkCol(int[9][9]);
bool check3x3(int[9][9]);
bool validateOcc();
void resetOcc();
bool validateSudoku(int[9][9]);

int main()
{
    int corrSudoku[9][9] = {
        {4, 3, 5, 2, 6, 9, 7, 8, 1},
        {6, 8, 2, 5, 7, 1, 4, 9, 3},
        {1, 9, 7, 8, 3, 4, 5, 6, 2},
        {8, 2, 6, 1, 9, 5, 3, 4, 7},
        {3, 7, 4, 6, 8, 2, 9, 1, 5},
        {9, 5, 1, 7, 4, 3, 6, 2, 8},
        {5, 1, 9, 3, 2, 6, 8, 7, 4},
        {2, 4, 8, 9, 5, 7, 1, 3, 6},
        {7, 6, 3, 4, 1, 8, 2, 5, 9}};

    int wrong3Sudoku[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {2, 3, 4, 5, 6, 7, 8, 9, 1},
        {3, 4, 5, 6, 7, 8, 9, 1, 2},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {5, 6, 7, 8, 9, 1, 2, 3, 4},
        {6, 7, 8, 9, 1, 2, 3, 4, 5},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {8, 9, 1, 2, 3, 4, 5, 6, 7},
        {9, 1, 2, 3, 4, 5, 6, 7, 8}};

    int wrongRSudoku[9][9] = {
        {4, 3, 5, 6, 2, 9, 7, 8, 1},
        {6, 8, 2, 5, 7, 1, 4, 9, 3},
        {1, 9, 7, 8, 3, 4, 5, 6, 2},
        {8, 2, 6, 1, 9, 5, 3, 4, 7},
        {3, 7, 4, 6, 8, 2, 9, 1, 5},
        {9, 5, 1, 7, 4, 3, 8, 2, 8},
        {5, 1, 9, 3, 2, 6, 8, 7, 4},
        {2, 4, 8, 9, 5, 7, 1, 3, 6},
        {7, 6, 3, 4, 1, 8, 2, 5, 9}};

    int wrongCSudoku[9][9] = {
        {4, 3, 5, 2, 6, 9, 7, 8, 1},
        {6, 8, 2, 5, 7, 1, 4, 9, 3},
        {1, 9, 7, 2, 8, 3, 4, 5, 6},
        {8, 2, 6, 1, 9, 5, 3, 4, 7},
        {3, 7, 4, 6, 8, 2, 9, 1, 5},
        {9, 5, 1, 7, 4, 3, 6, 2, 8},
        {5, 1, 9, 3, 2, 6, 8, 7, 4},
        {2, 4, 8, 9, 5, 7, 1, 3, 6},
        {7, 6, 3, 4, 1, 8, 2, 5, 9}};

    int sudoku1[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    int sudoku2[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 2},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    
    int sudoku3[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {5, 4, 3, 2, 8, 6, 1, 7, 9}
    };
    
    int sudoku4[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    
    int sudoku5[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {1, 2, 3, 5, 6, 7, 8, 9, 4},
        {5, 6, 4, 8, 9, 1, 2, 3, 7},
        {8, 9, 7, 2, 3, 4, 5, 6, 1},
        {2, 1, 5, 3, 4, 8, 6, 7, 9},
        {3, 4, 8, 6, 7, 2, 9, 1, 5},
        {6, 7, 1, 9, 1, 5, 3, 4, 8}
    };
    
    int sudoku6[9][9] = {
        {8, 2, 7, 1, 5, 4, 3, 9, 6},
        {9, 6, 5, 3, 2, 7, 1, 4, 8},
        {3, 4, 1, 6, 8, 9, 7, 5, 2},
        {5, 9, 3, 4, 6, 8, 2, 7, 1},
        {4, 7, 2, 5, 1, 3, 6, 8, 9},
        {6, 1, 8, 9, 7, 2, 4, 3, 5},
        {7, 8, 6, 2, 3, 5, 9, 1, 4},
        {1, 5, 4, 7, 9, 6, 8, 2, 3},
        {2, 3, 9, 8, 4, 1, 5, 6, 7}
    };
    

    cout << "Choose which sudoku to validate (0-9): ";
    int num;
    cin >> num;

    bool isValid;

    switch (num)
    {
    case 1:
        isValid = validateSudoku(corrSudoku);
        break;
    case 2:
        isValid = validateSudoku(wrongRSudoku);
        break;
    case 3:
        isValid = validateSudoku(wrongCSudoku);
        break;
    case 4:
        isValid = validateSudoku(wrong3Sudoku);
        break;
    case 5:
        isValid = validateSudoku(sudoku1);
        break;
    case 6:
        isValid = validateSudoku(sudoku2);
        break;
    case 7:
        isValid = validateSudoku(sudoku3);
        break;
    case 8:
        isValid = validateSudoku(sudoku4);
        break;
    case 9:
        isValid = validateSudoku(sudoku5);
        break;
    case 0:
        isValid = validateSudoku(sudoku6);
        break;
    default:
        cout << "\nInvalid input!";
        break;
    }

    if (isValid)
    {
        cout << "\nThe sudoku is valid!";
    }
    
}

void resetOcc()
{
    for (size_t i = 0; i < 9; i++)
    {
        occ[i] = 0;
    }
}

bool validateOcc()
{
    // cout << endl;
    for (size_t i = 0; i < 9; i++)
    {
        // cout << occ[i] << " ";
        if (occ[i] > 1)
        {
            cout << "\nNumber " << i+1 << " is repeated " << occ[i] << " times in";
            return false;
        }
    }
    return true;
}

bool checkRow(int arr[9][9])
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            occ[(arr[i][j]) - 1]++;
        }
        if (!validateOcc())
        {
            cout << " Row # " << i+1;
            return false;
        }
        resetOcc();
    }

    return true;
}

bool checkCol(int arr[9][9])
{
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            occ[(arr[j][i]) - 1]++;
        }
        if (!validateOcc())
        {
            cout << " Column # " << i+1;
            return false;
        }
        resetOcc();
    }

    return true;
}

bool check3x3(int arr[9][9])
{
    int square = 1;
    for (size_t row = 0; row < 9; row += 3)
    {
        for (size_t col = 0; col < 9; col += 3)
        {
            for (size_t i = row; i < row + 3; i++)
            {
                for (size_t j = col; j < col + 3; j++)
                {
                    occ[(arr[i][j]) - 1]++;
                }
            }
            if (!validateOcc())
            {

                cout << " Square # " << square;

                return false;
            }
            resetOcc();
            square++;
        }
    }
    return true;
}

bool validateSudoku(int arr[9][9])
{
    if (checkRow(arr))
    {
        if (checkCol(arr))
        {
            if (check3x3(arr))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}