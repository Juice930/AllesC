#include <stdio.h>
#include <math.h>

main() {

float r,h,pi;
pi=3.1416;
printf("Dame el radio ahora\n");
scanf("%f",&r);
printf("Gimme' the height\n");
scanf("%f",&h);
//printf("Dame el radio y la height (r,h)\n");
//scanf("%f,%f",&r,&h);
printf("El volumen de un cilindro de radio %f y altura %f es %f u^3\n", r,h,pi*r*r*h );
system("pause");
}