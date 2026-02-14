#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main () {
    float x, y;

    cout << "Exercise 1\n\n";
    cout << "Enter x and y: ";
    cin >> x >> y;

    float euclideanDistance = sqrt(pow((x - 0),2) + pow((y - 0), 2));

    cout << euclideanDistance;

    cout << "Exercise 2\n\n";
    time_t present_time;
    present_time = time(NULL);
    cout << present_time << " seconds have passed since 00:00 GMT, Jan 1, 1970" << endl;
    // int a = present_time;
    int a = present_time;
    int ys{31536000}, ms{2592000}, ds{86400}, hs{3600}, mns{60};
    int years, months, days, hours, minutes, secs;

    years = a/ys;
    a = a - (years*ys);
    cout << years << endl;
    cout << "a= " << a << endl;

    months = a/ms;
    a = a - (months*ms);
    cout << months << endl;
    cout << "a= " << a << endl;


    days = a/ds;
    a = a - (days*ds);
    cout << days << endl;
    cout << "a= " << a << endl;


    hours = a/hs;
    a = a - (hours*hs);
    cout << hours << endl;
    cout << "a= " << a << endl;

    minutes = a/mns;
    secs = a - (minutes*mns);
    cout << minutes << endl;
    cout << secs << endl;

    cout << "GMT " << hours << ":" << minutes  << ":" << secs << endl;
    cout << "PKT " << hours+5 << ":" << minutes  << ":" << secs << endl;


    cout << "Exercise 3\n\n";
    float moneyAct;

    cout << "Enter the money in decimal: ";
    cin >> moneyAct;

    int dollars = moneyAct;
    int money = (moneyAct-dollars)*100;

    int quarters = money/25;
    money = money%25;

    int dime = money/10;
    money = money%10;

    int nickel = money/5;
    money = money%5;

    cout << "The money is " << dollars << " Dollars " <<  quarters<< " Quarters " << dime << " Dime " << nickel << " Nickel "  << money << " pennies.";



    int num;
    cout << "Exercise 4\n\n";
    cout << "Enter the number: ";
    cin >> num;
    int numb = num;

    int _a = numb%10;
    numb = numb/10;

    int b = numb%10;
    numb = numb/10;

    int c = numb%10;
    numb = numb/10;

    int d = numb%10;
    numb = numb/10;

    int e = numb%10;
    numb = numb/10;

    int rev = _a*10000 + b*1000 + c*100 + d*10 + e;

    cout << rev;

    bool isPalindrome = rev == num;
    cout << "\n\nReverse: " << rev << " Number: " << num;
    if (isPalindrome) {
        cout << "\nYep, Palindrome!";
    } else {
        cout << "\nNope, Not Palindrome!";
    }
}