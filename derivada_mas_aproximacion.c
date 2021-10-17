/*Programa para calcular la derivada en un punto*/
//https://stackoverflow.com/questions/1559695/implementing-the-derivative-in-c-c

#include <stdio.h>


double derivada(double x);
double f(double x);

int main(int argc, char const *argv[])
{
	printf("%.15lf\n", derivada(2));
	printf("%.10lf\n", derivada(2));

	return 0;
}

double derivada(double x)
{
	double h = 1.0e-2;
	return ( (f(x + h) - f(x -h)) / (2*h) );
}

double f(double x)
{
	return (-16*(x*x) + 512);
}