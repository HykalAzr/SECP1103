#include <stdio.h>
#include <string.h>

void changeName(char names[][25], int size);

int main() {
    // Define an array of strings to store the names of your friends
    char friends[5][25] = {
        "AHMED MAAROF",
        "ALYZBETH",
        "ASYURIZAN",
        "CHEAH",
        "KAI EN"
    };

    // Print the names
    printf("Original Names:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", friends[i]);
    }
    
    // Change the names using the function
    changeName(friends, 5);

    // Print the names after the change
    printf("\nModified Names:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", friends[i]);
    }

    return 0;
}

void changeName(char names[][25], int size) {
    // Modify the ith name in the array
    int i = 1;
    strcpy(names[i], "HAIKAL AZHAR");
}






