#include <iostream>
#include <array>

using namespace std;

string getOrdinal(int num) {
    if (num == 1) return "1st";
    if (num == 2) return "2nd";
    if (num == 3) return "3rd";
    return to_string(num) + "th";
}

int main()
{
    cout << "EXERCISE # 1\n\n";
    array<int, 5> num = {55, 66, 33, 22, 77};

    cout << "The array: ";

    for (int digs : num)
    {
        cout << digs << " ";
    }

    for (int i = 0; i < num.size() - 1; i++)
    {
        for (int j = 0; j < num.size() - 1 - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    cout << "\nListed array: ";

    for (int digs : num)
    {
        cout << digs << " ";
    }

    cout << "\n\nEXERCISE # 2\n\n";

    int i = 0, j = 0;
    array<int, 5> numx = {55, 66, 33, 22, 77};
    array<int, 7> num2 = {12, 13, 42, 57, 100, 250, 900};

    cout << "The array 1: ";

    for (int digs : numx)
    {
        cout << digs << " ";
    }

    cout << "\nThe array 2: ";

    for (int digs : num2)
    {
        cout << digs << " ";
    }

    int a = numx.size(), b = num2.size(), index = 0;
    int const n = a + b;
    int num3[n];
    for (index = 0; i < numx.size() && j < num2.size(); index++)

    {
        if (numx[i] < num2[j])
        {
            num3[index] = numx[i];
            i++;
        }
        else
        {
            num3[index] = num2[j];
            j++;
        }
    }
    if (i == numx.size())
    {
        for (; j < num2.size(); index++, j++)
        {
            num3[index] = num2[j];
        }
    }
    else
    {
        for (; i < numx.size(); index++, i++)
        {
            num3[index] = numx[i];
        }
    }
    cout << "\n\nThe new array: ";

    for (int digs : num3)
    {
        cout << digs << " ";
    }

    cout << "\n\nEXERCISE # 3\n\n";

    array<int, 7> numy = {12, 13, 42, 57, 100, 250, 900};

    cout << "The array: ";

    for (int digs : numy)
    {
        cout << digs << " ";        
    }

    int v = numy.size();
    for (int i = 0; i < (numy.size() / 2); i++)
    {
        v--;
        int temp = numy[i];
        numy[i] = numy[v];
        numy[v] = temp;
    }
    cout << "\nThe reversed array: ";

    for (int digs : numy)
    {
        cout << digs << " ";        
    }

    cout << "\n\nEXERCISE # 4 \n\n";
    
    int m;
    cout << "\nEnter number of times to print: ";
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cout << getOrdinal(i) << " Hello" << endl;
    }
}