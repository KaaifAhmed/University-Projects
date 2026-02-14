#include <iostream>
#include <string.h>
#include <vector>
#include <limits>

using namespace std;

// void permutations (int, int i=0);

void generatePermutations(string str, int index, vector<string>& result) {
    if (index == str.size()) {
        result.push_back(str);
        return;
    }

    for (int i = index; i < str.size(); ++i) {
        swap(str[index], str[i]);
        generatePermutations(str, index + 1, result);
        swap(str[index], str[i]);
    }
}

void swap (char * a, char * b);

int fact (int a) {
    int f = 1;
    for (size_t i = 1; i <= a; i++)
    {
        f *= i;
    }
    return f;
    
}

bool isAnagram(string, string);

bool isSubsequence(string, string);

int findTotalWords(string);

int findTotalSents(string para);

int findSpaces(string para);

int findArticles(string para);

string findAndReplace(string);

string lowerCase(string);

bool isValid(string);
bool val1(string);
bool val2(string);
bool val3(string);
bool val4(string);

int main()
{
    cout << "EXERCISE # 1\n\n";

    char str[] = "Barca 1 Sevilla 0, Real Madrid 1 Barca 1, Barca 3 Valencia 1, Villarreal 2 Barca 1, Espanyol 2 Barca 4";
    char team[] = "Barca";

    int totScored{0}, totConceded{0}, wins{0}, losses{0}, draws{0}, points{0};

    char *strPtr = strtok(str, ",");

    while (strPtr != NULL)
    {

        int scored = 0, conceded = 0;

        while (*strPtr != '\0')
        {
            // cout << *strPtr;
            int i = 0;
            if (*strPtr == team[i])
            {
                char *tempPtr = strPtr;
                bool match = true;
                i++;
                while (team[i] != '\0')
                {
                    if (*(++tempPtr) != team[i])
                    {
                        match = false;
                        break;
                    }
                    i++;
                }
                if (match)
                {
                    tempPtr += 2;
                    scored += *tempPtr - '0';
                    strPtr = tempPtr;
                }
            }
            else if ((*strPtr >= '0') && (*strPtr <= '9'))
            {
                conceded += *strPtr - '0';
            }
            *strPtr++;
        }

        if (scored > conceded)
        {
            wins++;
        }
        else if (scored < conceded)
        {
            losses++;
        }
        else
        {
            draws++;
        }

        totScored += scored;

        totConceded += conceded;

        strPtr = strtok(NULL, ",");
    }

    points = (wins * 3) + draws;

    cout << "Total Goals Scored: " << totScored << endl;
    cout << "Total Goals Conceded: " << totConceded << endl;
    cout << "Total Wins: " << wins << endl;
    cout << "Total Losses: " << losses << endl;
    cout << "Total Draws: " << draws << endl;
    cout << "Total Points: " << points << endl;

    // char * strPtr2 = strtok(NULL, ",");
    // cout << strPtr2 << endl;

    cout << "\n\nEXERCISE # 2\n\n";
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 1 || n > 26) {
        cout << "n must be between 1 and 26" << endl;
        return 1;
    }

    string strx = "";
    for (int i = 0; i < n; ++i) {
        strx += ('a' + i);
    }

    vector<string> permutations;
    generatePermutations(strx, 0, permutations);

    for (const string& perm : permutations) {
        cout << perm << endl;
    }





    cout << "\n\nEXERCISE # 3\n\n";
    cout << "Enter the password to check if it\'s valid: ";
    string password;
    cin >> password;
    cout << "The password is " << (isValid(password)?"valid.":"not valid.");
    cin.ignore();

    cout << "\n\nEXERCISE # 4\n\n";
    string str1, str2;
    cout << "Enter the string # 1: ";
    getline(cin, str1);
    cout << "Enter the string # 2: ";
    getline(cin, str2);
    cout << "The strings are " << (isAnagram(str1, str2)?"anagram.":"not anagram.");

    cout << "\n\nEXERCISE # 5\n\n";
    string word, subset;
    cout << "Enter the word: ";
    cin >> word;
    cin.ignore();

    cout << "Enter the subset: ";
    cin >> subset;
    cin.ignore();

    cout << "Is the subset a sequence of word? " << isSubsequence(word, subset);

    cout << "\n\nEXERCISE # 7\n\n";
    char stry[200], largest[50], temp[50];
    cout << "Enter the string: ";
    cin.getline(stry, sizeof(stry));
    char *strPtrX = strtok(stry, " -");

    int i = 0;
    while (*strPtrX != '\0')
    {
        largest[i] = *strPtrX;
        i++;
        strPtrX++;
    }
    largest[i] = '\0';

    strPtrX = strtok(NULL, " -");

    while (strPtrX != NULL)
    {
        int j = 0;

        while (*strPtrX != '\0')
        {
            temp[j] = *strPtrX;
            j++;
            strPtrX++;
        }
        temp[j] = '\0';

        if (j > i)
        {
            int k = 0;
            while (temp[k] != '\0')
            {
                largest[k] = temp[k];
                k++;
            }
            largest[k] = '\0';
            i = j;
        }
        strPtrX = strtok(NULL, " -");
    }

    cout << "\nLargest: " << largest << endl;

    cout << "\n\nEXERCISE # 6\n\n";
    // char para[500];
    string para;

    cout << "Enter the paragraph: \n";
    getline(cin, para);
    int choice;

    do
    {

        cout << "Choose the operation you want to perform (type number): \n1. Calculate total words\n2. Calculate total sentences\n3. Calculate total spaces\n4. Count total articles in the paragraph\n5. Find and replace a string\nPress -1 to terminate\nChoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "\nTotal words: " << findTotalWords(para) << endl;
            break;
        case 2:
            cout << "\nTotal Sentences: " << findTotalSents(para) << endl;
            break;
        case 3:
            cout << "\nTotal Spaces: " << findSpaces(para) << endl;
            break;
        case 4:
            cout << "\nTotal Articles: " << findArticles(para) << endl;
            break;
        case 5:
            para = findAndReplace(para);
            cout << "\nNew paragraph: " << para << endl;
            break;
        case -1:
            cout << "\nGood bye!" << endl;
            break;

        default:
            cout << "\nInvalid option" << endl;
            break;
        }
    } while (choice != -1);
}

void swap (char * a, char * b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int findArticles(string para)
{
    string article[6] = {" a ", " an ", " the ", "A ", "An ", "The "};

    // cout << "TESTING: " << article[1][1];

    int articles = 0;

    for (size_t i = 0; para[i] != '\0'; i++)
    {
        for (size_t m = 0; m < 6; m++)
        {

            bool match = true;
            // cout << "Article # " << article[m];
            if (para[i] == article[m][0])
            {
                for (size_t j = 1; article[m][j] != '\0'; j++)
                {
                    if (para[i + j] != article[m][j])
                    {
                        match = false;
                        // cout << "\nPara and find: " << para[i+j] << find[j];
                        // cout << "\nMatch has been falsified because of mismatch!\n";
                        break;
                    }
                    if ((para[i + j + 1] == '\0') && (article[m][j + 1] != '\0'))
                    {
                        match = false;
                        // cout << "\nMatch has been falsified because of lack of chars!\n";
                        break;
                    }
                }

                if (match)
                {
                    articles++;
                    // cout << "articles: " << articles;
                }
            }
        }
    }

    return articles;
}

int findTotalWords(string para)
{
    int words = 1;
    for (size_t i = 0; para[i] != '\0'; i++)
    {
        if (para[i] == ' ')
        {
            words++;
        }
    }
    if (para[0] == '\0')
    {
        words = 0;
    }

    return words;
}

int findSpaces(string para)
{
    int spaces = 0;
    for (size_t i = 0; para[i] != '\0'; i++)
    {
        if (para[i] == ' ')
        {
            spaces++;
        }
    }

    return spaces;
}

int findTotalSents(string para)
{
    int sents = 0;
    for (size_t i = 0; para[i] != '\0'; i++)
    {
        if (para[i] == '.')
        {
            sents++;
        }
    }
    // if (para[0] == '\0')
    // {
    //     words = 0;
    // }

    return sents;
}

string findAndReplace(string para)
{
    char find[500], replace[500];
    cout << "Find: ";
    cin.getline(find, sizeof(find));
    cout << "Replace: ";
    cin.getline(replace, sizeof(replace));

    for (size_t i = 0; para[i] != '\0'; i++)
    {
        bool match = true;
        if (para[i] == find[0])
        {
            for (size_t j = 1; find[j] != '\0'; j++)
            {
                if (para[i + j] != find[j])
                {
                    match = false;
                    // cout << "\nPara and find: " << para[i+j] << find[j];
                    // cout << "\nMatch has been falsified because of mismatch!\n";
                    break;
                }
                if ((para[i + j + 1] == '\0') && (find[j + 1] != '\0'))
                {
                    match = false;
                    // cout << "\nMatch has been falsified because of lack of chars!\n";
                    break;
                }
            }

            if (match)
            {
                for (size_t k = 0; replace[k] != '\0'; k++)
                {
                    para[i + k] = replace[k];
                }
            }
        }
    }
    return para;
}

bool isSubsequence(string word, string subset)
{
    int i = 0, j = 0;
    while (word[i] != '\0')
    {
        if (subset[j] == word[i])
        {
            j++;
        }
        i++;
        if (j == (subset.length()))
        {
            return true;
        }
    }
    return false;
}

string lowerCase(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

bool isAnagram(string str1, string str2)
{
    str1 = lowerCase(str1);
    str2 = lowerCase(str2);
    int occ1[26];
    int occ2[26];

    int differences = 0;
    for (size_t i = 0; i < 26; i++)
    {
        occ1[i] = 0;
        occ2[i] = 0;
    }

    for (size_t i = 0; i < str1.length(); i++)
    {
        if (str1[i] != ' ')
        {
            occ1[str1[i] - 'a']++;
        }
    }

    for (size_t i = 0; i < str2.length(); i++)
    {
        if (str2[i] != ' ')
        {
            occ2[str2[i] - 'a']++;
        }
        if (str1[i] != str2[i])
        {
            differences++;
        }
    }

    if (!differences)
    {
        return false;
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (occ1[i] != occ2[i])
        {
            return false;
        }
    }

    return true;
}

bool isValid(string pwd)
{
    if (val1(pwd) && val2(pwd) && val3(pwd) && val4(pwd))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool val1(string pwd)
{
    if (pwd.length() >= 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool val2(string pwd)
{
    for (size_t i = 0; i < pwd.length(); i++)
    {
        if ((pwd[i] < '0') || (pwd[i] > '9' && pwd[i] < 'A') || (pwd[i] > 'Z' && pwd[i] < 'a') || (pwd[i] > 'z'))
        {
            return 0;
        }
    }
    return 1;
}

bool val3(string pwd)
{
    int nums{0};
    for (size_t i = 0; i < pwd.length(); i++)
    {
        if (pwd[i] >= '0' && pwd[i] <= '9')
        {
            nums++;
        }
    }
    if (nums >= 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool val4(string pwd)
{
    int chars{0};
    for (size_t i = 0; i < pwd.length(); i++)
    {
        if ((pwd[i] >= 'A' && pwd[i] <= 'Z') || (pwd[i] >= 'a' && pwd[i] <= 'z'))
        {
            chars++;
        }
    }
    if (chars >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}