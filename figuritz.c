//Programa para calcular el área de un triángulo, un rectángulo o un circulo
#include <stdio.h>
#define pi 3.1416
int main(){
    float b, h, a;
    char e;
prin:    
printf("Al area de que figura le quieres sacar el area?\nPulsa R para rectangulo\nT para triangulo\nC para circulo\n");
    scanf("%c",&e);
    switch(e){
        case 'r': case 'R':
            printf("Dame base y altura\t");
            scanf("%f,%f",&b,&h);
            a=b*h;
            printf("El area es: %.2f",a);
            break;
        case 't': case 'T':
            printf("Dame base y altura\t");
            scanf("%f,%f",&b,&h);
            a=b*h/2;
            printf("El area es: %.2f",a);
            break;
        case 'c': case 'C':
            printf("Dame el radio del circulo\t");
            scanf("%f",&b);
            a=(pi*b*b)/2;
            printf("El area es: %.2f",a);
            break;
        default:
            printf("No se que figura es esa\n\n\n");
            goto prin;
	break;
        }
    return 0;
}
