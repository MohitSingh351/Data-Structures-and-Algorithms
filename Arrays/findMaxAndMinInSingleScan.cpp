// Finding maximum and minimum elements in a single scan

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

void find(int A[], int length) {
    int max = A[0];
    int min = A[0];
    for(int i=0; i<length; i++) {
        if(A[i] > max) {
            max = A[i];
        }
        if(A[i] < min) {
            min = A[i];
        }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

int main() {

    int A[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sorted array
    int B[] = {2, 4, 9, 1, 5, 7, 6, 3, 8};  // Unsorted array
    find(B, 9);    

    return 0;
}