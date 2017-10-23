#include <stdio.h>
#include <math.h>
#define g 9.81
#define pi 3.141592

float radin (float ang){
	return ang*pi/180;
}

main (){
	float Vo, a, dt, t=0, x, y;
	printf("Hola amor, dime, a que velocidad iniciamos?\n");
	scanf("%f", &Vo);
	printf("Recuerdame, cual era nuestro angulo?\n");
	scanf("%f", &a);
	a=radin(a);//Radianiza a
	printf("En que intervalo de tiempo transcurre nuestro amor?\n");
	scanf("%f", &dt);
	while(t<=2*Vo*sin(a)/g){//tmax=2*Vo*sin(a)/g;
		x=Vo*cos(a)*t;
		y=-g*t*t/2+Vo*sin(a)*t;
		printf("t=%f:\tx=%f\ty=%f\n", t,x,y);
		t+=dt;//t=t+dt;
	}
	system("pause");
}
