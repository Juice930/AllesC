#include <stdio.h>
#include <math.h>
#define g 9.81

main () {
	float vi,t;
	printf("Dame la initial velocity in m/s\n");
	scanf ("%f", &vi);	
	t=vi/g;
	printf("The maximum height of a vertical shot thrown from the ground is %fm\n", vi*t-0.5*g*t*t);
	system ("pause");
}