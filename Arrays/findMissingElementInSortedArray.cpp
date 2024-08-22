// Find the missing element in a sorted array

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// Finding missing element in a sorted array through sum = [n*(n+1)]/2
// Time complexity: O(n)
// Work only for first n natural numbers(1 to n)
int findMissingElementM1(int A[], int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += A[i];
    }
    int lastElement = A[length-1];
    int total = (lastElement*(lastElement+1))/2;
    int missingElement = total - sum;
    cout << "Missing element is: " << missingElement << endl;
    return missingElement;
}

int findMissingElementM2(int A[], int length) {
    int diff = 0;
    diff = A[0] - 0;

    for(int i=0; i<length; i++) {
        if(A[i] - i != diff) {
            cout << "Missing element is: " << i + diff << endl;
            return i + diff;
        }
    }
}

int findMissingElementM3(int A[], int length) {
    int diff = A[1] - A[0];
    for (int i=0; i<length-1; i++){
        if (A[i+1] - A[i] != diff) {
            cout << "Missing element is: " << A[i] + diff << endl;
            return A[i] + diff;
        }
    }
}


int main() {

    int A[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14};
    findMissingElementM1(A, 13);

    int B[] = {10, 11, 12, 14, 15, 16};
    findMissingElementM2(B, 6);

    int C[] = {100, 200, 300, 400, 600, 700, 800};
    findMissingElementM3(C, 7);

    return 0;
}