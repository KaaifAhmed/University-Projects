#include <iostream>
#include <string>
#include <array>

using namespace std;

void changeCase(string *str)
{
    for (size_t i = 0; i < (*str).length(); i++)
    {
        // cout << (*str)[i];
        if (((*str)[i] >= 'a') && ((*str)[i] <= 'z'))
        {
            (*str)[i] -= 32;
        }
        else if (((*str)[i] >= 'A') && ((*str)[i] <= 'Z'))
        {
            (*str)[i] += 32;
        }
    }
}

void lowerCase(string *str)
{
    for (size_t i = 0; i < (*str).length(); i++)
    {
        if (((*str)[i] >= 'A') && ((*str)[i] <= 'Z'))
        {
            (*str)[i] += 32;
        }
    }
}

bool isPalindrome(string str)
{
    string temp = str;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        // cout << i << endl;
        temp.at((str.length() - 1) - i) = str.at(i);
    }
    cout << temp << endl;
    return (temp == str);
}

string removeSpaces(string str)
{
    int position = str.find_first_of(' ');
    while (position != str.npos)
    {
        str.erase(position, 1);
        position = str.find_first_of(' ');
    }

    return str;
}

string sortString(string str)
{
    for (size_t i = 0; i < str.length() - 1; i++)
    {
        for (size_t j = i + 1; j < str.length(); j++)
        {
            if (str[i] > str[j])
            {
                swap(str[i], str[j]);
            }
        }
    }

    return str;
}

string longestString(string str)
{
    int position = str.find_first_of(' ');
    int i = 0;
    string longest;

    while (position != str.npos)
    {
        if ((position - i) > longest.length())
        {
            longest = str.substr(i, (position - i));
            // cout << longest << endl;
        }
        // cout << str.substr(i,(position-i)) << endl;
        i = position + 1;
        str[position] = '.';

        position = str.find_first_of(' ');
        // cout << "\ni: " << i << " pos: " << position << endl;
    }
    // cout << "\ni: " << i << " lenght: " << str.length() << endl;

    if (((str.length()) - i) > longest.length())
    {
        longest = str.substr(i, ((str.length()) - i));
        // cout << longest << endl;
    }

    return longest;
}

string removeDuplicates(string str)
{
    array<int, 26> freq = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string strc = str;
    lowerCase(&str);
    for (size_t i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            if (freq[str[i] - 'a'] == 0)
            {
                freq[str[i] - 'a']++;
            }
            else if (freq[str[i] - 'a'] > 0)
            {
                strc.at(i) = '$';
                // cout << str[i] << " is repeated at " << i << endl;
            }
        }
    }

    int pos = strc.find_first_of('$');
    while (pos != strc.npos)
    {
        strc.erase(pos, 1);
        pos = strc.find_first_of('$');
    }

    cout << endl;

    return strc;
}

void zigzagString (string str, int rows, int cols) {
char arr[rows][cols];

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = ' ';
        }
    }

    bool down = true;

    for (size_t i = 0, j = 0; i < str.length(); i++)
    {
        arr[j][i] = str[i];
        // cout << "i: " << i << " j: " << j << endl;

        if (j == rows - 1)
        {
            down = !down;
        }
        else if ((j == 0) && (!down))
        {
            down = !down;
        }

        if (down)
        {
            j++;
        }
        else
        {
            j--;
        }
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nThe row-wise concatenated string is: ";
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (arr[i][j] != ' ')
            {
                cout << arr[i][j];
            }
        }
    }
}

int main()
{
    // string str = "hI i AM kAAIF aHMED.";
    // changeCase(&str);
    // cout << str;

    // cout << boolalpha << isPalindrome("noon");

    // cout << removeSpaces("I had 4  spaces.");

    // cout << sortString("plaqokswijdehufrgytmnxzbvc");

    // string a = "hello ";
    // string b = "hele!";
    // cout << b.compare(0,3,a,0,3);

    // cout << longestString("I am not the longest word in this sentence");

    // cout << removeDuplicates("can you please remove duplicates from this?");
    // cout << removeDuplicates("I have two is");

    // string str = "I am the worst";
    // str.erase(4,1);
    // cout << str;

    // string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // string str;
    // cout << "Enter the string: ";
    // getline(cin, str);
    // int rows = 5, cols = str.length();
    // cout << "Number of rows: ";
    // cin >> rows;

    // zigzagString(str, rows, cols);

}