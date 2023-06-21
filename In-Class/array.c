#include<stdio.h>

int main(){
    const int SIZE = 5;
    int arr[SIZE];
    
for(int n = 0; n < 5; n++){
    arr[n] = n * n;
    printf("arr%d = %d\n", n+1, arr[n]);
}

    return 0;
}