#include<stdio.h>

int main(){

    char name[20];
    int age;
    FILE *in, *out;

    in = fopen("C:\\Users\\HAIKAL\\GitHub Repo\\SECP1103\\input.dat", "r");
    out = fopen("C:\\Users\\HAIKAL\\GitHub Repo\\SECP1103\\output.out", "w");
    while(!feof(in))
    {
        fgets(name, 20,in);
        fscanf(in, "%d\n", &age);
        printf("nama= %s ", name);
        printf("\t age = %d \n", age);
        fprintf(out, "name= %s\t", name);
        fprintf(out, "age = %d\n", age);
    }
    fclose(in);
    fclose(out);
    return 0;
}