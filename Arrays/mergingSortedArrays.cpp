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

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sortArray(struct Array *arr) {
    for (int i=0;i<arr->length-1;i++) {
        for (int j=i+1;j<arr->length;j++) {
            if (arr->A[i] > arr->A[j]) {
                swap(&arr->A[i], &arr->A[j]);
            }
        }
    }
}

int main() {
    struct Array arr1;
    createArray(&arr1);
    display(&arr1, arr1.length);

    struct Array arr2;
    createArray(&arr2);
    display(&arr2, arr2.length);

    struct Array arr3;

    sortArray(&arr1);
    sortArray(&arr2);

    int i=0, j=0, k=0;
    int m = arr1.length;
    int n = arr2.length;
    while (i<m && j<n) {
        if (arr1.A[i] < arr2.A[j]) {
            arr3.A[k++] = arr1.A[i++];
        } else {
            arr3.A[k++] = arr2.A[j++];
        }
    }

    for (;i<m;i++) {
        arr3.A[k++] = arr1.A[i];
    }

    for (;j<n;j++) {
        arr3.A[k++] = arr2.A[j];
    }   

    arr3.length = m+n;
    display(&arr3, arr3.length);

    return 0;
}