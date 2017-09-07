//Programa que saca la media de los números que están en posiciones impares
#include<stdio.h>
#include<string.h>
int dospuntos3[20];
int i,cant, sum;
float media;
int main(){
do{	printf("Dame tu serie de numeros");
	gets(dospuntos3);
	cant=strlen(dospuntos3);

		for(i=1;i<=cant;i=i+2){
			sum+=dospuntos3[i];}
			}
			while(cant<0);
		media=sum/(cant/2);
	printf("\nLa media es ",media);
return 0;
}
