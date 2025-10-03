#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> a)
{
    for (auto elem : a)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> v1 = {0, 1, 5, 2};
    // printVector(v1);

    // v1.pop_back();

    // printVector(v1);

    // v1.push_back(45);
    // printVector(v1);

    struct student
    {
        string name;
        int age;
        float gpa;
    };

    student kaaif = {"kaaif", 19, 4.0};

    cout << kaaif.name;
    cout << kaaif.age;
    
    kaaif.name = "chandiyo";
    cout << kaaif.name;
    

}