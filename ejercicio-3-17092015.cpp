#include <stdio.h>
#include <conio.h>
#include <iostream>
#include<stdlib.h>


using namespace std;

int *(*AlfaFnApArApEn(void))[4]{
     int *(*pApArApEn)[4]=(int *(*)[4])new(int*[4]);
     int *pApEn=new int;
     int *qApEn=new int;
     int *rApEn=new int;
     int *sApEn=new int;
     
     cout << "Ingresa cuatro valores enteros\n";
     cin >> *pApEn >> *qApEn >> *rApEn >> *sApEn;
     
     (*pApArApEn)[0]=pApEn;
     (*pApArApEn)[1]=qApEn;
     (*pApArApEn)[2]=rApEn;
     (*pApArApEn)[3]=sApEn;
     
     return pApArApEn;
}

main(void){
	int *(*pApArApEn)[4]=AlfaFnApArApEn();
	
	cout<<*(*pApArApEn)[0] << *(*pApArApEn)[1] << *(*pApArApEn)[2] << *(*pApArApEn)[3];

}
