/************************************************
** Author: Andrea Hayes
** Date: April 30,2020
** Purpose: Check user numbers against random lotter numbers
** Input: Lottery array and user numbers
** Processing: Random number and comparing arrays
** Output: How many numbers match
*************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main() {
    const int LOTNUM = 5, USERNUM = 5, MIN=0, MAX=9;
    int lottery[LOTNUM], user[USERNUM], test[] = { 1,2,3,4,5 }, match=0;
    bool equal = true;
    
    unsigned seed = time(0);

    srand(seed);
    
    cout << "Enter 5 numbers between 0 and 9 and " << endl;
    cout << "to determine if you won the lottery." << endl;

    // Create random numbers and put them in the array
    for (int i = 0; i < LOTNUM; i++) {
        lottery[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }
    
    // Get user numbers and put them in an array
    for (int i = 0; i < USERNUM; i++) {
        cout << "Enter number: ";
        cin >> user[i];
        if (user[i] < 0 || user[i]>9) {
            cout << "Please enter numbers between 0 and 9." << endl;
            return 0;
        }
    }

    // Disply Lottery numbers
    cout << "Lottery Numbers: ";
    for (int i = 0; i < LOTNUM; i++) {
        cout << lottery[i] << " ";
    }
    /*cout << "Test: ";
    for (int i = 0; i < LOTNUM; i++) {
        cout << test[i] << " ";
    }*/
    cout << endl;
    // Display User numbers
    cout << "Your Numbers:    ";
    for (int i = 0; i < USERNUM; i++) {
        cout << user[i] << " ";
    }
    cout << endl;
    // TEST with non random numbers 
    /* int i = 0;
    for (int i = 0; i < LOTNUM; i++) {
        bool equal = true;
        if (test[i] == user[i]) {
            equal = false;
            match += 1;
        }
    }
    if (equal) {
        cout << "You matched " << match << " numbers." << endl;
        if (match == 5) {
            cout << "You are the grand prize winner!" << endl;
        }
    } */

    // Determine what numbers in the array match and display how many matched
    int i = 0;
    for (int i = 0; i < LOTNUM; i++) {
        bool equal = true;
        if (lottery[i] == user[i]) {
            equal = false;
            match += 1;
        }
    }
    if (equal) {
        cout << "You matched " << match << " numbers." << endl;
        if (match == 5) {
            cout << "You are the grand prize winner!" << endl;
        }
    }

    return 0;
}