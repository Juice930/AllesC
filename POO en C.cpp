#include <iostream>
using namespace std;
void Imprim(int X){
	printf("%d\n",X);
}

int *Alfa(int x, int y){

	//*pApEn = x+y;
	//return pApEn;
	int *p;
	*p=x+y;
	return p;
}

int *Beta(int x, int y){
	int *p;
	*p=x-y;
	return p;
}

int *Gamma(int x, int y){
	int *p;
	*p=x*y;
	return p;
}

int *Delta(int x, int y){
	int *p;
	*p=x/y;
	return p;
}

main(){
	int A,B;
	void (*p)(int)=Imprim;	//p es de tipo void y recibe un entero;
	void (*q)(int)=Imprim;

	puts("Dame los valores de A y B");
	scanf("%d,%d",&A,&B);
	p(A);
	q(B);
	int i;

	int *(*Suma)(int,int)=Alfa;
	int *(*Rest)(int,int)=Beta;
	int *(*Mult)(int,int)=Gamma;
	int *(*Divi)(int,int)=Delta;
	
	printf("%d",*Divi(A,B));

	int *(*XArApFnApEn[4])(int,int)={Suma,Rest,Mult,Divi};
	printf("\nLOCURA %d",*(XArApFnApEn[2])(A,B))	;
	//int (*ApFn)(int,int)= *XArApFnApEn;
	//for(i=0;i<4;i++)
//		printf("%d\n", *(ApFn(A,B))[i] );
	//int *(*(*pApArApFnApEn[4]))(int,int)= int *(*(*[4])(int,int)) XArApFnApEn;
	//puts("Sobreviviste!");
	//printf("%d\n\n",*(pApArApFnApEn[0] (A,B)));
	
	//for(i=0;i<4;i++)
	//	printf("%d\n", *(*pApArApFnApEn)[i] (A,B) );
}
