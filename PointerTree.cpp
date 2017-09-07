#include <iostream>
#include <string.h>
#include "PilaGenerica.hpp"
//Árbol
//De: Pablo Velázquez
using namespace std;

bool Operando(char c){
		return (c>=65 && c<=90) || (c>=97 && c<=122) ||	(c>=48 && c<=57);
}

bool Operador(char c){
		return (c=='*' || c=='/' || c=='+' || c=='-');
}

struct Nodo{
	Nodo *pIzq, *pDer;
	char Dato;
};

void prefija(Nodo *Raiz){
	if(Raiz!=NULL){
		cout<<Raiz->Dato<<'\t';
		prefija(Raiz->pIzq);
		prefija(Raiz->pDer);
	}
}
void prefijaInv(Nodo *Raiz){
	if(Raiz!=NULL){
		prefijaInv(Raiz->pDer);
		prefijaInv(Raiz->pIzq);
		cout<<Raiz->Dato<<'\t';
	}
}

void infija(Nodo *Raiz){
	if(Raiz!=NULL){
		infija(Raiz->pIzq);
		cout<<Raiz->Dato<<'\t';
		infija(Raiz->pDer);
	}
}

void infijaInv(Nodo *Raiz){
	if(Raiz!=NULL){
		infijaInv(Raiz->pDer);
		cout<<Raiz->Dato<<'\t';
		infijaInv(Raiz->pIzq);
	}
}

void posfija(Nodo *Raiz){
	if(Raiz!=NULL){
		cout<<Raiz->Dato<<'\t';
		posfija(Raiz->pIzq);
		posfija(Raiz->pDer);
	}
}

void posfijaInv(Nodo *Raiz){
	if(Raiz!=NULL){
		posfijaInv(Raiz->pDer);
		posfijaInv(Raiz->pIzq);
		cout<<Raiz->Dato<<'\t';
	}
}

main(){
	Pilas <Nodo*> Pila(20);
	char *string=new char;
	cout<<"Dame la Expresion a evaluar"<<endl;
	cin>>string;
	Nodo *t,*sI,*sD,*s,*n;
	int i=0;
	n=new Nodo;
	
	while(string[i]!='\0'){
		
		if(Operando(string[i])){
			t=new Nodo;
			t->Dato=string[i];
			t->pIzq=NULL;
			t->pDer=NULL;
			Pila.Agregar(t);
		}
		
		else if(Operador(string[i])){
				sD=Pila.Retirar();
				sI=Pila.Retirar();
				s=new Nodo;
				s->Dato=string[i];
				s->pIzq=sI;
				s->pDer=sD;
				Pila.Agregar(s);
			}
		
		else{
			cout<<"Eh?";
			system("pause");
			exit(1);
		}
		i++;
	}

	n=Pila.Retirar();
	cout<<"\nPrefija\n";
	prefija(n);
	cout<<"\nPrefija Inversa\n";
	prefijaInv(n);
	cout<<"\nInfija\n";
	infija(n);
	cout<<"\nInfija Inversa\n";
	infijaInv(n);
	cout<<"\nPosfija\n";
	posfija(n);
	cout<<"\nPosfija Inversa\n";
	posfijaInv(n);
	cout<<endl;
	system("pause");
}
