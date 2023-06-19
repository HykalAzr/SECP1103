#include<stdio.h>

int main(){

    char name[20];
    int age;
    FILE* in;

    in = fopen("C:\\Users\\HAIKAL\\GitHub Repo\\SECP1103\\input.dat", "r");
    while(!feof(in))
    {
        fscanf(in, "%s %d\n", name, &age);
        printf("nama= %s ", name);
        printf("\t age = %d \n", age);
    }
    fclose(in);
    return 0;
}