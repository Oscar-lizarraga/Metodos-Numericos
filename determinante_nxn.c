//Programa para calcular el determinante de una matriz de nxn


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeerEntero(int* a);
void LeerArreglo(int **m, int c, int r);
int ConstruirArreglo(int **m, int c, int r);
void LimpiarCadena(char *cadena);


int main(int argc, char const *argv[])
{
	int** m;
	int c = 0, r = 0;

	printf("\n\t Ingrese el numero de columnas: ");
	LeerEntero(&c);
	printf("\n\t Ingrese el numero de renglones: ");
	LeerEntero(&r);

	if(ConstruirArreglo(m,c,r)){
		printf("\t Se creo el arreglo\n\t");


	}
	else{
		printf("ERROR: No hay memoria suficiente! ");
	}
	LeerArreglo(m,c,r);



}


void LeerEntero(int *a)
{
	char b;
	while(scanf("%d%c",a,&b) != 2 || b != '\n' || *a < 0)
	{
		printf("\t Ingreso mal el dato solicitado!, Vuelva a ingresarlo: ");
		fflush(stdin);
	}
}

void LeerArreglo(int** m, int c, int r)
{
	char* matriz = (char*)calloc(2*c,sizeof(char));			
	for (int i = 0; i < c; i++)
	{
		fgets(matriz,(2*c)+1,stdin);
		fflush(stdin);

		for (int j = 0; j < c; j++)
		{
			printf("%d\n",matriz[j*2] - 48);
			m[i][j] = (matriz[j*2] -48);
		}	
	}
}

int ConstruirArreglo(int** m, int c, int r)
{
	m = (int**)calloc(c, sizeof(int*));
	if(m == NULL) return 0;
	for (int i = 0; i < c; i++)
	{
		m[i] = (int*)calloc(r,sizeof(int));
		if(m[i] == NULL){
			return 0;
		}
	}
}

void LimpiarCadena(char *cadena)
{
	int longitud = strlen(cadena);
	if (longitud > 0 && (cadena[longitud - 1] == '\n'))
	{
		cadena[longitud - 1] = '\0';
	}
}




