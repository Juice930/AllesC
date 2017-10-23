#include <stdio.h>
	int n;
	float x=0;

void mean (int i){
	float xi;
	printf ("Dame x%d\n", i);
	scanf ("%f", &xi);
	x+=xi/n;
}

main (){
	int i;
	printf("Dame el valor de n\n");
	scanf ("%d", &n);
	for (i=0;i<n;i++)
		mean (i);
	printf("El promedio de los numeros dados es %f\n", x);	
}