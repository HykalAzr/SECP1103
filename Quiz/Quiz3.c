#include <stdio.h>

/*
Written by: Haikal Azhar (A20EE0254)
Date: 28/6/2023
*/

int avgArray (int userNums[], int SIZE);

int main() {
    const int SIZE = 10;
    int userNums[SIZE];
    printf ("Enter 10 numbers: ");
    for (int count = 0; count < SIZE; count++){
        printf("#%d", (count + 1));
        scanf("%d", &userNums[count]);
    }
    printf("The average of those numbers is ");
    int avg = avgArray(userNums, SIZE);
    printf ("%d\n", avg);
    return 0;
}

int avgArray (int userNums[], int Size){

    int total = 0, result = 0;

    for (int i = 0; i < Size; i++){
        total = total + userNums[i];
    }

    result = total / Size;

    return result;
}