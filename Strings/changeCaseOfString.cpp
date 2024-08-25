// Changing case of a string
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {

    char str[] = "MOHIT";
    for (int i=0; i<strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        } else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    cout << str << endl;

    return 0;
}