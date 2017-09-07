//Programa que indica cuántos múltiplos de 3 hay en un vector ya almacenado
#include<stdio.h> 
#include<stdlib.h>
int nums[] = {15, 14, 20, 1, 3, 7, 9, 2, 15}; 
int i, cont=0;
main(){
	for(i=0;i<9;i++){
		if(nums[i]%3==0){
			cont++;}}
printf("El numero total de multiplos de 3 es: %d",cont);
getchar ();
return 0;
}