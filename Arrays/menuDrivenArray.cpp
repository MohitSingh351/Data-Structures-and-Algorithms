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

void swap1(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void display(struct Array *arr) {
    for(int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

void append(struct Array *arr, int newElement) {
    if (arr->length >= arr->size) {
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

int LinearSearch(struct Array *arr, int key) {
    for (int i=0;i<arr->length;i++) {
        if (arr->A[i] == key) {
            swap1(&arr->A[i], &arr->A[0]);
            cout << "Element " << key << " found at index " << i << endl;
            return i;
        }
    }
    return -1;
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
            return mid;
        } else if (key < arr.A[mid]) {
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

// Method 1: By swap1ping in the same array
void reverseArrayM1(struct Array *arr) {
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--) {
        swap1(&arr->A[i],&arr->A[j]);
    }
}

// Method 2: By swap1ping in a new array
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


void sortArray(struct Array *arr) {
    for (int i = 0; i < arr->length - 1; i++) {
        for (int j = i + 1; j < arr->length; j++) {
            if (arr->A[i] > arr->A[j]) {
                swap1(&arr->A[i], &arr->A[j]);
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
    }

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}

int main() {

    struct Array arr;
    int ch;
    int x, index;
    createArray(&arr);
    display(&arr);

    do
    {
        cout << "MENU" << endl;
        cout << "1. Append" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Search" << endl;
        cout << "5. Sum" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element to append: ";
            cin >> x;
            append(&arr, x);
            break;
        case 2:
            cout << "Enter the index: ";
            cin >> index;
            cout << "Enter the element to insert: ";
            cin >> x;
            insert(&arr, index, x);
            break;
        case 3:
            cout << "Enter the index: ";
            cin >> index;
            deleteElement(&arr, index);
            break;
        case 4:
            cout << "Enter the element to search: ";
            cin >> x;
            LinearSearch(&arr, x);
            break;
        case 5:
            sum(arr);
            break;
        case 6:
            display(&arr);
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (ch != 7);

    return 0;
}