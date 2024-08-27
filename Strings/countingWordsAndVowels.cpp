// Counting words and vowels in a string

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {

    char str[] = "Mohit Singh";

    int words = 1;
    int vowels = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == ' ') {
            words++;
        }
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowels++;
            }
    }
    cout << "Number of words: " << words << endl;
    cout << "Number of vowels: " << vowels << endl;

    return 0;
}