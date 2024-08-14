#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main() {
    int i, j;
    // 1st type: Normal declaration of 2D array
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};  

    // 2nd type: Using pointers
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    // 3rd type: Using double pointers
    int **C;    // Double pointer
    C = new int *[3];   // Creating an array of pointers
    C[0] = new int[4];  
    C[1] = new int[4];
    C[2] = new int[4];

    for(i=0;i<3;i++) {
        for(j=0;j<4;j++)
        printf("%d ",C[i][j]);
        printf("\n");
    }

    delete []B[0];
    delete []B[1];
    delete []B[2];

    delete []C[0];
    delete []C[1];
    delete []C[2];

    return 0;
}