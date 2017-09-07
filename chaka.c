#include <stdio.h>
int main(){
int M[20];
int med;
printf("Escribe algun numero entero");
gets(M);
med=strlen(M);
if(med>2)
	printf("Tu numero tiene mas de dos digitos");
else
	printf("Tu numero no tiene mas de dos digitos");
return 0;
}
