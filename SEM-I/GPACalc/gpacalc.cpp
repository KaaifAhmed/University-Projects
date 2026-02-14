#include <iostream>
#include <thread>

using namespace std;

float calculateGPA (int marks) {
    if (marks >= 85)
    {
        return 4.0;
    } 
    
    else if (marks >= 80) {
        return 3.8;
    }

    else if (marks >= 75) {
        return 3.4;
    }

    else if (marks >= 71) {
        return 3.0;
    }

    else if (marks >= 68) {
        return 2.8;
    }

    else if (marks >= 64) {
        return 2.4;
    }

    else if (marks >= 61) {
        return 2.0;
    }

    else if (marks >= 57) {
        return 1.8;
    }

    else if (marks >= 53) {
        return 1.4;
    }

    else if (marks >= 50) {
        return 1.0;
    }

    else if (marks < 50) {
        return 0.0;
    } 
    
    else {
        return 10.0;
    }
    
}

float calculateCGPA (float gpa[6], int creds[6]) {
    float gradePoints = 0;
    int totalCreditHours = 0;
    float CGPA = 0.0;
    // cout << "GPA: " << gpa[0] << " Credit hours: " << creds[0] << endl;
    for (int i = 0; i < 6; i++)
    {
        gradePoints += gpa[i] * creds[i];
        totalCreditHours += creds[i];
    }
    cout << "\n\nTotal Grade points: " << gradePoints << " Total Credit Hours: " << totalCreditHours << endl;
    CGPA = gradePoints/totalCreditHours;
    return CGPA;
    
}

int main () {
    string subjects[] = {"Programming Fundamentals", "Introduction to Information and Communication Technologies", 
    "Discrete Structures", "Calculus and Analytical Geometry", "Functional English", "Ideology and Constitution of Pakistan"};
    int subjectCreditHours[] = {4, 3, 3, 3, 3, 2};
    float subjectMarks[] = {0, 0, 0, 0, 0, 0};
    float subjectGPA[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    int numberOfSubjects = 6;

    for (int i = 0; i < numberOfSubjects; i++)
    {
        cout << "\nEnter your marks in " << subjects[i] << ": ";
        cin >> subjectMarks[i];
        subjectGPA[i] = calculateGPA(subjectMarks[i]);
        cout << "Your GPA in " << subjects[i] << " is: " << subjectGPA[i] << endl;
    }

    float CGPA = calculateCGPA(subjectGPA, subjectCreditHours);

    cout << "\n\nYour CGPA is: " << CGPA << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

}