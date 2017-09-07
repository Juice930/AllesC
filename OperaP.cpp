#include <iostream>
#include <string.h>
#include "PilaGenerica.hpp"
using namespace std;
/*
Programa que evalúa una expresión
Hecho por: Pablo Velázquez
05/11/2015
*/
bool Operando(char c){
		return (c>=65 && c<=90) || (c>=97 && c<=122) ||	(c>=48 && c<=57);
}

bool Operador(char c){
		return (c=='*' || c=='/' || c=='+' || c=='-');
}

float eval(float A, float B, char op){
	switch(op){
		case '+':return A+B;
		case '-':return A-B;
		case '*':return A*B;
		case '/':return A/B;
	}
}

float evalFn(char *str,float *N, Pilas <float> Pilitz){
	int i=0;
	float A,B,Res;
	
	while(str[i++]!='\0')
		if(Operando(str[i-1]))
			Pilitz.Agregar(N[int(str[i-1])-int('a')]);
		else if(Operador(str[i-1])){
			B=Pilitz.Retirar();
			A=Pilitz.Retirar();
			Res=eval(A,B,str[i-1]);
			Pilitz.Agregar(Res);
		}
		else{
			cout<<"\nCARACTER NO ACEPTABLE!  "<<str[i-1];
			exit(0);
		}
	return Pilitz.Retirar();
}

main(){
	char *string=new char;
	char opcion;
	Pilas <float> PilaFloat(20);
	float aux;
	float *arreAux=new float;
	float *arreNum;
	int J=0;
	
	while(true){
		cout<<"Dame la expresion!\t\n";
		cin>>string;
		for(int i=0;i<strlen(string);i++)
			if(Operando(string[i])){
				cout<<"\n"<<string[i]<<"=\t";
				cin>>aux;
				PilaFloat.Agregar(aux);
			}
		
		while(!PilaFloat.Empty())
			arreAux[J++]=PilaFloat.Retirar();
			
		arreNum=new float [J];
	
		for(int i=0;i<J;i++)
			arreNum[i]=arreAux[J-1-i];
		
		cout<<"El resultado es "<<evalFn(string,arreNum,PilaFloat);
		cout<<"\nQuieres intentar otra vez?";
		cin>>opcion;
		if(opcion=='N' || opcion=='n')	break;
		J=0;
	}
}
