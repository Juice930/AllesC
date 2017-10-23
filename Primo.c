#include <stdio.h>

int main(){
	int i=2,j,p,n;
	printf ("Cuantos numeros primos necesitas?\n");
	scanf ("%d",&n);
	printf ("Los numeros solicitados por su servilleta son los siguientes:\n");
	
	while (n>0){
		p=1;				//p=1 significa que es primo
		for (j=2; j<i; j++){
			if(i%j==0){
				p=0;		//p=0 es antiprimo
				break;
			}
		}
		if (p==1){
			printf ("%i, ",i);
			n--;
		}
		i++;
	}
	return 0;
}
