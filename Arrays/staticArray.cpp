#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main() {
    int A[5] = {2, 4, 6, 8, 10};    // Static Array
    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}