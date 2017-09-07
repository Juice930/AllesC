#include <iostream>

using namespace std;

struct Alumno{
	char Cal;
	float AlfaRe;
	int Beta[10];
};

struct Gamma{
	int A;
	int *Alfa[5];
};

main(){
	Alumno Lista[10];
	Lista[0].Cal=10;
	for(int i=0;i<10;i++)
		Lista[0].Beta[i]=i+5;
	
	Alumno *p = new Alumno;
	p->Cal='A';
	
	cout<<p->Cal;
}
