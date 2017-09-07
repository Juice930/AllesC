#include <iostream>
using namespace std;
//Listas ligadas
struct Nodo{
	char car;
	Nodo *sig;
};

Nodo *creaLista(int num){
	Nodo *p,*q,*t;
	p= new Nodo;
	p->car='A';
	p->sig=NULL;
	q=t=p;
	for (int i=1;i<num;i++){
		q=new Nodo;
		puts("Ingresa un caracter!");
		cin>>	q->car;
		t->sig=q;
		t=q;
	}
	t->sig=NULL;
	return p;
}
//Lista Simplemente ligada
void exhibeLSL(Nodo *Prim){
	cout<<"Prim->";
	while(Prim!=NULL){
		if (Prim->sig ==NULL)
			cout<<"["<<Prim->car 	<<"|null]";
		else
			cout<<"["<<Prim->car 	<<"|*]->";
		Prim=Prim->sig;
	}
}

main(){
	Nodo	*Prim;
	Prim=creaLista(5);
	exhibeLSL(Prim);
	fflush(stdin);
	cout<<endl;
	system("pause");
}
