//Oscar Lizarraga Pelayo
//Conversor de numeros enteros en base 10, a base 2


#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,nc,p=0;
    int *m;
    printf("Ingrese un entero: ");
    scanf("%i", &n);

    nc = n;
    m = (int*)malloc(sizeof(int));


    if (m == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        while(n)
        {   
            m[p] = (n % 2);
            n = n/2;
            p++;
            m = (int*)realloc(m,(p + 1)* sizeof(int));
        }

        if (nc>0)
        {
            printf("\n");
            for (int i = (p-1); i >= 0 ; i--)
            {
                printf("%d",m[i]);
            }
        }
        else
        {

        }
    }

    free(m);
    return 0;
}

