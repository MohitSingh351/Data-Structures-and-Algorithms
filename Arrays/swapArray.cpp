#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Array {
    int A[10];
    int size;
    int length;
};

void display(struct Array *arr, int length) {
    for(int i=0;i<length;i++) {
        printf("%d ",arr->A[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Method 1: By swapping in the same array
void reverseArrayM1(struct Array *arr) {
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--) {
        swap(&arr->A[i],&arr->A[j]);
    }
}

// Method 2: By swapping in a new array
void reverseArrayM2(struct Array *arr) {
    int *B;
    int i, j;
    B = new int[arr->length];

    for(i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for(i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }
    delete []B;
}

void createArray(struct Array *arr) {
    cout << "Enter the size of the array: ";
    cin >> arr->size;
    arr->length = 0;
    cout << "Enter the elements of the array: ";
    for(int i=0;i<arr->size;i++) {
        cin >> arr->A[i];
    }
    arr->length = arr->size;
}

int main() {
    struct Array arr;
    createArray(&arr);
    display(&arr, arr.length);
    reverseArrayM1(&arr);   // it reverses 1, 2, 3, 4, 5 to 5, 4, 3, 2, 1
    display(&arr, arr.length);
    reverseArrayM2(&arr);   // it reverses 5, 4, 3, 2, 1 to 1, 2, 3, 4, 5
    display(&arr, arr.length);
    return 0;
}