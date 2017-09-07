#include <iostream>

using namespace std;

struct Alfa{
	int *(*pApArApEn)[2];
	int *(*qApFnApEn)(int);
};

int *AlfaFnAp(int A){
	int *p=new int;
	*p=A;
	return p;
}

main(){
	Alfa *pAlfa=new Alfa;
	int A=5,B=10;
	int *X=&A,*Y=&B;
	
	int *Arre[2]={X,Y};
	
	pAlfa->	pApArApEn=(int *(*)[2]) Arre;
	
	cout<<	*(*pAlfa->pApArApEn)[0] <<" "<<*(*pAlfa->pApArApEn)[1]<<"\n";

	pAlfa->qApFnApEn=AlfaFnAp;

	cout<<	*(*pAlfa->qApFnApEn)(12)<<"\n";
	
}
