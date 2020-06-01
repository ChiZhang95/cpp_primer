/* 
 * Exercise 4.21: Write a program to use a conditional operation to find the elements 
 * in a vector<int> that have odd value and double the value of each such element.
 */
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(auto &num : arr){
        num = (num % 2 == 1)? num * 2 : num;
        cout << num << endl;
    }
    
    return 0;
}