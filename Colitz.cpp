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
class Colas{
public:
	Colas(int);	//void Init(void);
	~Colas(){};	//Destructor
	void Agregar(T A);
	T Retirar(void);
	void Mostrar(void);
	T **colaApApT;
	void MostrarStru(void);
private:
	int Prin;
	int Tope;
	int con;
	int Max;
	bool Empty(void);
	bool Full(void);
};

template <class T>
Colas<T>::Colas(int Max){
	Prin=0;
	con=0;
	Tope=0;
	this->Max=Max;
	colaApApT=new T *[Max];
}

template <class T>
void Colas<T>::Agregar(T A){
	if(!Full()){
		T *p=new T;
		*p=A;
		colaApApT[Tope]=p;
		Tope=Tope+1%Max;
		con++;
	}
	else
		cout<< "Cola Llena\n";
}

template <class T>
T Colas<T>::Retirar(){
	if(!Empty()){
		T *Item=colaApApT[Prin];
		con--;
		Prin=(Prin+1)%Max;
		return *Item;
	}

	else{
		cout<< "Pila Vacia\n";
		exit(1);
	}
}

template <class T>
bool Colas<T>::Empty(void){
	return Tope==-1;
}

template <class T>
bool Colas<T>::Full(void){
	return Tope>Max;
}

template <class T>
void Colas<T>::Mostrar(void){
	int top=Tope;
	cout<<"---"<<endl;
	while(top>Prin)
		cout<<"|"<<*colaApApT[--top]<<"|\n"<<"---\n";
}

template <class T>
void Colas<T>::MostrarStru(void){
	int top=Tope;
	while(top>Prin){
		top--;
		cout<<"---\n";
		cout<< "|"<<colaApApT[top]->X	<<	colaApApT[top]->C <<"|\n";
	}
	cout<<"---\n";
}

main(){
	Colas<int> ColaNum(20);
	Colas<char> ColaChar(20);
	Colas<char> ColaChar2(20);
	Colas<Alfa> ColaAlfa(20);
	
	cout<<"Cola de Numeros!\n";
	for(int i=0; i<10;i++)
		ColaNum.Agregar(i);
	ColaNum.Mostrar();
	cout<<'\n';
	for(int i=0; i<7;i++)
		cout<<ColaNum.Retirar()<<'\n';
	cout<<'\n';
	ColaNum.Mostrar();

	system("Pause");
	system("cls");

	//Imprime caracteres graciosos
	cout<<"Cola de Caracteres Feos!\n";
	for(int i=0; i<10;i++)
		ColaChar.Agregar(i);
		
	ColaChar.Mostrar();
	cout<<'\n';
	for(int i=0; i<3;i++)
		cout<<ColaChar.Retirar()<<'\n';
	cout<<'\n';
	ColaChar.Mostrar();
	
	system("Pause");
	system("cls");

	//No imprime caracteres graciosos
	cout<<"Cola de Caracteres!\n";
	for(int i=0; i<10;i++)
		ColaChar2.Agregar(int('a')+i);
	ColaChar2.Mostrar();
	cout<<'\n';
	for(int i=0; i<4;i++)
		cout<<ColaChar2.Retirar()<<'\n';
	cout<<'\n';
	ColaChar2.Mostrar();

	system("Pause");
	system("cls");

	Alfa H;

	cout<<"Cola de Numeros y Caracteres!\n";
	
	for(int i=0;i<10;i++){
		H.X=i;
		H.C=char(int('a')+i);
		ColaAlfa.Agregar(H);
	}
	
	ColaAlfa.MostrarStru();
	
	cout<<"\n\n";
	
	for(int i=0;i<5;i++)
		ColaAlfa.Retirar();

	ColaAlfa.MostrarStru();
	system("Pause");
}
