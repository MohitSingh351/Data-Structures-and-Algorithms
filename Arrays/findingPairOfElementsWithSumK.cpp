// Finding pairs of elements with a given sum

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// Function to find pairs of elements with a given sum
// Time complexity: O(n^2)
void findPairsWithSumK(int A[], int length, int sum) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (A[i] + A[j] == sum) {
                cout << "Pair found: (" << A[i] << ", " << A[j] << ")" << endl;
            }
        }
    }
}

int maxElement(int A[], int length) {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Function to find pairs of elements with a given sum using hashing
// Time complexity: O(n)
void findPairsWithSumKUsingHashing(int A[], int length, int sum) {
    int max = maxElement(A, length);
    int h_length = max + 1;
    int *H = new int[h_length];
    for (int i = 0; i < h_length; i++) {
        H[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        if (H[sum - A[i]] != 0 && sum - A[i] >= 0) {
            cout << "Pair found: (" << A[i] << ", " << sum - A[i] << ")" << endl;
        }
        H[A[i]]++;
    }
    delete[] H;
}

// Function to find pairs of elements with a given sum in a sorted array
// Time complexity: O(n)
void findPairsWithSumKInSortedArray(int A[], int length, int sum) {
    int i=0;
    int j = length - 1;
    while (i < j) {
        if (A[i] + A[j] == sum) {
            cout << "Pair found: (" << A[i] << ", " << A[j] << ")" << endl;
            i++;
            j--;
        } else if(A[i] + A[j] < sum) {
            i++;
        } else {
            j--;
        }
    }
}

int main() {

    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int sum = 10;
    findPairsWithSumK(A, 10, sum);  // Pairs should be (3, 7) and (8, 2)

    cout << endl;

    int B[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    findPairsWithSumKUsingHashing(B, 10, sum);  // Pairs should be (3, 7) and (8, 2)

    cout << endl;

    int C[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    findPairsWithSumKInSortedArray(C, 10, sum);  // Pairs should be (4, 6) and (3, 7)

    return 0;
}