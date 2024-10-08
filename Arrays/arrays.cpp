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

void sortArray(struct Array *arr) {
    for (int i=0;i<arr->length-1;i++) {
        for (int j=i+1;j<arr->length;j++) {
            if (arr->A[i] > arr->A[j]) {
                swap(&arr->A[i], &arr->A[j]);
            }
        }
    }
}

// Binary Search
int BinarySearch(struct Array arr, int key) {
    int l = 0;  // low
    int h = arr.length-1;   // high
    int mid;    // middle
    while (l <= h) {
        mid = (l+h)/2;
        if (arr.A[mid] == key) {
            cout << "Element " << key << " found at index " << mid << endl;
            break;
        } else if (key < mid) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

// Recursive Binary Search
int RBinarySearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l+h)/2;
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            return RBinarySearch(a, l, mid-1, key);
        } else {
            return RBinarySearch(a, mid+1, h, key);
        }
    }
    return -1;
}

int main() {
    struct Array arr;
    createArray(&arr);
    // display(&arr, arr.length);
    // append(&arr, 100);
    // display(&arr, arr.length);
    // insert(&arr, 2, 20);
    // display(&arr, arr.length);
    // deleteElement(&arr, 3);

    sortArray(&arr);
    int key = 5;
    BinarySearch(arr, key);
    display(&arr, arr.length);
    
    return 0;
}