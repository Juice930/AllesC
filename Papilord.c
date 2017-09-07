/*Programa que lee la calificación de un examen y escribe la calificación no numérica correspondiente*/
#include <stdio.h>
int main(){
    float cal;
    printf("Escribe la calificacion del Examen  ");
    scanf("%f",&cal);
    if(cal<0 || cal>10)/*Las calificaciones van del 0 al 10*/
    {
        printf("\nCalificacion no valida");}
    else{
        if(cal>=0 && cal<5){
            printf("\nNO APROBADO");}
        else{
            if (cal>=5 && cal<7){
                printf("\nAprobado");}
            else{
                if (cal>=7 && cal<9){
                    printf("\nNotable");}
                else{
                    if (cal>=9 && cal<10){
                        printf("\nSobresaliente");}
                    else{
                        if(cal==10){
                            printf("\nExcelente!");}
                        }
                    }
                }
            }
        }
return 0;
}
//PABLO VELÁZQUEZ
