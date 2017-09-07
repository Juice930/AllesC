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
		//pila[++Tope]=p;
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

	cout<<"---\n";
	cout<< "|"<<*pilaApApT[top--]<<"|\n";
	cout<<"---\n";

	while(top>-1){
		cout<<"|"<<*pilaApApT[top--]<<"|\n";
		cout<<"---\n";
	}

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

main(){
	Pilas<int> PilaNum(20);
	Pilas<char> PilaChar(20);
	Pilas<char> PilaChar2(20);
	Pilas<Alfa> PilaAlfa(20);
	
	cout<<"Pila de Numeros!\n";
	for(int i=0; i<10;i++)
		PilaNum.Agregar(i);
	PilaNum.Mostrar();
	cout<<'\n';
	for(int i=0; i<2;i++)
		cout<<PilaNum.Retirar()<<'\n';
	cout<<'\n';
	PilaNum.Mostrar();

	system("Pause");
	system("cls");

	//Imprime caracteres graciosos
	cout<<"Pila de Caracteres Feos!\n";
	for(int i=0; i<10;i++)
		PilaChar.Agregar(i);
	PilaChar.Mostrar();
	cout<<'\n';
	for(int i=0; i<2;i++)
		cout<<PilaChar.Retirar()<<'\n';
	cout<<'\n';
	PilaChar.Mostrar();
	
	system("Pause");
	system("cls");

	//No imprime caracteres graciosos
	cout<<"Pila de Caracteres!\n";
	for(int i=0; i<10;i++)
		PilaChar2.Agregar(int('a')+i);
	PilaChar2.Mostrar();
	cout<<'\n';
	for(int i=0; i<2;i++)
		cout<<PilaChar2.Retirar()<<'\n';
	cout<<'\n';
	PilaChar2.Mostrar();

	system("Pause");
	system("cls");

	Alfa H;

	cout<<"Pila de Numeros y Caracteres!\n";
	
	for(int i=0;i<10;i++){
		H.X=i;
		H.C=char(int('a')+i);
		PilaAlfa.Agregar(H);
	}
	
	PilaAlfa.MostrarStru();
	
	cout<<"\n\n";
	
	for(int i=0;i<2;i++)
		PilaAlfa.Retirar();

	PilaAlfa.MostrarStru();
	system("Pause");
}
