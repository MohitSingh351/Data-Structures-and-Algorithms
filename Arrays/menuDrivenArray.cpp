#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
    void swap1(int *x, int *y) {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
public:
    Array() {   // Non-parameterized constructor
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz) { // Parameterized constructor
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array() {  // Destructor
        delete []A;
    }





void display() {
    for(int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void append(int newElement) {
    if (length >= size) {
        cout << "Array is full" << endl;
    } else {
        A[length] = newElement;
        length++;
        cout << "Element " << newElement <<" appended successfully" << endl;
    }
}

void insert(int index, int newElement) {
    if (index >= 0 && index <= length) {
        for(int i=length;i>index;i--) {
            A[i] = A[i-1];
        }
        A[index] = newElement;
        length++;
        cout << "Element " << newElement << " inserted successfully at index " << index << endl;
    } else {
        cout << "Invalid index" << endl;
    }
}

int deleteElement(int index) {
    int x = 0;
    int i;
    if (index >= 0 && index < length) {
        x = A[index];
        for (i=index; i < length-1; i++) {
            A[i] = A[i+1];
        }
        length--;
        cout << "Element " << x << " deleted successfully" << endl;
        return x;
    }
    return 0;
}

int LinearSearch(int key) {
    for (int i=0;i<length;i++) {
        if (A[i] == key) {
            swap1(&A[i], &A[0]);
            cout << "Element " << key << " found at index " << i << endl;
            return i;
        }
    }
    return -1;
}

// Binary Search
int BinarySearch(struct Array arr, int key) {
    int l = 0;  // low
    int h = length-1;   // high
    int mid;    // middle
    while (l <= h) {
        mid = (l+h)/2;
        if (A[mid] == key) {
            cout << "Element " << key << " found at index " << mid << endl;
            return mid;
        } else if (key < A[mid]) {
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
void reverseArrayM1() {
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--) {
        swap1(&A[i],&A[j]);
    }
}

// Method 2: By swap1ping in a new array
void reverseArrayM2() {
    int *B;
    int i, j;
    B = new int[length];

    for(i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    for(i = 0; i < length; i++) {
        A[i] = B[i];
    }
    delete []B;
}

int get(int index) {
    if (index >= 0 && index < length) {
        cout << "Element at index " << index << " is " << A[index] << endl;
        return A[index];
    }
    return -1;
}

int set(int index, int x) {
    if (index >= 0 && index < length) {
        A[index] = x;
        cout << "Element at index " << index << " is set to " << x << endl;
        return A[index];
    }
    return -1;
}

int max() {
    int max = A[0];
    for(int i=1;i<length;i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    cout << "Maximum element in the array is " << max << endl;
    return max;
}

int min() {
    int min = A[0];
    for(int i=1;i<length;i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    cout << "Minimum element in the array is " << min << endl;
    return min;
}

int sum() {
    int sum = 0;
    for(int i=0;i<length;i++) {
        sum += A[i];
    }
    cout << "Sum of all elements in the array is " << sum << endl;
    return sum;
}

int average() {
    int sum = 0;
    for(int i=0;i<length;i++) {
        sum += A[i];
    }
    cout << "Average of all elements in the array is " << sum/length << endl;
    return sum/length;
}

void createArray() {
    cout << "Enter the size of the array: ";
    cin >> size;
    length = 0;
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> A[i];
    }
    length = size;
}


void sortArray() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (A[i] > A[j]) {
                swap1(&A[i], &A[j]);
            }
        }
    }
}

void MergeArrays(Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = length;
    int n = arr2->length;
    while (i < m && j < n) {
        if (A[i] < arr2->A[j]) {
            A[k++] = A[i++];
        } else {
            A[k++] = arr2->A[j++];
        }
    }

    for (; i < m; i++) {
        A[k++] = A[i];
    }

    for (; j < n; j++) {
        A[k++] = arr2->A[j];
    }

    length = m + n;
}

Array* UnionForSortedArray(Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = length;
    int n = arr2->length;

    struct Array *arr3 = new Array(m+n);

    while (i < m && j < n) {
        if (A[i] < arr2->A[j]) {
            A[k++] = A[i++];
        } else if (A[i] > arr2->A[j]) {
            arr3->A[k++] = arr2->A[j++];
        } else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < m; i++) {
        arr3->A[k++] = A[i];
    }

    for (; j < n; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}

Array* Intersection(Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = length;
    int n = arr2->length;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < m && j < n) {
        if (A[i] < arr2->A[j]) {
            i++;
        } else if (A[i] > arr2->A[j]) {
            j++;
        } else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}

Array* Difference(Array *arr2) {
    int i = 0, j = 0, k = 0;
    int m = length;
    int n = arr2->length;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < m && j < n) {
        if (A[i] < arr2->A[j]) {
            arr3->A[k++] = A[i++];
        } else if (A[i] > arr2->A[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    for (; i < m; i++) {
        arr3->A[k++] = A[i];
    }

    arr3->length = k;
    arr3->size = 10; // Assuming the size of the new array is 10

    return arr3;
}
};

int main() {
    Array *arr1;
    int ch;
    int size, index;
    cout << "Enter the size of the array: ";
    cin >> size;
    arr1 = new Array(size);


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
            cin >> size;
            arr1->append(size);
            break;
        case 2:
            cout << "Enter the index: ";
            cin >> index;
            cout << "Enter the element to insert: ";
            int x;
            cin >> x;
            arr1->insert(index, x);
            break;
        case 3:
            cout << "Enter the index: ";
            cin >> index;
            arr1->deleteElement(index);
            break;
        case 4:
            cout << "Enter the element to search: ";
            cin >> x;
            arr1->LinearSearch(x);
            break;
        case 5:
            arr1->sum();
            break;
        case 6:
            arr1->display();
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (ch != 7);

    delete arr1;    // Deleting the array

    return 0;
}