#include <stdio.h>
void entrada_Lista();
void burbuja(int a[]);
void seleccion (int a[]);
void insercion(int a[],int n);
int n,y=0;
int a[];
int main(){
int opcion;
printf("Cuanto mide tu arreglo");
scanf("%d",&n);
entrada_Lista(n);
printf("Como quieres ordenar tu arreglo? (1 para Burbuja, 2 para selección, 3 para inserción");
scanf("%d",&opcion);
switch(opcion){
	case 1:
		burbuja(a[]);
		break;
	case 2:
		seleccion(a[]);
		break;
	case 3:
		insercion(a[],n);
		break;
	default:
		printf("No conozco ese metodo");
		break;}
printf("\nTu arreglo ordenado es\n");
for(y=0;y<n;y++)
printf("%d",a[i]);
}
void entrada_Lista(int a[])
{
int i;
printf("\nEntrada de los elementos\n");
for(i=0;i<n; i++){
printf("\na[%d]= ",i+1);
scanf("%d",a+i);
}
}
void burbuja(int a[]){
         int i, j, aux;
         for(i=0;i<A.length-1;i++)
              for(j=0;j<A.length-i-1;j++)
                   if(A[j+1]<A[j]){
                      aux=A[j+1];
                      A[j+1]=A[j];
                      A[j]=aux;
                   }
}
void seleccion(int a[]) 
{ 
int i, j, min, A[N], aux; 
for (i=1;i <= N; i++) { 
	min = i; 
	j = i + 1; 
for (j=1;j <= N; j++) { 
	if(A[j] < A[i]) 
	{ 
		min = j; 
		aux = a[i]; 
		a[i] = a[min]; 
		a[min] = aux; }
} 
} 
}
void insercion (int a[], int tam)
{
 int i ,  j , valorBusqueda; 
 for(i = 1; i < tam; i++) 
 {
  valorBusqueda = a[i];
  for (j = i - 1; j >= 0 && a[j] > valorBusqueda; j--)
  {
   a[j + 1] = a[j];
  }
  a[j + 1] = valorBusqueda;
 }
 val = a[i];
 }