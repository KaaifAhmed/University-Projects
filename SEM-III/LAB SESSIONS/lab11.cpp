#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int hi, int lo)
{
    int i = lo - 1;
    int j = lo;
    int pivot = arr[hi];
    while (j < hi)
    {
        if (arr[j] <= pivot)
        {
            i++;
            // Swap
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }

    i++;
    // Swap
    arr[hi] = arr[i];
    arr[i] = pivot;

    return i;
}

void quickSort(vector<int> &arr, int hi, int lo)
{
    if (hi-lo <= 0)
    {
        return;
    }

    int pivot = partition(arr, hi, lo);
    quickSort(arr, pivot-1, lo);
    quickSort(arr, hi, pivot+1);
}

void printVector(vector<int> vec)
{
    cout << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> arr = {2, 8, 9, 10, 4, 3, 11, 6};
    printVector(arr);

    quickSort(arr, arr.size()-1, 0);
    printVector(arr);

    return 0;
}