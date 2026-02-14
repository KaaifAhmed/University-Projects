#include <iostream>

using namespace std;

int main () {
    string num, out;
    cin >> num;
    out = num;
    for (size_t i = 0; i < num.size(); i++)
    {
        if (i==0)
        {
            out[num.size()-1] = num[0];
        }
        else {
            out[i-1] = num[i];
        }
    }

    cout << out << endl;
    
    for (size_t i = 0; i < num.size(); i++)
    {
        if (i==(num.size()-1))
        {
            out[0] = num[num.size()-1];
        }
        else {
            out[i+1] = num[i];
        }
    }

    cout << out;
    
}