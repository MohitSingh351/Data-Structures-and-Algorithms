#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// Checking duplicate character in a string by compairing each character with all other characters
void checkDuplicateM1(char *str) {
    int i, j;
    int length = strlen(str);
    for(i=0; i<length;i++) {
        for(j=i+1; j<length; j++) {
            if (str[i] == str[j]) {
                cout << "Duplicate character found: " << str[i] << endl;
            }
        }
    }
}

// Checking duplicate character in a string by using hash table
// FOR ALL LOWERCASE ALPHABETS(ASSUMING)
void checkDuplicateM2(char *str) {
    int i, length;
    length = strlen(str);
    int hash[26] = {0};
    for(i=0; i<length-1; i++) {
        hash[str[i] - 'a']++;
    }
    for(i=0; i<26; i++) {
        if (hash[i] > 1) {
            cout << "Duplicate character found: " << (char)(i + 'a') << endl;
        }
    }
}

// Checking duplicate character in a string by using bitwise operation
// FOR ALL LOWERCASE ALPHABETS(ASSUMING)
-

int main() {

    char str[] = "hhello";
    checkDuplicateM1(str);
    cout << endl;
    checkDuplicateM2(str);
    return 0;
}