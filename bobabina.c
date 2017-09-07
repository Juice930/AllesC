#include <stdio.h>
#include <math.h>
#define pi 3.141592

main () {
	float r,n;
	printf("Dame el radio de la bobina\n");
	scanf ("%f", &r);
	printf("Dame el numero de vueltas\n");
	scanf ("%f", &n);
	printf("La cantidad de alambre necesario para fabricar una bobina es %f\n", 2*pi*r*n  );

}