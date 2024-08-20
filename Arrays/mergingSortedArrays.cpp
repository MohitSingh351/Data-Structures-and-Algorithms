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

void display(struct Array *arr) {
    for(int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

void createArray(struct Array *arr) {
    cout << "Enter the size of the array: ";
    cin >> arr->size;
    arr->length = 0;
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < arr->size; i++) {
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
    for (int i = 0; i < arr->length - 1; i++) {
        for (int j = i + 1; j < arr->length; j++) {
            if (arr->A[i] > arr->A[j]) {
                swap(&arr->A[i], &arr->A[j]);
            }
        }
    }
}

void MergeArrays(struct Array *arr1, struct Array *arr2, struct Array *arr3) {
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    while (i < m && j < n) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for (; i < m; i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < n; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = m + n;
}

struct Array* UnionForSortedArray(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < m && j < n) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr1->A[i] > arr2->A[j]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < m; i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < n; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < m && j < n) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        } else if (arr1->A[i] > arr2->A[j]) {
            j++;
        } else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < m; i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < n; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < m && j < n) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else if (arr1->A[i] > arr2->A[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    for (; i < m; i++) {
        arr3->A[k++] = arr1->A[i];
    };

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}

int main() {
    struct Array arr1 = {{1, 2, 3, 4, 5}, 10, 5};
    struct Array arr2 = {{3, 4, 5, 6, 7}, 10, 5};
    struct Array *arr3;

    arr3 = Difference(&arr1, &arr2);

    display(arr3);

    free(arr3); // Free the allocated memory

    return 0;
}