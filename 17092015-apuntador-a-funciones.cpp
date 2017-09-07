#include <iostream>

using namespace std;

void AlfaFnApEn(int XEn){
	printf("%d",XEn);
}

int *FnApEn(int AEn, int BEn){
	int *pApEn=new int;
	*pApEn=AEn+BEn;
	return pApEn;
}
main(void){
	int AEn, BEn;
	void (*pApEn)(int)=AlfaFnApEn;
	void (*qApEn)(int)=AlfaFnApEn;
//************************************************************
    cout<<"Apuntador a funcion que no devuelve nada\n";
//************************************************************   
	cout<<"Ingresa el valor de A y B\n";
	cin>> AEn>>BEn;

	pApEn(AEn);
	puts("\n");
	qApEn(BEn);
	puts("\n");
//************************************************************	
	cout<<"Funcion que devuelve un apuntador a un entero\n\n";
//************************************************************
	AlfaFnApEn(AEn);
//************************************************************
    cout<<"\nApuntador a funcion que devuelve un apuntador a un entero\n";
//**************************************************************
    int *(*pApFnApEn)(int, int)= (int *(*)(int, int)) FnApEn;
    puts("\n\n");
    cout<<*(*pApFnApEn)(AEn, BEn)<<"\n";
	puts("\n");
	system("pause");
	
}

/*p es un Apuntador a un Arreglo de Apuntadores
Funciones, dos argumentos Enteros, que devuleve un 
Apuntador a un Entero*/
