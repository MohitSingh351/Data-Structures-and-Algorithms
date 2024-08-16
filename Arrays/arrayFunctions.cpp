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

int get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        cout << "Element at index " << index << " is " << arr.A[index] << endl;
        return arr.A[index];
    }
    return -1;
}

int set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = x;
        cout << "Element at index " << index << " is set to " << x << endl;
        return arr->A[index];
    }
    return -1;
}

int max(struct Array arr) {
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    cout << "Maximum element in the array is " << max << endl;
    return max;
}

int min(struct Array arr) {
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
    }
    cout << "Minimum element in the array is " << min << endl;
    return min;
}

int sum(struct Array arr) {
    int sum = 0;
    for(int i=0;i<arr.length;i++) {
        sum += arr.A[i];
    }
    cout << "Sum of all elements in the array is " << sum << endl;
    return sum;
}

int average(struct Array arr) {
    int sum = 0;
    for(int i=0;i<arr.length;i++) {
        sum += arr.A[i];
    }
    cout << "Average of all elements in the array is " << sum/arr.length << endl;
    return sum/arr.length;
}

int main() {
    struct Array arr;
    createArray(&arr);
    display(&arr, arr.length);
    get(arr, 2);
    set(&arr, 2, 10);
    display(&arr, arr.length);
    display(&arr, arr.length);
    max(arr);
    min(arr);
    sum(arr);
    average(arr);
    return 0;
}