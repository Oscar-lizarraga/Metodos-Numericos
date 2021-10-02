#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	float x;
	printf("\n\tIngrese el grado del polinomio: ");
	scanf("%i",&n);

	n++;
	float a[n];
	for (int i = 0; i < n; i++)
	{
		printf("\n\tcoeficiente x^%i: ",i);
		scanf("%f",&a[i]);
	}
	printf("\n\tIngrese el valor para x: ");
	scanf("%i",&x);
	float p = a[n];

	for ( int i = (n-1); i > 0; i--)
	{
		p = a[i] + x*p;
	}
	printf("\n\t%.2f",p);
	return 0;
}