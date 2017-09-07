#include <iostream>
using namespace std;
//Listas Circulares
//De: Pablo Velázquez

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
	for(int i=1;i<num;i++){
		q=new Nodo;
		puts("Ingresa un caracter!");
		cin>>q->car;
		t->sig=q;
		t=q;
	}
	t->sig=p;
	return p;
}
//Lista Simplemente Ligada Circular
void exhibeLSLC(Nodo *Prim){
	cout<<"Prim->";
	Nodo *aux=Prim;
	do{
		cout<<"["<<Prim->car <<"|*]->";
		Prim=Prim->sig;
		if (Prim==aux)
			cout<<"["<<Prim->car <<"|*]";
	}while(aux!=Prim);
}

main(){
	Nodo	*Prim;
	Prim=creaLista(10);
	exhibeLSL(Prim);
	fflush(stdin);
	cout<<endl;
	system("pause");
}
