#include <iostream>
using namespace std;

int(*(*CreaVector(void))[10])[10]{
	int m=0;
	int (*(*p)[10])[10]=(int(*(*)[10])[10]) new (int(*[10])[10]);
	for(int i=0;i<10;i++)
		(*p)[i]=(int(*)[10])new int[10];
	for(int k=0;k<10;k++)
		for(int j=0;j<10;j++)
			(*(*p)[j])[k]=m++;
	return p;
}

main(){
	int (*(*p)[10])[10]=CreaVector();
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			cout<<*p[i][j]<<' ';
		cout<<'\n';
	}
}
