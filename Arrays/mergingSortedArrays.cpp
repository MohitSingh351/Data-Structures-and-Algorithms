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

void MergeArrays(struct Array *arr1, struct Array *arr2, struct Array *arr3) {
    int i=0, j=0, k=0;
    int m = arr1->length;
    int n = arr2->length;
    while (i<m && j<n) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for (;i<m;i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for (;j<n;j++) {
        arr3->A[k++] = arr2->A[j];
    }   

    arr3->length = m+n;
}

int main() {
    struct Array arr1, arr2, arr3;
    createArray(&arr1);
    createArray(&arr2);
    sortArray(&arr1);
    sortArray(&arr2);

    cout << "Array 1: ";
    display(&arr1, arr1.length);
    cout << "Array 2: ";
    display(&arr2, arr2.length);

    arr3.size = arr2.size + arr1.size;
    arr3.length = 0;
    MergeArrays(&arr1, &arr2, &arr3);
    cout << "Merged Array: ";
    display(&arr3, arr3.length);

    return 0;
}