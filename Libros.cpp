#include <iostream>
#include <string.h>
using namespace std;
//Clase de Pila de Libros de Pablo Velázquez
class Libros{
public:
	void Iniciar(char[20],char[20]);
	void Exhibe(void);
private:
	char Autor[20];
	char Titulo[20];
};

void Libros::Iniciar( char titulo[20], char autor [20]){
	strcpy(Autor,autor);
	strcpy(Titulo,titulo);
}

void Libros::Exhibe(void){
	cout<<Titulo<<"\n";
	cout<<Autor<<"\n";
}

main(void){
	Libros Libro;
	Libro.Iniciar("Mecanica Cuantica","Pancho");
	Libro.Exhibe();
}
