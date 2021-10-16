/*****************************************************************
*   Programa para calcular raices por el metodo de secante     *
*   Autor: Oscar Lizarraga                                       *
******************************************************************/

#include<stdio.h>
#include<math.h>

#define EULER 2.71828

int LeerInt();
double LeerDouble();
void ImprimirFunciones();
double f(double x, int op);
double ImprimirBiseccion(double f(double x, int op),double a, double b, double eps, int  maxItera, int opcion);
int CifrasCorrectas(double cv, double c);


int main()
{
	double a = 0,b = 0,eps;
	int maxItera, op;
	do
  	{
 		ImprimirFunciones();
 		op = LeerInt();
  	}while(op < 1 || op > 4);
  	printf("\tIngrese la cota inferior Xi: ");
	a = LeerDouble();
	printf("\tIngrese la cota superior Xs: ");
	b = LeerDouble();

  	printf("\tIngrese el error tolerado: ");
  	eps = LeerDouble();
  	printf("\tIngrese el numero de iteraciones maximo: ");
  	maxItera = LeerInt();
  	ImprimirBiseccion(f,a,b,eps,maxItera,op);
  	return 0;
}


double ImprimirBiseccion(double f(double x, int op),double a, double b, double eps, int  maxItera, int opcion)
{

	double c , c_before, c_after;
	c = a; c_after = b;
  	int iter = 1, cifras = 0;

  	printf("_____________________________________________________________________________________________________________\n");
  	printf("iter\tXi\t\tXs\t\tXm\t\tf(Xm)\t\t|Er|\t\tDigitos significativos correctos\n");
  	printf("______________________________________________________________________________________________________________\n");
    do
    {
    	if (iter > 1 )
    	{
    		c_after = c;
    		c = c_before;
    	}
    	c_before = c - ( ( (c - c_after) / ( f(c,opcion) - f(c_after,opcion) ) ) * f(c,opcion) );
    	cifras = CifrasCorrectas(c_after,c);
      	printf("%d. \t%.10lf \t%.10lf \t%.10lf \t%.10lf \t%.10lf \t%d\n",iter,c_after,c,c_before,f(c_before,opcion),fabs((c_before - c_after) / c_before),cifras);
    	iter++;
    }while(fabs((c - c_after) / c) >= eps && iter <= maxItera);

    printf("______________________________________________________________________________________________________________\n\n\tUna raiz de la ecuacion es:\n\n\t%.10lf\n\n\n",c);
}

double f(double x, int opcion)
{
	switch(opcion)
	{	
		case 1:
			//printf("%lf",((x*x*x) -x -1));
			return 5;
			break;
		case 2:
			return (-2*(x*x*x) -4*(x*x) +4*x +4);
			break;
		case 3:
			return ( x - pow(2,(-x)) );
			break;
		case 4:
			return (pow(EULER,x) + pow(2,(-x)) +2*cos(x) -6);
			//return ((x*x*x) -0.165*(x*x) + .0003993);
			break;
		default:
			break;
	}
}

int CifrasCorrectas(double cv, double c)
{
	int t = 1;
	while( (fabs((c - cv) / c)) < (5*pow(10,(-t))) )
	{
		t++;
	}
	return t;
}


int LeerInt()
{
	int n;
	char a;
	while(scanf("%d%c",&n,&a) != 2 || a != '\n')
	{
		printf("\tIngreso mal el dato solicitado!");
		printf("\n\tVuelta a ingresar: ");
		fflush(stdin);
	}
	return n;
}

double LeerDouble()
{
	double n;
	char a;
	while(scanf("%lf%c",&n,&a) != 2 || a != '\n')
	{
		printf("\tIngreso mal el dato solicitado!");
		printf("\n\tVuelta a ingresar: ");
		fflush(stdin);
	}
	return n;
}

void ImprimirFunciones()
{
	printf("\n\tfunciones disponibles: ");
	printf("\n\t[1] x^3 -x -1");
	printf("\n\t[2] -2x^3 -4x^2 +4x +4");
	printf("\n\t[3] x -2^(-x)");
	printf("\n\t[4] e^x + 2^(-x) + 2cos(x) -6");	
	printf("\n\n\tIngrese el numero de alguna opcion: ");
}