#include <stdio.h>
#include <conio.h>
#include <iostream>
#include<stdlib.h>

using namespace std;

void AlfaFn(int XEn){
	printf("%d",XEn);
}

int *SumaFnApEn(int AEn, int BEn){
	int *pApEn=new int;
	*pApEn=AEn+BEn;
	return pApEn;
}
int *RestaFnApEn(int AEn, int BEn){
	int *pApEn=new int;
	*pApEn=AEn-BEn;
	return pApEn;
}
int *ProductoFnApEn(int AEn, int BEn){
	int *pApEn=new int;
	*pApEn=AEn*BEn;
	return pApEn;
}
int *DivisionFnApEn(int AEn, int BEn){
	int *pApEn=new int;
	*pApEn=AEn/BEn;
	return pApEn;
}

main(void){
	int *(*pApFnApEn)(int, int)=SumaFnApEn;
	int *(*qApFnApEn)(int, int)=RestaFnApEn;
	int *(*rApFnApEn)(int, int)=ProductoFnApEn;
	int *(*tApFnApEn)(int, int)=DivisionFnApEn;
	
	int *(*XArApFnApEn[4])(int, int)={pApFnApEn,qApFnApEn,rApFnApEn,tApFnApEn};
	
	int *(*(*pApArApFnApEn)[4])(int, int)=(int *(*(*)[4])(int, int)) XArApFnApEn;
	
	cout<<*(*(*pApArApFnApEn)[0])(2, 3)<<"\n";
	puts("");
	cout<<*(*(*pApArApFnApEn)[1])(7, 3)<<"\n";
	puts("");	
	cout<<*(*(*pApArApFnApEn)[2])(5, 3)<<"\n";
	puts("");
	cout<<*(*(*pApArApFnApEn)[3])(3, 2)<<"\n";
	puts("");
	
}
