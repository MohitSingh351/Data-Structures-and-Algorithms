// Reversing a string

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseStringM1(char *str) {
    for (int i=strlen(str); i>=0; i--) {
        cout << str[i];
    }
}

void reverseStringM2(char *str) {
    int length = strlen(str);
    char *revStr = new char[length + 1];
    for (int i=0; i<length; i++) {
        revStr[i] = str[length-i-1];
    }
    revStr[length] = '\0'; // Null-terminate the reversed string    
    cout << revStr;
    delete[] revStr;
}

void reverseStringM3(char *str) {
    int length = strlen(str);
    for (int i=0; i<length/2; i++) {
        swap(&str[i], &str[length-i-1]);
    }
    cout << str;
}

int main() {

    char str[] = "Mohit";
    reverseStringM1(str);

    cout << endl;

    char str2[] = "Mohit";
    reverseStringM2(str2);

    cout << endl;

    char str3[] = "Mohit";
    reverseStringM3(str3);

    return 0;
}