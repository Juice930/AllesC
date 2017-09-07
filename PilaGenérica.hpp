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

struct Alfa{
	int X;
	char C;
};

struct Beta{
	Beta *p1, *p2;
	char Dato;
};

template <class T>
class Pilas{
public:
	Pilas(int);	//void Init(void);
	~Pilas(){};	//Destructor
	void Agregar(T A);
	T Retirar(void);
	void Mostrar(void);
	T **pilaApApT;
	void MostrarStru(void);
	void MostrarStru2(void);
private:
	int Tope;
	int Max;
	bool Empty(void);
	bool Full(void);
};
	//:: Operador de resolución
template <class T>
Pilas<T>::Pilas(int Max){
	Tope=-1;
	this->Max=Max;
	pilaApApT=new T *[Max];
}

template <class T>
void Pilas<T>::Agregar(T A){
	if(!Full()){
		T *p=new T;
		*p=A;
		pilaApApT[++Tope]=p;
	}
	else
		cout<< "Pila Llena\n";
}

template <class T>
T Pilas<T>::Retirar(){

	if(!Empty())
		return *pilaApApT[Tope--];

	else{
		cout<< "Pila Vacia\n";
		exit(1);
	}
}

template <class T>
bool Pilas<T>::Empty(void){
	return Tope==-1;
}

template <class T>
bool Pilas<T>::Full(void){
	return Tope>Max;
}

template <class T>
void Pilas<T>::Mostrar(void){
	int top=Tope;

	cout<<"---\n"<< "|"<<*pilaApApT[top--]<<"|\n"<<"---\n";

	while(top>-1)
		cout<<"|"<<*pilaApApT[top--]<<"|\n"<<"---\n";

}

template <class T>
void Pilas<T>::MostrarStru(void){
	int top=Tope;

	cout<<"---\n";
	cout<< "|"<<pilaApApT[top]->X	<<	pilaApApT[top]->C <<"|\n";
	cout<<"---\n";
	top--;
	while(top>-1){
		cout<< "|"<<pilaApApT[top]->X	<<	pilaApApT[top]->C <<"|\n";
		top--;
		cout<<"---\n";
	}

}

template <class T>
void Pilas<T>::MostrarStru2(void){
	int top=Tope;

	cout<<"---\n";
	cout<< "|*|"	<<	*pilaApApT[top]->p1 <<"->|"<<pilaApApT[top]->Dato<<"\n";
	cout<<"---\n";
	top--;
	while(top>-1){
		cout<< "|*|"<<*pilaApApT[top]->p1 <<"->|"<<pilaApApT[top]->Dato<<"\n";
		top--;
		cout<<"---\n";
	}

}
