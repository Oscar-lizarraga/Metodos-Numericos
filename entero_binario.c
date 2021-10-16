//Programa de numeros enteros positivos a binario 
//Oscar Lizarraga Pelayo

#include <stdio.h>
#include <stdlib.h>

void imprimirBinario(int n);
int leerNumero();

int main()
{
	int n;

	n = leerNumero();

	printf("\tSu numero en binario es: ");
	imprimirBinario(n);

	return 0;
}

void imprimirBinario(int n)
{
	if(n)
	{
		imprimirBinario(n/2);
		printf("%d",(n % 2));
	}
}

int leerNumero()
{
	int n;
	char a;
	printf("\n\tIngrese un entero positivo: ");
	while(scanf("%d%c",&n,&a) != 2 || a != '\n' || n < 0)
	{
		printf("\tIngreso mal el dato solicitado!");
		printf("\n\tIngrese un entero positivo: ");
		fflush(stdin);
	}
	return n;
}