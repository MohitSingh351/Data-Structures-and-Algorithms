// Adding/Appending an element to the array to the last position

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display(int A[], int length) {
    for(int i=0;i<length;i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main() {

    const int MAX_SIZE = 10;    // Constant variable declaring the size of the array
    int A[MAX_SIZE] = {1, 2, 3, 4, 5, 6};   // Declaration of an array of size 16
    int length = 6; // Current number of elements in the array
    int newElement = 10;    // Element to be added to the array

    // Adding the element to the array
    if(length < MAX_SIZE) {
        A[length] = newElement;
        length++;
    } else {
        printf("Array is full. Cannot add more elements.\n");
    }

    // Calling display function to display the elements of the array
    display(A, length);

    return 0;
}