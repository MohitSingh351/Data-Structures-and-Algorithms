// Finding length of string
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {

    char str[] = "Hello World!";
    int i=0;
    while (str[i] != '\0') {
        i++;
    }
    cout << "Length of string is: " << i << endl;
    return 0;
}