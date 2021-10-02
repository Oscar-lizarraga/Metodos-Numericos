/*****************************************************************
*   Programa para calcular raices por el metodo de Newton Raphson*
*   Autor: Oscar Lizarraga                                       *
******************************************************************/

#include<stdio.h>
#include<math.h>

#define EULER 2.71828

int LeerInt();
double LeerDouble();
void ImprimirFunciones();
double f(double x, int op);
double ImprimirResultado(double f(double x, int op),double a, double eps, int  maxItera, int opcion);
int CifrasCorrectas(double cv, double c);
double derivada(double x, int op);

int main()
{
	double a = 0,b = 0,eps;
	int maxItera, op, r = 0;
	do
  	{
 		ImprimirFunciones();
 		op = LeerInt();
  	}while(op < 1 || op > 5);
  	do
  	{
  		r = 0;
  		printf("\tIngrese la cota inferior Xi: ");
		a = LeerDouble();
		printf("\tIngrese la cota superior Xs: ");
		b = LeerDouble();
		if (f(a,op) * f(b,op) > 0)
		{
			r = 1;
			printf("\tNo hay una raiz en ese intervalo, considere otro\n");
		}
  	}while(r);

  	printf("\tIngrese el error tolerado: ");
  	eps = LeerDouble();
  	printf("\tIngrese el numero de iteraciones maximo: ");
  	maxItera = LeerInt();
  	ImprimirResultado(f,a,eps,maxItera,op);
  	return 0;
}


double ImprimirResultado(double f(double x, int op),double a, double eps, int  maxItera, int opcion)
{
  	int iter = 1, cifras = 0;
  	double c = 0;

  	printf("_____________________________________________________________________________________________________________\n");
  	printf("iter\t Xm\t\t |Er|\t\t Digitos significativos correctos\n");
  	printf("______________________________________________________________________________________________________________\n");
    do
    {
    	if (iter > 1 )
    	{
    		c = a;
    	}
    	a = a - ( f(a,opcion) / derivada(a,opcion) );
    	cifras = CifrasCorrectas(c,a);
      	printf("%d. \t%.10lf \t%.10lf \t%d\n",iter,a,fabs((a - c) / a),cifras);
    	iter++;
    }while(fabs((a - c) / a) >= eps && iter <= maxItera);

    printf("______________________________________________________________________________________________________________\n\n\tUna raiz de la ecuacion es:\n\n\t%.10lf\n\n\n",c);
}

double f(double x, int opcion)
{
	switch(opcion)
	{	
		case 1:
			return (x*x*x);
			break;
		case 2:
			return ((x*x) +4);
			break;
		case 3:
			return ( sin(x) );
			break;
		case 4:
			return (pow(EULER,x) -x );
			break;
		case 5:
			return (pow(x,10) -1);
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
	printf("\n\t[1] x^3 ");
	printf("\n\t[2] x^2+2");
	printf("\n\t[3] sen(x)");
	printf("\n\t[4] e^x -x");
	printf("\n\t[5] x^10-1");		
	printf("\n\n\tIngrese el numero de alguna opcion: ");
}

double derivada(double x, int op)
{
	double h = 1.0e-2;
	return ( (f((x + h), op) - f((x -h), op)) / (2*h) );
}