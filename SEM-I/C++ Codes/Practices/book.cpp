#include <iostream>
#include <array>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

void printArray (int arr[], int size) {
    cout << "\n";

    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << " ";
    }
    
    cout << "\n";
    
}

string decimalConversion (int base, int dec) {
    int a, b {dec}, i {1}, conv;

    if (base > 10)
    {
        string conv;
        while (b != 0)
        {
            a = b%base;
            b = b/base;
            if (a > 9)
            {
                conv = (char) (a + 55) + conv;
            } else {
                conv = to_string(a) + conv;
            }
            
        }
        string x = conv;
        conv = "";
        return x;

    } else 
    {
        while (b != 0)
        {
            a = b%base;
            b = b/base;
            conv += a*i;
            i *= 10;
        }
        string x = to_string(conv);
        conv = 0;
        return x;
    }
}

int main () {
    cout << "EXERCISE 7.10";
    int basicSal;
    cout << "\nEnter basic hourly salary rates: ";
    cin >> basicSal;

    const int workers = 5;
    int tips[workers];
    int hours[workers];
    int salary[workers];

    for (size_t i = 0; i < workers; i++) {
        cout << "\nEnter the hours worked by Server " << i+1 << ": ";
        cin >> hours[i];
        cout << "\nEnter the tips collected by Server " << i+1 << ": ";
        cin >> tips[i];
    }

    for (size_t i = 0; i < workers; i++)
    {
        salary[i] = basicSal*hours[i] + tips[i];
    }
    
    cout << "\n\nSalary Range  Number of Servers\n";
    for (size_t i = 2; i < 10; i++)
    {
        cout << setw(7) << i*10 << "-" << i*10+9 << ": "; // i + '0-' + i + '9: '
        for (size_t j = 0; j < workers; j++)
        {
            if ((salary[j] >= i*10) && (salary[j] <= i*10+9))
            {
                cout << '*';
            }
            
        }
        cout << '\n';
        
    }


    cout << "\n\nEXERCISE 7.13\n";

    const int numsSize = 10;

    array<int, numsSize> nums {};
    int uniqueNums {0};

    for (size_t i = 0; i < numsSize; i++)
    {
        cout << "Enter a number (1-100): ";
        cin >> nums[uniqueNums];

        bool isUnique = true;

        for (size_t j = 0; j < uniqueNums; j++)
        {
            if (nums[uniqueNums] == nums[j])
            {
                isUnique = false;
                cout << "The number is duplicate.\n";
            }
            
        }

        if (isUnique)
        {
            uniqueNums++;
        }        
        
        
    }

    cout << "\nThese are the unique numbers you entered: ";

    for (size_t i = 0; i < uniqueNums; i++)
    {
        cout << nums[i];
        cout << " ";
    }
    
    cout << "\n\nEXERCISE 7.16\n";
    array<int, 11> occurences {};

    srand(time(NULL));

    int rounds = 36000000;
    int dice1, dice2, sum;

    for (size_t i = 0; i < rounds; i++)
    {
        dice1 = 1 + rand()%6;
        dice2 = 1 + rand()%6;
        sum = dice1 + dice2;
        occurences[sum-2]++;

        // cout << "\n\n" << dice1 << "  " << dice2 << "  " << sum << "\n";
    }

    cout << "\nSUMS  OCCURENCES  PROBABILITY\n";
    for (size_t i = 0; i < occurences.size(); i++)
    {
        cout << setw(4) << (i+2) << setw(12) << occurences[i] << setw(13) << setprecision(2) << (float) occurences[i] / rounds << endl;

    }


    cout << "\n\nEXERCISE 4.16\n";

    float fundsRaised {0};
    bool run {true};

    while (run)
    {
        int laps;
        float sponsorshipRate, contribution;
        cout << "\nEnter laps completed(-1 to end): ";
        cin >> laps;

        if (laps == -1)
        {
            cout << "\nTotal funds raised: " << fundsRaised;
            run = false;
            break;
        }

        cout << "\nEnter sponsorship rate: ";
        cin >> sponsorshipRate;

        contribution = sponsorshipRate*laps;
        fundsRaised += contribution;
        cout << "\nStudent contribution is: " << contribution;
    }
    
    
     
    cout << "\n\nEXERCISE 4.16\n";
    
    array<int, 10> nums = {};

    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << "Enter number # " << i+1;
        cin >> nums[i];
    }

    int largest {nums[0]};

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
        
    }
    
    cout << "\nThe largest number among all is: " << largest;

    int n,c;
    cout<<"Enter Fibonacci series of nth term: ";
    cin>>n;
    
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    
    for (int i=0;i<(n-2);i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    cout<<endl;



    cout << "\n\nDEC TO BIN,OCT,HEX\n";

    int dec;
    cout << "Enter decimal number: ";
    cin >> dec;

    string bin {decimalConversion(2, dec)}, oct {decimalConversion(8, dec)}, hex {decimalConversion(16, dec)};
    
    cout << "\nBinary: " << bin;
    cout << "\nOctal: " << oct;
    cout << "\nHexadecimal: " << hex;

}