// Finding duplicates in an array

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// Function to find duplicates in an array
// Time complexity: O(n)
void findDuplicatesM1(int A[], int length){
    int lastDuplicate = 0;
    for (int i = 0; i < length-1; i++) {
        if (A[i] == A[i+1] && A[i] != lastDuplicate) {
            cout << "Duplicate element is: " << A[i] << endl;
            lastDuplicate = A[i];
        }
    }
}

// Function to find duplicates in an array and also to count number of duplicates
// Time complexity: O(n)
void findDuplicatesM2(int A[], int length) {
    int i, j;
    for (i=0; i<length-1; i++) {
        if (A[i] == A[i+1]) {
            j = i+1;
            while(A[j] == A[i]){
                j++;
            }
            cout << "Duplicate element is: " << A[i] << " and it appears " << j-i << " times." << endl;
            i = j-1;
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

// Function to find duplicates in an array using hashing
// Time complexity: O(n)
void findDuplicatesM3(int A[], int length) {
    int max = maxElement(A, length);
    int *H = new int[max + 1];
    int h_length = max + 1;
    for(int i=0; i<h_length; i++) {
        H[i] = 0;
    }
    for(int i=0; i<length; i++) {
        H[A[i]]++;
    }
    for(int i=0; i<h_length; i++) {
        if (H[i] > 1) {
            cout << "Duplicate element is: " << i << " and it appears " << H[i] << " times." << endl;
        }
    }
    delete[] H;
}

void findDuplicatesInUnsortedArrayM1(int A[], int length) {
    for(int i=0; i<length-1; i++) {
        int count = 1;
        if(A[i] != -1) {
            for(int j=i+1; j<length; j++) {
                if(A[i] == A[j]) {
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 1) {
                cout << "Duplicate element is: " << A[i] << " and it appears " << count << " times." << endl;
            }
        }
    }
}

// Find duplicates in an unsorted array using hashing
void findDuplicatesUsingHashing(int A[], int length) {
    int max = maxElement(A, length);
    int w_length = max + 1;
    int *W = new int[w_length];
    for(int i=0; i<w_length; i++) {
        W[i] = 0;
    }
    for(int i=0; i<length; i++) {
        W[A[i]]++;
    }
    
    for(int i=0; i<w_length; i++) {
        if(W[i] > 1) {
            cout << "Duplicate element is: " << i << " and it appears " << W[i] << " times." << endl;
        }
    }
    
    delete[] W;
}

int main() {

    // Test case 1
    int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    findDuplicatesM1(A, 10);  // Duplicates should be 8 and 15
    cout << endl;
    findDuplicatesM2(A, 10);  // Duplicates should be 8 and 15
    cout << endl;
    findDuplicatesM3(A, 10);  // Duplicates should be 8 and 15
    cout << endl;
    cout << "Unsorted array" << endl << "------------------";
    cout << endl;
    int B[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    findDuplicatesInUnsortedArrayM1(B, 10);  // Duplicates should be 8, 6
    cout << endl;
    int C[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    findDuplicatesUsingHashing(C, 10);  // Duplicates should be 8, 6
    return 0;
}