#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// Function to find the missing element in a sorted array using the sum formula
// Time complexity: O(n)
// This method works only for arrays containing the first 'n' natural numbers (1 to n)
int findMissingElementM1(int A[], int length) {
    int sum = 0;

    // Calculate the sum of the elements in the array
    for (int i = 0; i < length; i++) {
        sum += A[i];
    }

    // Calculate the expected sum of the first 'n' natural numbers
    int lastElement = A[length-1];
    int total = (lastElement * (lastElement + 1)) / 2;

    // The missing element is the difference between the expected sum and the actual sum
    int missingElement = total - sum;
    cout << "Missing element is: " << missingElement << endl;
    return missingElement;
}

// Function to find the missing element in a sorted array using the difference method
// Time complexity: O(n)
// This method assumes that the numbers are sequentially increasing
int findMissingElementM2(int A[], int length) {
    int diff = A[0] - 0;  // Calculate the initial difference (A[0] - 0)

    // Iterate through the array to find the missing element
    for (int i = 0; i < length; i++) {
        if (A[i] - i != diff) {  // Check if the difference is not consistent
            cout << "Missing element is: " << i + diff << endl;
            return i + diff;
        }
    }
    return -1;  // Return -1 if no missing element is found (although there should be one)
}

// Function to find the missing element in a sorted array using a difference pattern
// Time complexity: O(n)
// This method assumes that the difference between consecutive elements is consistent
int findMissingElementM3(int A[], int length) {
    int diff = A[1] - A[0];  // Calculate the initial difference between the first two elements

    // Iterate through the array to find the missing element
    for (int i = 0; i < length - 1; i++) {
        if (A[i + 1] - A[i] != diff) {  // Check if the difference is not consistent
            cout << "Missing element is: " << A[i] + diff << endl;
            return A[i] + diff;
        }
    }
    return -1;  // Return -1 if no missing element is found (although there should be one)
}

int main() {

    // Test case 1
    int A[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14};
    findMissingElementM1(A, 13);  // Missing element should be 8

    // Test case 2
    int B[] = {10, 11, 12, 14, 15, 16};
    findMissingElementM2(B, 6);  // Missing element should be 13

    // Test case 3
    int C[] = {100, 200, 300, 400, 600, 700, 800};
    findMissingElementM3(C, 7);  // Missing element should be 500

    return 0;
}
