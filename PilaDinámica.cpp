#include <iostream>

using namespace std;

/*
Constructor
1 	Construye el objeto
2	Inicia con valores las variables asociadas a la clase
3	Crea variables dinámicas

Destructor
1 	Recupera la memoria de las variables dinámicas
2	Destruye el objeto
*/

class Pilas{
public:
	Pilas(int);	//void Init(void);
	~Pilas(){};	//Destructor
	void Agregar(int A);
	int Retirar(void);
	void Mostrar(void);
private:
	int **pilaApApEn;
	int *pila[10];
	int Tope;
	int Max;
	bool Empty(void);
	bool Full(void);
};
	//:: Operador de resolución
Pilas::Pilas(int Max){
	Tope=-1;
	this->Max=Max;
	pilaApApEn=new int *[Max];
}

void Pilas::Agregar(int A){
	if(!Full()){
		int *p=new int;
		*p=A;
		pilaApApEn[++Tope]=p;
	}
	else
		cout<< "Pila Llena\n";
}

int Pilas::Retirar(){
	if(!Empty()){
		return *pilaApApEn[Tope--];
	}
	else{
		cout<< "Pila Vacia\n";
		exit(1);
	}
}

bool Pilas::Empty(void){
	return Tope==-1;
}

bool Pilas::Full(void){
	return Tope>Max;
}

void Pilas::Mostrar(void){
	int top=Tope;

	cout<<"---\n";
	cout<< "|"<<*pilaApApEn[top--]<<"|\n";
	cout<<"---\n";

	while(top>-1){
		cout<<"|"<<*pilaApApEn[top--]<<"|\n";
		cout<<"---\n";
	}

}

main(){
	Pilas Pila(20);
	for(int i=0; i<5;i++)
		Pila.Agregar(i);
	Pila.Mostrar();
	cout<<'\n';
	for(int i=0; i<2;i++)
		cout<<Pila.Retirar()<<'\n';
	cout<<'\n';
	Pila.Mostrar();
}