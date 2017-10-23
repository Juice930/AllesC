#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int n;
	do{
		printf ("De que tamanio es tu matriz?");
		scanf ("%d", &n);
		fflush(stdin);
	}while(n<0);  //El do while lo repite hasta que la pipol teclee un num positive, como un quark up! No es necesario ponerlo, porque, quien va a querer una matriz imaginaria?
	
	int A[n][n], i, j;
	srand(time(0));
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++){
			if (i<=j){
				A[i][j]=rand()%21;
			}else {
				A[i][j]=0;
			}
		}
		
	printf("Esto es A:\n");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
	
	int k=0;
	int array[(n*(n+1))/2];
	for (i=0; i<n; i++)
		for (j=i; j<n; j++)
			array[k++]=A[i][j];
	
	printf ("El arreglo de la matriz triangular sup es\n");
	for (i=0; i<k; i++)
		printf ("%d ", array[i]);

	return 0;	
}
