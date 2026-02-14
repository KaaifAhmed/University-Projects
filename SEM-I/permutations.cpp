// #include <iostream>
// #include <string.h>
// #include <limits>

// using namespace std;

// void permutations(int n, string * arr, int countX = 0);

// void swap(char *a, char *b);

// int fact(int a);

// int main()
// {
//     // cout << "\n\nEXERCISE # 3\n\n";
//     cout << "Enter n: ";
//     int n;
//     cin >> n;
//     int nfact = fact(n);

//     string perms[nfact];
//     for (size_t i = 0; i < nfact; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             perms[i][j] = 'a' + j;
//         }
//     }

//     // for (size_t i = 0; i < nfact; i++)
//     // {
//     //     for (size_t j = 0; j < n; j++)
//     //     {
//     //         cout << perms[i][j];
//     //     }
//     //     cout << endl;
//     // }

//     // cout << "FACT: " << fact(2) << fact(3) << endl;

//     permutations(n, perms);

//     // for (size_t i = 0; i < nfact; i++)
//     // {
//     //     for (size_t j = 0; j < n; j++)
//     //     {
//     //         cout << perms[i][j];
//     //     }
//     //     cout << endl;
//     // }
// }

// int fact(int a)
// {
//     int f = 1;
//     for (size_t i = 1; i <= a; i++)
//     {
//         f *= i;
//     }
//     return f;
// }

// void swap(char *a, char *b)
// {
//     char temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void permutations(int n, string * perms, int countX)
// {
//     int nfact = fact(n);
//     int count = 0;

//     if (n == 2)
//     {
//         for (size_t i = 0; i < n; i++)
//         {
//             swap(perms[countX + i][n - 1], perms[countX + i][i]);
//             cout << "n: " << n << " countX + i: " << countX + i << endl;
//         }   
//     }
//     else if (n > 2)    
//     {
//         for (size_t i = 0; i < n; i++)
//         {
//             for (size_t j = 0; j < fact(n - 1); j++)
//             {
//                 swap(perms[countX + j][n - 1], perms[countX + j][i]);
//                 cout << "n: " << n << " countX + j: " << countX + j << endl;
//                 // cout << perms[count][n-1] << perms[count][i] <<  endl;
//                 count++;
//             }
//             permutations(n-1, perms, countX);
//             countX += count;
//             cout << " UF " << n << endl;
            
//         }
//         cout << " OF " << n << endl;
//     }

//     cout << " HI " << n << endl;

    
//     for (size_t i = 0; i < nfact; i++)
//     {
//         for (size_t j = 0; j < n; j++)
//         {
//             cout << perms[i][j];
//         }
//         cout << endl;
//     }

// }

#include <iostream>
#include <string>
using namespace std;

int fact(int a);
void swap(char &a, char &b);
void permutations(int n, string *perms, int countX);

int main() {
    cout << "Enter n: ";
    int n;
    cin >> n;
    int nfact = fact(n);

    string perms[nfact];

    // Fill base string: "abc..."
    string base = "";
    for (int i = 0; i < n; i++) {
        base += 'a' + i;
    }

    // Fill all strings with base
    for (int i = 0; i < nfact; i++) {
        perms[i] = base;
    }

    permutations(n, perms, 0);

    for (int i = 0; i < nfact; i++) {
        cout << perms[i] << endl;
    }

    return 0;
}

int fact(int a) {
    int f = 1;
    for (int i = 1; i <= a; i++)
        f *= i;
    return f;
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permutations(int n, string *perms, int countX) {
    int blockSize = fact(n - 1);

    if (n == 1)
        return;

    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            permutations(n-1, perms, countX);         // recurse on remaining n-1 letters
            countX += fact(n-1);
            if (i < n-1) {
                swap(perms[i], perms[n-1]);           // swap next element into place
            }
        }

        countX += blockSize;
    }
}
