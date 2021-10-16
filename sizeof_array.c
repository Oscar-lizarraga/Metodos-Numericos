#include<stdio.h>

#include<stdlib.h>

void main(){

    char *ptr = NULL;

    int i = 0;

    int size = 0;

    int n = 0;

    printf("Enter the size of the dynamic array in bytes : ");

    scanf("%d",&n);

    ptr = (char*) calloc (n,sizeof(char));

    for(i=0;i<n;i++){

            size = size + sizeof(ptr[i]);

    }

    printf("Size is %d\n",size);

}