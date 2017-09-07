#include <iostream>
using namespace std;
//Listas ligadas

struct Nodo{
	char car;
	Nodo *sig;
};

struct Testa{
	int n;
	Nodo *sig;
};

Testa *creaLista(int num){
	Testa *T;
	Nodo *p,*q,*t;
	T= new Testa;
	p=new Nodo;
	p=t=q;
	for (int i=1;i<num;i++){
		q=new Nodo;
		puts("Ingresa algo");
		cin>>	q->car;
		t->sig=q;
		t=q;
	}
	T->sig=p;
	T->n=num;
	t->sig=NULL;
	return T;
}
//Lista Simplemente ligada con Testa
void exhibeLSLT(Testa *Prim){
	cout<<"Prim->";
	Nodo *Aux;
	Aux=Prim->sig;
	cout<< "["<<Prim->n<<"<<?"<<"|*]->";
	while(Aux!=NULL){
		if (Aux->sig ==NULL)
			cout<<"["<<Aux->car 	<<"|null]";
		else
			cout<<"["<<Aux->car 	<<"|*]->";
		Aux=Aux->sig;
	}
}

main(){
	Testa	*Prim;
	Prim=creaLista(5);
	exhibeLSLT(Prim);
}
