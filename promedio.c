#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
float funm (int x); 
float media (int x); 
float desv (int x); 
float dest (int x); 
float mecu (int x);
float meha (int x);
int n;
int Ele[40];
void main (void){
	printf("Numero total de numeros\n");
	scanf("%d",&n);
for (int i=0;i<n;i++){
        printf("\nEscribe el elemento %d de tu vector: ",i+1);
        scanf("%d",&Ele[i]);
		}
    printf("\nEl valor de la media (m) es: %.2f", funm (n));
	printf("\nEl valor de la desviacion media es: %.2f", desv (n));
	printf("\nEl valor de la desviacion tipica es: %.2f",dest (n));
	printf("\nEl valor de la media cuadratica es: %.2f",mecu (n));
	printf("\nEl valor de la media harmonica es: %.2f",meha (n));
}
float funm (int n){
float acum=0;
float Res;
for (int i=0;i<n;i++){
        acum+=Ele[i];
		}
Res=acum/n;
    return Res;
}
float desv (int n){
float acum=0, res, m, abso;
m=funm (n);
for(int i=0;i<n;i++){
	abso=(Ele[i]-m);
	acum+=labs (abso);}
res=acum/n;
return res;
}
float dest (int n){
float acum=0, res, m;
m=funm (n);
for(int i=0;i<n;i++){
	acum+=pow (Ele[i]-m,2);}
res=sqrt(acum/n);
return res;
}
float mecu (int n){
float acum=0, res;
for(int i=0;i<n;i++){
	acum+=pow (Ele[i],2);}
res=sqrt(acum/n);
return res;
}
float meha (int n){
float acum=0, res;
for(int i=0;i<n;i++){
	acum+=(1/Ele[i]);}
res=n/acum;
return res;
}