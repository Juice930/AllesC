#include <iostream>
using namespace std;

int tam;
struct Nodo{
	int len;
	int *arre;
	Nodo *sig;
};

struct SuperNodo{
	int len;
	int *arre;
	Nodo *sig, *bebe;
};

bool vLen(SuperNodo *N,int pos){
	return pos<=N->len/tam;
}

int *Vectoriza(SuperNodo *N,int pos){
	Nodo *aux=N->bebe;
	
	for(int i=1;i<pos;i++)
		aux=aux->sig;		
	return aux->arre;
}

int Buscar(SuperNodo *N, int loc){
	Nodo *aux=N->bebe;
	cout<<"Buscando\t";
	loc--;
	if (loc!=tam)
		for(int i=0;i<loc/tam;i++)
			aux=aux->sig;
	return aux->arre[loc%tam];
}

void Mostrar(SuperNodo *N){
	int j=0;
	Nodo *aux=N->bebe;
		cout<<'\n';
		for(int i=0;i<tam*3-1;i++)
			cout<<'-';
		cout<<'\n';
		cout<<'|';
		for(int i=0;i<N->len;i++){
			cout<<aux->arre[i%tam]<<"|";
			if((i+1)%tam==0 && i!=0){
				aux=aux->sig;
				cout<<'\n';
				for(int i=0;i<tam*3-1;i++)
					cout<<'-';
				cout<<"\n|";
				j++;
			}
		}
	cout<<'\n';
}

void AgregaNum(SuperNodo *N,int n){
	if(N->bebe==NULL){
		Nodo *s=new Nodo;
		s->arre=new int[tam];
		s->len=1;
		s->arre[0]=n;
		s->sig=NULL;
		N->sig=s;
		N->bebe=N->sig;
	}
	else
		if (N->len%tam!=0){
			N->sig->arre[(N->len)%tam]=n;
			N->sig->len++;
		}
		else{
			N->sig->sig=new Nodo;
			N->sig->sig->arre=new int[tam];
			N->sig->sig->len=1;
			N->sig->sig->arre[0]=n;
			N->sig->sig->sig=NULL;
			N->sig=N->sig->sig;
		}
	N->len++;
}
void Busqueda(SuperNodo *Super){
	int n;
	char op;
	
	cout<<"\nEn donde quieres buscar?\t";
	cin>>n;
	if(n<=Super->len && n>0)
		cout<<"\nTu numero es "<<Buscar(Super,n)<<'\n';
	else
		cout<<"\nNo metiste tantos numeros!!!\n";	
}

void Suma(SuperNodo *N){
	int V1,V2;
	cout<<"\nQue vectores quieres sumar?\n";
	cin>>V1>>V2;
	cout<<'\n';
	
	if(vLen(N,V1) && vLen(N,V2)){
		int *Vector1=Vectoriza(N,V1);
		int *Vector2=Vectoriza(N,V2);
		cout<<"La Suma es:\n";
		for(int i=0;i<tam;i++)
			cout<<Vector1[i]+Vector2[i]<<"  ";
		cout<<'\n';
	}
	
	else
		cout<<"\nNo existen esos vectores!\n";
}

void Resta(SuperNodo *N){
	int V1,V2;
	cout<<"\nQue vectores quieres restar?\n";
	cin>>V1>>V2;
	cout<<'\n';
	
	if(vLen(N,V1) && vLen(N,V2)){
		int *Vector1=Vectoriza(N,V1);
		int *Vector2=Vectoriza(N,V2);
		cout<<"La Resta de V1-V2 es:\n";
		for(int i=0;i<tam;i++)
			cout<<Vector1[i]-Vector2[i]<<"  ";
		cout<<'\n';
	}
	
	else
		cout<<"\nNo existen esos vectores!\n";
}

void Escalar(SuperNodo *N){
	int V,x;
	cout<<"\nQue vector quieres escalar?\n";
	cin>>V;
	fflush(stdin);
	
	if(vLen(N,V)){
		cout<<"\nMultiplicar por... ";
		cin>>x;
		int *Vector1=Vectoriza(N,V);
		cout<<"El nuevo vector es:\n";
		for(int i=0;i<tam;i++)
			cout<<Vector1[i]*x<<"  ";
		cout<<'\n';
	}
	
	else
		cout<<"\nNo existe ese vector!\n";
}

void Punto(SuperNodo *N){
	int V1,V2;
	cout<<"\nQue vectores quieres multiplicar?\n";
	cin>>V1>>V2;
	cout<<'\n';
	int total=0;
	if(vLen(N,V1) && vLen(N,V2)){
		int *Vector1=Vectoriza(N,V1);
		int *Vector2=Vectoriza(N,V2);
		for(int i=0;i<tam;i++)
			total+=Vector1[i]*Vector2[i];
		cout<<"El producto punto da:\t"<<total;
		cout<<'\n';
	}
	else
		cout<<"\nNo existen esos vectores!";
}

main(){
	SuperNodo *Super=new SuperNodo;
	Super->len=0;
	Super->sig=NULL;
	Super->bebe=NULL;
	int n;
	char op;
	tam=-1;
	while(tam<1){
	cout<<"De que tamano quieres tus vectores?";
	cin>>tam;
	}
	while(true){
		cout<<"Dame un numero...\t";
		cin>>n;
		AgregaNum(Super,int(n));
		Mostrar(Super);
		cout<<"Quieres agregar otro num?\t";
		cin>>op;
		if(op=='N' || op=='n')
			break;
	}
	while(true){
		system("cls");
		cout<<"Tus numeros";
		Mostrar(Super);
		cout<<"\nQue quieres hacer?\n1\tBuscar\n2\tSuma\n3\tResta\n4\tProducto por un escalar\n5\tProducto Punto\n6\tSalir\n";
		cin>>op;
		switch (op){
			case '1':
				Busqueda(Super);
				system("pause");
				break;
			case '2':
				Suma(Super);
				system("pause");
				break;
			case '3':
				Resta(Super);
				system("pause");
				break;
			case '4':
				Escalar(Super);
				system("pause");
				break;
			case '5':
				Punto(Super);
				system("pause");
				break;
			case '6':
				exit(0);
			}
	}
}
