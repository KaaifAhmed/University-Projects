#include <iostream>
#include <random>
#include <ctime>

using namespace std;
int main()
{
    cout << "\nEXERCISE: GRADING MCQS\n\n";
    const int noOfStuds = 8;
    const int noOfMcqs = 10;

    char key [noOfMcqs] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};

    char answers [noOfStuds] [noOfMcqs];

    int correct [noOfStuds];

    float total{0}, avg{0};

    for (size_t i = 0; i < noOfStuds; i++)
    {
        correct[i] = 0;
    }

    srand(time(NULL));

    for (size_t i = 0; i < noOfStuds; i++)
    {
        for (size_t j = 0; j < noOfMcqs; j++)
        {
            answers [i][j] = 65 + rand()%5;
        }

    }

    // Displaying the array

    for (size_t i = 0; i < noOfStuds; i++)
    {
        for (size_t j = 0; j < noOfMcqs; j++)
        {
            cout << answers [i][j] << " ";
        }
        cout << "\n";

    }

    // Comparing

    for (size_t i = 0; i < noOfStuds; i++)
    {
        for (size_t j = 0; j < noOfMcqs; j++)
        {
            if (answers[i][j] == key [j])
            {
                correct[i]++;
            }

        }

    }

    cout << '\n';
    for (size_t i = 0; i < noOfStuds; i++)
    {
        cout << correct[i] << " ";
    }

    // Calculating total

    for (size_t i = 0; i < noOfStuds; i++)
    {
        total += correct[i];
    }

    avg = total/noOfStuds;

    cout << "\n\nThe average correct answers of the class are: " << avg;

    cout << "\n\n\nEXERCISE MATRIX ADDITION\n";

    int rows, cols;
    cout << "\nEnter the number of rows in the matrix: ";
    cin >> rows;

    cout << "\nEnter the number of columns in the matrix: ";
    cin >> cols;

    int mat1[rows][cols], mat2[rows][cols];

    // Generating numbers
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    // Displaying the array
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << mat1[i][j] << " ";
        }

        cout << "   ";

        for (size_t j = 0; j < cols; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << "\n";
    }

    // Adding the matrices

    int mat3[rows][cols];

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Displaying the array
    cout << "\n\nAFTER ADDITION:\n\n";

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << mat3[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n\nEXERCISE MATRIX MULTIPLICATION\n";

    int rows1, cols1, rows2, cols2;
    cout << "\nEnter the number of rows in the matrix 1: ";
    cin >> rows1;

    cout << "\nEnter the number of columns in the matrix 1: ";
    cin >> cols1;

    cout << "\nEnter the number of rows in the matrix 2: ";
    cin >> rows2;

    cout << "\nEnter the number of columns in the matrix 2: ";
    cin >> cols2;

    if (cols1 != rows2)
    {
        cout << "\nImpossible! Allah Hafiz.";
    }
    else
    {

        // Generating the numbers

        int matrix1 [rows1][cols1], matrix2 [rows2][cols2];

        for (size_t i = 0; i < rows1; i++)
        {
            for (size_t j = 0; j < cols1; j++)
            {
                matrix1[i][j] = rand() % 10;
            }
        }

        for (size_t i = 0; i < rows2; i++)
        {
            for (size_t j = 0; j < cols2; j++)
            {
                matrix2[i][j] = rand() % 10;
            }
        }

        // Displaying the array

        cout << "\nMatrix 1: \n";
        for (size_t i = 0; i < rows1; i++)
        {
            for (size_t j = 0; j < cols1; j++)
            {
                cout << matrix1[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\nMatrix 2: \n";
        for (size_t i = 0; i < rows2; i++)
        {
            for (size_t j = 0; j < cols2; j++)
            {
                cout << matrix2[i][j] << " ";
            }
            cout << "\n";
        }

        // MULTIPLYING

        int matrix3 [rows1] [cols2];

        for (size_t i = 0; i < rows1; i++)
        {
            for (size_t j = 0; j < cols2; j++)
            {
                matrix3[i][j] = 0;
            }
            
        }

        for (size_t i = 0; i < rows1; i++)
        {
            for (size_t j = 0; j < cols2; j++)
            {
                for (size_t k = 0; k < cols1; k++)
                {
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                
            }
            
        }

        cout << "\nAFTER MULTIPLYING:\n";
        for (size_t i = 0; i < rows1; i++)
        {
            for (size_t j = 0; j < cols2; j++)
            {
                cout << matrix3[i][j] << " ";
            }
            cout << "\n";
        }
        

    }
}