#include <iostream>
//Pila de Pablo Velázquez
using namespace std;

/*
Constructor
1 	Construye el objeto
2	Inicia con valores las variables asociadas a la clase
3	Crea variables dinÃ¡micas

Destructor
1 	Recupera la memoria de las variables dinÃ¡micas
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
	int pila[10];
	int Tope;
	int Max;
	bool Empty(void);
	bool Full(void);
};
	//:: Operador de resoluciÃ³n
Pilas::Pilas(int Max){
	Tope=-1;
	this->Max=Max;
}

void Pilas::Agregar(int A){
	if(!Full())
		pila[++Tope]=A;
	else
		cout<< "Pila Llena\n";
}

int Pilas::Retirar(){
	if(!Empty())
		return pila[Tope--];
	else{
		cout<< "Pila vacia\n";
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
	cout<< "|"<<pila[top--]<<"|\n";
	cout<<"---\n";
	while(top>-1){
		cout<<"|"<<pila[top--]<<"|\n";
		cout<<"---\n";
	}
}

main(){
	Pilas Pila(8);//Este argumento no puede ser mayor a 10, por el tamaaño de pila[10]. Checar PilaDinámica.cpp
	for(int i=0; i<5;i++)
		Pila.Agregar(i);
	Pila.Mostrar();
	cout<<'\n';
	for(int i=0; i<2;i++)
		cout<<Pila.Retirar()<<'\n';
	cout<<'\n';
	Pila.Mostrar();
}
