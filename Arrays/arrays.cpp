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

// function to create an array
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

void append(struct Array *arr, int newElement) {
    if (arr->length > arr->size) {
        cout << "Array is full" << endl;
    } else {
        arr->A[arr->length] = newElement;
        arr->length++;
        cout << "Element " << newElement <<" appended successfully" << endl;
    }
}

void insert(struct Array *arr, int index, int newElement) {
    if (index >= 0 && index <= arr->length) {
        for(int i=arr->length;i>index;i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = newElement;
        arr->length++;
        cout << "Element " << newElement << " inserted successfully at index " << index << endl;
    } else {
        cout << "Invalid index" << endl;
    }
}

int deleteElement(struct Array *arr, int index) {
    int x = 0;
    int i;
    if (index >= 0 && index < arr-> length) {
        x = arr->A[index];
        for (i=index; i < arr->length-1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        cout << "Element " << x << " deleted successfully" << endl;
        return x;
    }
    return 0;
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key) {
    for (int i=0;i<arr->length;i++) {
        if (arr->A[i] == key) {
            swap(&arr->A[i], &arr->A[0]);
            cout << "Element " << key << " found at index " << i << endl;
            return i;
        }
    }
    return -1;
}

int main() {
    struct Array arr;
    createArray(&arr);
    display(&arr, arr.length);
    append(&arr, 10);
    display(&arr, arr.length);
    insert(&arr, 2, 20);
    display(&arr, arr.length);
    deleteElement(&arr, 3);

    int key = 10;
    int index = LinearSearch(&arr, key);
    display(&arr, arr.length);
    
    return 0;
}