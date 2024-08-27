#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void compareStrings(char *str1, char *str2) {
    int i = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i]) {
                cout << "String 1 is smaller" << endl;
            } else {
                cout << "String 2 is smaller" << endl;
            }
            return;
        }
        i++;
    }
    
    if (str1[i] == '\0' && str2[i] == '\0') {
        cout << "Strings are equal" << endl;
    } else if (str1[i] == '\0') {
        cout << "String 1 is smaller" << endl;
    } else {
        cout << "String 2 is smaller" << endl;
    }
}

void checkPalindromeM1(char *str) {
    int i=0;
    int j = strlen(str) - 1;
    while(i<j) {
        if (str[i] == str[j]){
            i++;
            j--;
        } else {
            cout << "Not a palindrome" << endl;
            return;
        }
    }
    cout << str << " is a palindrome" << endl;
}

void checkPalindromeM2(char *str) {
    int i;
    int length = strlen(str);
    int j=length - 1;
    char *revStr = new char[strlen(str) + 1];

    for(i=0; i<length; i++){
        revStr[i] = str[length-i-1];
    }
    revStr[length] = '\0';

    while(i<j) {
        if (str[i] == str[j]){
            i++;
            j--;
        } else {
            cout << "Not a palindrome" << endl;
            return;
        }
    }
    cout << str << " is a palindrome" << endl;

    delete [] revStr;
}

int main() {
    char str1[] = "Mohia";
    char str2[] = "Mohit";
    compareStrings(str1, str2);

    cout << endl;
    cout << "Palindrome check" << endl;
    char str3[] = "Mohit";
    checkPalindromeM1(str3);
    checkPalindromeM2(str3);
    return 0;
}
