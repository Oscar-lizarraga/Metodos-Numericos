//Programa de binario a decimal 
//Oscar Lizarraga Pelayo

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int leerNumero();
void imprimirDecimal(int b);

int main()
{

	int b = leerNumero();
	imprimirDecimal(b);

	return 0;
}

int leerNumero()
{
	int n;
	char a;
	printf("\n\tIngrese un numero en binario: ");
	while(scanf("%d%c",&n,&a) != 2 || a != '\n' || n < 0)
	{
		printf("\tIngreso mal el dato solicitado!");
		printf("\n\tIngrese un numero en binario: ");
		fflush(stdin);
	}
	return n;
}

void imprimirDecimal(int b)
{
	int digito, d = 0;
	for (int i = 0; b > 0 ; i++)
	{
		digito = b % 10;
		b = b/10;
		d = d + digito*pow(2,i); 
	}
	printf("\tSu numero en decimal es: %d\n",d);
}