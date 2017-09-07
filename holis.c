#include <stdio.h>
int main(){
    float x, y;
    int a;
    printf("Dame 2 numeros ");
    scanf("%f,%f",&x,&y);
    if(y==0){
        printf("Numero no valido");
        }
    else{
    printf("Que operacion quiere hacer?\nPulse 1 para sumar\n2 para restar\n3 para multiplicar\n4 para dividir\n");
    scanf("%d",&a);
    switch(a){
        case 1:
            printf("\n\nLa suma es %.3f",x+y);
            break;
        case 2:
            printf("\n\nLa resta es %.3f",x-y);
            break;
        case 3:
            printf("\n\nLa multiplicacion es %.3f",x*y);
            break;
        case 4:
            printf("\n\nLa division es %.3f",x/y);
            break;
        default:
            printf("\n\nBoton no admitido");
            break;
        }
    }
return 0;
}
