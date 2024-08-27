// Validating a string

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int valid(char *name) {
    for(int i=0; i<strlen(name); i++) {
        if(name[i] >= 'a' && name[i] <= 'z') {
            continue;
        } else if(name[i] >= 'A' && name[i] <= 'Z') {
            continue;
        } else if(name[i] >= '0' && name[i] <= '9') {
            continue;
        } else if (name[i] == ' ') {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {

    char name[] = "Mohit Singh";
    if (valid(name)) {
        cout << "Valid String" << endl;
    } else {
        cout << "Invalid String" << endl;
    }

    return 0;
}