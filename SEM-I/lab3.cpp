#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
  cout << "\n\nEXERCISE ONE\n";
  int a, b, i{1}, gcd{0};
  cout << "Enter two numbers: ";
  cin >> a >> b;
  int minNum = min(a, b);
  // cout << minNum/2;

  while (i <= minNum) {
    if ((a%i==0) && (b%i==0)) {
      gcd = i;
      // cout << "Hi: " << gcd;
      // cout << "Hi: " << i;
    }
    // cout << i;
    i++;
  }

  cout << "The GCD is: " << gcd;


  cout << "\n\nEXERCISE TWO\n";

  srand(time(nullptr));
  int randNum = rand()%101;
  cout << "[TOP SECRET]The answer is: " << randNum;


  int guess;
  cout << "\n\nGive a guess: ";
  cin >> guess;

  while (guess != randNum) {
    if (guess > randNum) {
      cout << "Too high!";
    } else {
      cout << "Too low!";
    }
    cout << "\nGo again: ";
    cin >> guess;
  }

  cout << "Congratulations, you guessed the number you already knew!";



  cout << "\n\nEXERCISE THREE\n";
  int num;
  cout << "Enter a number: ";
  cin >> num;
  int originalNum = num;

  int pal = 0;

  while (num !=0) {
    pal *= 10;
    pal += num%10;
    num /= 10;
    // cout << pal;
  }

  cout << pal;
  if (pal == originalNum) {
    cout << "\nThe num is palindrome!";
  } else {
    cout << "\nThe num is not palindrome!";
  }



  cout << "\n\nEXERCISE FOUR\n";
  char status;
  int income, taxRate{0};

  cout << "Are you shadi shuda (married) or kanwara (single) (type m or s): ";
  cin >> status;
  cout << "Your total income: ";
  cin >> income;

  if (status == 's') {
    if (income > 372951) {
      taxRate = 35;
    } else if (income > 171551) {
      taxRate = 33;
    } else if (income > 82251) {
      taxRate = 28;
    } else if (income > 33951) {
      taxRate = 25;
    } else if (income > 8351) {
      taxRate = 15;
    } else if (income > 0) {
      taxRate = 10;
    } else {
      cout << "\nInvalid income";
    }
  } else if (status == 'm') {
    if (income > 372951) {
      taxRate = 35;
    } else if (income > 208851) {
      taxRate = 33;
    } else if (income > 137051) {
      taxRate = 28;
    } else if (income > 67901) {
      taxRate = 25;
    } else if (income > 16701) {
      taxRate = 15;
    } else if (income > 0) {
      taxRate = 10;
    } else {
      cout << "\nInvalid income";
    }
  }

  float tax = income * (taxRate / 100.0);
  cout << "\nTax rate: " << taxRate;
  cout << "\nTax: " << tax;

  float takeHome = income - tax;
  cout << "\nTake Home income: " << takeHome;

}