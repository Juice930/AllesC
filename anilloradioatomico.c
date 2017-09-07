#include <stdio.h>
#include <math.h>
#define pi 3.141592
main () {
	float r1, r2;

	printf("Dame el radius chico\n");
	scanf("%f", &r1);
	printf("Dame el radius grande\n");
	scanf("%f", &r2);
	printf("El area de tu anillo es %f\n", pi*r2*r2-pi*r1*r1);
	system("pause");
}