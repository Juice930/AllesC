#include <iostream>
#include <string.h>
#include <math.h>
#include "PilaGenerica.hpp"
using namespace std;

char Uno[]={"12345678"};
char Dos[]={"987654"};

struct Nodo
{
	int Num;
	Nodo *ap;	
};

int Convertir(int x,int i){
	return int(x/pow(10,i)) % 10;
}

void Mostrar(Nodo *Ap,Nodo *p){
	do{
		cout<<"["<<p->Num<<"|*]->";
		p=p->ap;
		if(Ap->ap==p)
			cout<<"["<<p->Num<<"]";
	}while(Ap->ap!=p);
	puts("\n");
}

char *InttoChar(Nodo *n,int nod,int sob){
	char *v=new char;
	int *num=new int;
	Pilas <int> PilaEnt(nod);
	if(sob!=0)	nod--;
	//cout<<"\n\n"<<nod*5+sob<<"\n\n";
	
	Pilas <char> PilaCar(nod*5+sob);
	char arre[nod*5+sob], aux[nod*5+sob];
	
	int x,j=0;
	n=n->ap;
	
	do{
		PilaEnt.Agregar(n->Num);
	//	cout<<n->Num<<"->";
		n=n->ap;
	}while(n->Num!=-1);
	
	while(!PilaEnt.Empty()){
		x=PilaEnt.Retirar();
		for(int i=log10(x);i>=0;i--)
			PilaCar.Agregar(Convertir(x,i));
	}
	
	while(!PilaCar.Empty())
		arre[j++]=PilaCar.Retirar()+char('0');
	
	for(int i=0;i<strlen(arre);i++)
		aux[strlen(arre)-i-1]=arre[i];
	//cout<<'\n'<<strlen(aux);
	v=aux;
	//cout<<'\n'<<"ARRE..."<<arre<<'\n';
	cout<<'\n'<<"V..."<<v<<'\n';
	return v;
}

void Resultado(Nodo *p,Nodo *q,Nodo *r){
	// printf("Resultado!\n");
	// p=p->ap;
	// do{
	// 	printf("%5d",p->Num);
	// 	p=p->ap;
	// }while(p->Num!=-1);
	// printf("\n+\n");
	// q=q->ap;
	// do{
	// 	printf("%5d",q->Num);
	// 	q=q->ap;
	// }while(q->Num!=-1);
	// printf("\n-----------------------\n");
	// r=r->ap;
	// do{
	// 	printf("%5d",r->Num);
	// 	r=r->ap;
	// }while(r->Num!=-1);
	
}

Nodo *Suma(Nodo *p, Nodo *q){
	p=p->ap;
	q=q->ap;
	Nodo *r=new Nodo;
	Nodo *s,*t;
	Nodo *w;
	int sob=0,res;
	s=t=r;
	r->Num=-1;
	do{
		res=p->Num+q->Num+sob;
		sob=res/100000;
		res=res%100000;
		t=new Nodo;
		s->ap=t;
		t->Num=res;
		p=p->ap;
		q=q->ap;
		s=t;
	}while(p->Num!=-1 && q->Num!=-1);

	if(p->Num==-1 && q->Num==-1){
		t->ap=r;
		return r;
	}
	
	if(p->Num==-1)
		w=q;
	else
		w=p;
	do{
		res=w->Num+sob;
		sob=res/100000;
		res=res%100000;
		t=new Nodo;
		t->Num=res;
		s->ap=t;
		w=w->ap;
		s=t;
	}while(w->Num!=-1);
	cout<<sob<<'\n';

	if(sob!=0){
			t=new Nodo;
			t->Num=sob;
			s->ap=t;
			s=t;
	}
	t->ap=r;
	return r;
}

Nodo *Resta(Nodo *p, Nodo *q){
	p=p->ap;
	q=q->ap;
	Nodo *r=new Nodo;
	Nodo *s,*t;
	Nodo *w;
	int sob=0,res;
	s=t=r;
	r->Num=-1;
	do{
		sob=res/100000;
		res=res%100000;
		if(p->Num<q->Num){
			p->Num+=100000;
			p->ap->Num-=1;
		}
		res=p->Num-q->Num;

		t=new Nodo;
		s->ap=t;
		t->Num=res;
		p=p->ap;
		q=q->ap;
		s=t;
	}while(p->Num!=-1 && q->Num!=-1);

	if(p->Num==-1 && q->Num==-1){
		t->ap=r;
		return r;
	}
	
	if(p->Num==-1)
		w=q;
	else
		w=p;

	do{
		res=w->Num-sob;
		sob=res/100000;
		res=res%100000;
		t=new Nodo;
		t->Num=res;
		s->ap=t;
		w=w->ap;
		s=t;
	}while(w->Num!=-1);
	
	if(sob!=0){
			t=new Nodo;
			t->Num=sob;
			s->ap=t;
			s=t;
	}
	t->ap=r;
	return r;
}

int parse(char c[],int ex){
	int aux=0;
	int a=strlen(c)-ex-5;
	for(int i=strlen(c)-1-ex;i>=a;i--){
		aux+=(int(c[i])-int('0'))*pow(10,(strlen(c)-1-i)%5);
		if(i==0)
			break;
	}
	return aux;
}

main(){
	char A[100],B[100];
	long numA,numB;
	int Nod1=strlen(Uno)/5, Nod2=strlen(Dos)/5;
	int Sob1=strlen(Uno)%5, Sob2=strlen(Dos)%5;

	if(Sob1!=0)
		Nod1++;
	if(Sob2!=0)
		Nod2++;

	int *U= new int;
	int *D= new int;

	for(int i=Nod1;i>=0;i--)
		U[i]=parse(Uno,i*5);
	
	for(int i=Nod2;i>=0;i--)
		D[i]=parse(Dos,i*5);

	for (int i=0;i<Nod1;i++)
		cout<<U[i]<<'\n';
	cout<<'\n';
	for (int i=0;i<Nod2;i++)
		cout<<D[i]<<'\n';

	Nodo *p,*q,*r;
	Nodo **NU,**ND;
	NU=new Nodo*;
	ND=new Nodo*;
	p=new Nodo;
	q=new Nodo;
	r=new Nodo;

	for(int i=0;i<Nod1;i++){
		NU[i]=new Nodo;
		NU[i]->Num=U[i];
	}

	for(int i=0;i<Nod2;i++){
		ND[i]=new Nodo;
		ND[i]->Num=D[i];
	}

	p->ap=NU[0];
	q->ap=ND[0];
	p->Num=-1;
	q->Num=-1;

	for(int i=0;i<Nod1;i++)
		if(i==Nod1-1)
			NU[i]->ap=p;
		else
			NU[i]->ap=NU[i+1];

	for(int i=0;i<Nod2;i++)
		if(i==Nod2-1)
			ND[i]->ap=q;
		else
			ND[i]->ap=ND[i+1];
			
	Nodo *Apu=new Nodo;
	Apu->ap=p;
	Mostrar(Apu,p);
	Apu->ap=q;
	Mostrar(Apu,q);
	
	Nodo *R=Suma(p,q);
	Apu->ap=R;
	Mostrar(Apu,R);
	
	char **Res=new char*;
	
	Res[0]=InttoChar(p,Nod1,Sob1);
	Res[1]=InttoChar(q,Nod2,Sob2);
	Res[2]=InttoChar(R,Nod1+Nod2,Sob1+Sob2);
	cout<<Res[1]<<'\n';
	for(int i=0;i<3;i++){
		for(int j=0;j<strlen(Res[i]);j++)
			cout<<Res[i][j]<<',';
		cout<<endl;
	}
	//Res[2]=InttoChar()
	
	
	//R=Resta(p,q);
	//Apu->ap=R;
	//Mostrar(Apu,R);

	//Resultado(p,q,R);
	//char *Sol=InttoChar(p,Nod1,Sob1);
	//for(int i=0;i<Nod1*5+Sob1;i++)
	//	printf("%c",*Sol);
}
