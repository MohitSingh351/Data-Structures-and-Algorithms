#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 10;    // Constant variable declaring the size of the array
    int A[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // Declaration of an array of size 10

    // Displaying the elements of the array
    for(int i=0;i<MAX_SIZE;i++) {
        cout<<A[i]<<" ";
    }

    return 0;
}