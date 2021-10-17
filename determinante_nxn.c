/***********************************************************
 * Metodos numericos, Programa para el calculo del determinante 
 * por recursividad de una matriz de nxn
 * 
 * Fecha de ultima revision: 16/10/21
 * 
 * Autor:
 * Lizarraga Pelayo Oscar
 * *********************************************************/

#include <stdio.h>
#include <stdlib.h>

double** ConstruirMatriz(int, int);
double CalcularDeterminante(int, int, double**);
void LeerMatriz(char, int, int, double**);
void ImprimirMatriz(int, int, double**);
void DestruirMatriz(int, double**);
void LeerEntero(int* a);

int main(void)
{
	double **A;
	int M, N;
	printf("Renglones de la matriz: \n");
	LeerEntero(&M);
	printf("Columnas de la matriz: \n");
	LeerEntero(&N);

	printf("Construyendo la matriz A... \n");
	A = ConstruirMatriz(M, N);

	printf("Introduzca los elementos ...\n");
	LeerMatriz('A', M, N, A);

	printf("Los elementos de la matriz son: \n");
	ImprimirMatriz(M, N, A);

	printf("\nEl determinante es: %.5lf"	,CalcularDeterminante(M,N,A));
	DestruirMatriz(M, A);

	return 0;
}

double CalcularDeterminante(int m, int n, double** mat)
{
	if(n == 0 || n != m) return 0.0;			//Si la matriz no es cuadrada su det es 0
	if(n == 1 && m == 1) return mat[0][0];		//Si la matriz es de dim 1, su determinante es el mismo elemento
	double determinante = 0.0;
	for (int k = 0; k < n; k++)
	{
		double** mat_a = ConstruirMatriz(m-1,n-1); //crearemos una matriz con una dimension menor
		for (int i = 0; i < m-1 ; i++)
		{
			for (int j = 0; j < n-1; j++)	//Aqui asignaremos los valores de la matriz original a la matriz con dimension menor
			{
				if(j < k){mat_a[i][j] = mat[i+1][j];}		
				else{mat_a[i][j] = mat[i+1][j+1];}		
			}
		}
		if (k % 2 == 0){ // aqui tomaremos el cambio de signo para el coeficiente 
			determinante+= mat[0][k]*CalcularDeterminante(m-1,n-1,mat_a); //aqui hacemos la llamada recursiva
		}
		else{
			determinante-= mat[0][k]*CalcularDeterminante(m-1,n-1,mat_a);
		}
	}
	return determinante;
}


/*Este metodo crea una matriz dinamica, primero se crea una matriz aux que sera devuelta
si no se pudo reservar la memoria con longitud de m-renglones entonces su valor sera NULL y
se devolvera, despues en cada renglon reservamos memoria para cada columna*/
double** ConstruirMatriz(int m, int n)
{
	double** mat = (double**)calloc(m, sizeof(double*));	
	if (mat == NULL) exit(0);
	for (int i = 0; i < m; i++)
	{
		mat[i] = (double*)calloc(n, sizeof(double));
		if (mat[i] == NULL)
		{
			printf("Error de asignacion de memoria\n");
			exit(0);
		}
	}
	return mat;
}

void LeerMatriz(char ch, int m, int n, double **mat)
{
	char str[128];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c(%d,%d) = ?", ch, i + 1, j + 1);
			fgets(str, sizeof(str), stdin);
			mat[i][j] = (double)atof(str);
		}
	}
}

void DestruirMatriz(int m, double** mat)
{
	for (int i = 0; i < m; i++)
	{
		free(mat[i]);
	}
	free(mat);
}


void ImprimirMatriz(int m, int n, double **mat)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\t%.2lf", mat[i][j]);
		}
		printf("\n");
	}
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





