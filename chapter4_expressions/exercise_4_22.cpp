/*
 * Exercise 4.22: Extend the program that assigned high pass, pass, and fail grades to also assign low pass 
 * for grades between 60 and 75 inclusive.
 */

#include <iostream>

using namespace std;

int main(){
    for(unsigned grade; cin >> grade;){
        // version 1: nested conditional operator
        string finalgrade1 = (grade >= 90) ? "high pass" : (grade >= 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
        cout << finalgrade1 << endl;

        //version 2: if else 
        string finalgrade2;
        if(grade >= 90) {
            finalgrade2 = "high pass";
        } else if (grade >= 75) {
            finalgrade2 = "pass";
        } else if (grade >= 60) {
            finalgrade2 = "low pass";
        } else {
            finalgrade2 = "fail";
        }
        cout << finalgrade2 << endl;
    }

    return 0;
}