//Tarea 2: Programa que calcula la suma de 1/k para k = {1,2,...n}
//para el sistema de F(10,3,-9,9)
//Autor: Oscar Lizarraga Pelayo

//la cardinalidad del sistema esta dado por 2(B-1)*B^(t-1)(U-L+1)+1
//esto nos da 2(10-1)*10^(3-1)(9-9+1)+1 = 34,201 numeros

//En los numeros positivos 
//el minimo es .100x10^(-9) = .0000000001
//el maximo es .999x10^(9) = 999000000

//En los numeros negativos
//el maximo es -.100x10^(-9) = -.0000000001
//el minimo es -.999x10^(9) = -999000000

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//double suma = 0, minimo = .100e-9;  //con un float es mas que suficiente para representar la suma
	//printf("%.10lf"	,minimo);
	float i = 1;
	int resp = 1;
	float suma = 0;
	char redondeado[16];

	do
	{
		resp = 0;
		suma = suma + (1/i);
		printf("\n\tla iteracion k= %.1f",i);
		sprintf(redondeado,"1/k = %.2E",(1/i));
		printf("%s",&redondeado);
		printf("\n\tla suma es = %.2e\n",suma);
		printf("\n\tIngrese 1 para otra iteracion y 0 para salir: ");
		scanf("%d",&resp);
		i = i + 1;
	}while(resp == 1);

	/*while(suma != .0000000001)
	{
		resp = 0;
		suma = suma + (1/i);
		printf("\n\tla iteracion k= %.1e, 1/k = %.1e",i,(1/i));
		printf("\n\tla suma es = %.10e\n",suma);
		printf("\n\tIngrese 1 para otra iteracion y 0 para salir: ");
		scanf("%d",&resp);
		i = i + 1;
	}*/
	return 0;
}