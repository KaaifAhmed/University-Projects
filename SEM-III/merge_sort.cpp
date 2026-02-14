#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> c;
    for (size_t i=0, j=0; (i < a.size()) || (j < b.size());)
    {
        
        if (i >= a.size())
        {
            for (; j < b.size(); j++)
            {
                c.push_back(b[j]);
            }
            break;         
        }
        if (j >= b.size())
        {
            for (; i < a.size(); i++)
            {
                c.push_back(a[i]);
            }
            break;     
        }

        if (a[i] <= b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i])
        {
            c.push_back(b[j]);
            j++;
        }
    }

    return c;
}

vector<vector<int>> split(vector<int> a)
{
    int mid = a.size() / 2;
    vector<int> b, c;
    vector<vector<int>> out;

    for (size_t i = 0; i < mid; i++)
    {
        b.push_back(a[i]);
    }
    for (; mid < a.size(); mid++)
    {
        c.push_back(a[mid]);
    }

    out.push_back(b);
    out.push_back(c);

    return out;
}

vector<int> merge_sort(vector<int> arr)
{
    vector<int> finArr;

    // Base Case: Array with 1 element gets returned
    if (arr.size() == 1)
        return arr;

    else {
        vector<vector<int>> combArr = split(arr);
        finArr = merge(merge_sort(combArr[0]), merge_sort(combArr[1]));
    }

    return finArr;
}

void printVector(vector<int> v) {
    cout << "\nSize: " << v.size() << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    vector<int> arr = {12, 3, 43, 23, 92, 89, 104, 25, 15, 8, 18};

    cout << "BEFORE SORTING: ";
    printVector(arr);

    arr = merge_sort(arr);

    cout << "\nAFTER SORTING:";
    printVector(arr);

    return 0;
}