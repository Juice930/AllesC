# include <iostream>
# include <string.h>
using namespace std;

int con=0;

void Mostrar(char **lista){
	for(int i=0;i<con;i++)
			cout<<lista[i]<<endl;
}

main(){
	char **lista=new char*[100];
	while (true){
		char *palabras = new char;
		cout<<"ingrese la palabra\n";
        cin>>palabras;
        if (strcmp("Terminar",palabras)){
        	lista[con]=palabras;
        	con++;
        	Mostrar(lista);
		}
        else
        	break;
    }
	
}
