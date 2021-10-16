/*****************************************************************
*   Programa para calcular raices por el metodo de biseccion     *
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
  	do
  	{
  		printf("\tIngrese la cota inferior Xi: ");
		a = LeerDouble();
		printf("\tIngrese la cota superior Xs: ");
		b = LeerDouble();
  	}while(!(f(a,op) * f(b,op) < 0));

  	printf("\tIngrese el error tolerado: ");
  	eps = LeerDouble();
  	printf("\tIngrese el numero de iteraciones maximo: ");
  	maxItera = LeerInt();
  	ImprimirBiseccion(f,a,b,eps,maxItera,op);
  	return 0;
}


double ImprimirBiseccion(double f(double x, int op),double a, double b, double eps, int  maxItera, int opcion)
{
	double c;
  	int iter = 1, cifras = 0;
  	double cv = 0;

  	printf("_____________________________________________________________________________________________________________\n");
  	printf("iter\tXi\t\tXs\t\tXm\t\tf(Xm)\t\t|Er|\t\tDigitos significativos correctos\n");
  	printf("______________________________________________________________________________________________________________\n");
    do
    {
    	if (iter > 1 )
    	{
    		cv = c;
    	}
    	c=(a+b)/2;
    	cifras = CifrasCorrectas(cv,c);
      	printf("%d. \t%.10lf \t%.10lf \t%.10lf \t%.10lf \t%.10lf \t%d\n",iter,a,b,c,f(c,opcion),fabs((c - cv) / c),cifras);
      	if(f(a,opcion)*f(c,opcion)>0)
      	{
      		a=c;
 		}
    	else if(f(a,opcion)*f(c,opcion)<0)
    	{
      		b=c;     		
    	}
    	iter++;
    }while(fabs((c - cv) / c) >= eps && iter <= maxItera);

    printf("______________________________________________________________________________________________________________\n\n\tUna raiz de la ecuacion es:\n\n\t%.10lf\n\n\n",c);
}

double f(double x, int opcion)
{
	switch(opcion)
	{	
		case 1:
			//printf("%lf",((x*x*x) -x -1));
			return ((x*x*x) -x -1);
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