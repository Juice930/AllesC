#include <stdio.h>
#include <string.h>
int Arr[50];
int cambianumero ();
int imprimidor ();
int main(){
printf("Dame tu numero");
gets(Arr);
cambianumero();
imprimidor();
getchar();
}
int imprimidor () {
int i=0, med;
printf("\nTu numero cambiado es \n");
med=strlen(Arr);
for(i=0;i<med;i++){
	printf("%d",Arr[i]);
}
}
int cambianumero (){
int i=0, med;
med=strlen(Arr);
for(i=0;i<med;i++){
	if(Arr[i]==0)
		Arr[i]=9;
	if(Arr[i]==1)
		Arr[i]=5;
	if(Arr[i]==2)
		Arr[i]=4;
	if(Arr[i]==3)
		Arr[i]=2;
	if(Arr[i]==4)
		Arr[i]=7;
	if(Arr[i]==5)
		Arr[i]=6;
	if(Arr[i]==6)
		Arr[i]=1;
	if(Arr[i]==7)
		Arr[i]=3;
	if(Arr[i]==8)
		Arr[i]=0;
	if(Arr[i]==9)
		Arr[i]=8;}
}