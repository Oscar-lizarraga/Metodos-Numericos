#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n; 				//grado del polinomio
	float x;			//valor de x en el polinomio
	
	printf("\n\tIngrese el grado del polinomio: ");
	scanf("%d",&n);     

	n++;				//Le sumamos 1, porque 
	float a[n];			//de 0 a n elementos
	for (int i = 0; i < n; i++)
	{
		printf("\n\tcoeficiente x^%i: ",i);
		scanf("%f",&a[i]);
	}
	printf("\n\tIngrese el valor para x: ");
	scanf("%f",&x);
	float p = a[n-1]; //le asignamos el valor del ultimo coeficiente porque A(n) es la ultima iteracion

	for ( int i = (n-1); i > 0; i--)
	{
		p = a[i] + x*p; //esto calculara la P(n) con la P(n-1)   coef + (x)P(n-1);
	}
	printf("\n\t%.2f",p);
	return 0;
}