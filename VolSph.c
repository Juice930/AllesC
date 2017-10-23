#include <stdio.h>
#define pi 3.141592

float Kugel (float); 
//hola Salu2

main (){
float r;
	printf("Gimme' the radius now!");
	scanf ("%f",&r);
	printf ("The volume of the sphere with radius %f, is %f\n", r, Kugel(r));
	system("Pause");
}

float Kugel (float r){
	printf("Hola, soy Kugel\n");//Esfera en alemán
	return 4./3*pi*r*r*r;
}
//chau