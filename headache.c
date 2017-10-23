#include <stdio.h>
#include <math.h>

float Re,Im;//Variables Globales

void chicharronera (float a,float b,float c, int complex){
	if (complex==0){
		Re=(-b+sqrt(b*b-4*a*c))/(2*a);
		Im=(-b-sqrt(b*b-4*a*c))/(2*a);//No es imaginario, pero ahorro variables
	}
	else if(complex==1){
		Re=-b/(2*a);
		Im=sqrt(4*a*c-b*b)/(2*a);
	}
}

main (){
	float a,b,c;
	printf ("Q 11 con el 12?, esto te resuelve la equation ax^2+bx+c=0.\nDame a, b, y c.\n" );
	scanf ("%f,%f,%f", &a, &b, &c);
	if(b*b-4*a*c>=0){
		chicharronera(a,b,c,0);
		printf ("Las raices son x1=%f, y x2=%f\n", Re,Im);
	}
	else{
		chicharronera(a,b,c,1);
		printf("Las raices complejas son x1=%f + %fi y x2=%f + %fi\n", Re,Im,Re,-Im);
	}
	system("pause");
}