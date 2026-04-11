#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> merge(vector<int> v1, vector<int> v2)
{
    vector<int> out;
    int i = 0;
    int j = 0;

    // Traversing through vector 1 and 2 simultaneously
    // We compare first elem of v1, with first of v2
    // The smaller one is pushed to the output vect
    // The pointer of that vector is incremented, and comparison occurs again
    // This is done until one of the vectors is emptied (i.e. their pointer i/j reaches end of vector)

    while ((i < v1.size()) && (j < v2.size()))
    {
        if (v1[i] <= v2[j])
        {
            out.push_back(v1[i]);
            i++;
        }
        else
        {
            out.push_back(v2[j]);
            j++;
        }
    }

    // The vector which still had remaining elements is dumped into the output as it is
    // Bcz it's already sorted, and no need to compare
    while (i < v1.size())
    {
        out.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        out.push_back(v2[j]);
        j++;
    }

    return out;
}

// Works by dividing the array into two halves recursively, until one elem remains
// Then those divided arrays are merged together in sorted order as it backtracks
vector<int> mergeSort(vector<int> arr)
{
    // Base case: only one elem (or less)
    if (arr.size() <= 1)
    {
        return arr;
    }

    // Dividing the array into two halves
    int mid = arr.size() / 2;

    vector<int> v1(arr.begin(), arr.begin() + mid);
    vector<int> v2(arr.begin() + mid, arr.end());

    // Applying merge sort on those smaller halves recursively
    v1 = mergeSort(v1);
    v2 = mergeSort(v2);

    // Merging those two halves
    arr = merge(v1, v2);

    return arr;
}
int main()
{
    vector<int> v = {5, 6, 3, 8, 10, 23, 4, 19, 6, 4};

    vector<int> out = mergeSort(v);
    printVector(out);

    return 0;
}