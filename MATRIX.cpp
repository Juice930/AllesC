#include <stdio.h>
int main();//Declaramos main porque la llamamos en las otras funciones
void Suma(void){
	int A[3][3],B[3][3],i,j;
	for (i=0; i<=2; i++)
		for (j=0; j<=2; j++){
			printf("Rola los coeficientes de A%d%d\n", i,j);
			scanf("%d", &A[i][j]);
		}
	printf("Esto es A:\n");
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++){
			printf("Rola los coeficientes de B%d%d\n", i,j);
			scanf("%d", &B[i][j]);
		}
	}
	printf("Esto es B:\n");
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", B[i][j]);
		printf("\n");
	}
	//Cuando los loops no tienen {} es porque incluyen una sola instrucción
   	for (i=0; i<=2; i++)
		for (j=0; j<=2; j++)
			A[i][j]+=B[i][j];
			
	printf("La suma de A y B es\n");
	
	  for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
	main();
}
void Transponer(void){
	int A[3][3],B[3][3],i,j;
	for (i=0; i<=2; i++)
		for (j=0; j<=2; j++){
			printf("Rola los coeficientes de A%d%d\n", i,j);
			scanf("%d", &A[i][j]);
	}
	 for (i=0; i<=2; i++)
		for (j=0; j<=2; j++)
			B[i][j]=A[j][i];
	printf("La matriz transpuesta de A es\n");
	
	  for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", B[i][j]);
		printf("\n");
	}
	main();
}
void Multiplicar(void){
	int A[3][3],B[3][3],C[3][3],i,j,k;
	
	for (i=0; i<=2; i++)
		for (j=0; j<=2; j++){
			printf("Rola los coeficientes de A%d%d\n", i,j);
			scanf("%d", &A[i][j]);
		}
	printf("Esto es A:\n");
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++){
			printf("Rola los coeficientes de B%d%d\n", i,j);
			scanf("%d", &B[i][j]);
		}
	}
	printf("Esto es B:\n");
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", B[i][j]);
		printf("\n");
	}
	//Iniciando C con 0
	for (i=0; i<=2; i++)
		for (j=0; j<=2; j++)
			C[i][j]=0;
			
	//Multiplicandito
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			for (k=0; k<=2; k++)
				C[i][j]+=A[i][k]*B[k][j];
	}
	
	printf("La multiplicacion de A por B es\n");
	
	for (i=0; i<=2; i++){
		for (j=0; j<=2; j++)
			printf("%d\t", C[i][j]);
		printf("\n");
	}
	main();
}
int main(){
char Op;			//para guardar caracteres 
printf ("Quieres sumar (s), transponer (t) o multiplicar (m) matrices? Para salir (n)\n");
fflush(stdin);		//Limpia el buffer del teclado
scanf ("%c", &Op);

if (Op=='s')
	Suma();
else if (Op=='t')
	Transponer();
else if(Op=='m')
	Multiplicar();
else if(Op=='n')
	return 0;
else
	main();
}
