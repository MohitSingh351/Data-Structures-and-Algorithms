#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main() {
    int *p, *q;
    int i;

    p = new int[5]; // Dynamic Array
    p[0] = 3; p[1] = 5; p[2] = 7; p[3] = 9; p[4] = 11;  // Assigning values to the array

    q = new int[10];    // Creating a new array of size 10
    for(i = 0; i < 5; i++) {
        q[i] = p[i];    // Copying the values from p to q
    }
    delete []p; // Deleting the array p
    p = q;  // Assigning the address of q to p
    q = NULL;   // Assigning NULL to q

    for(i = 0; i < 5; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}