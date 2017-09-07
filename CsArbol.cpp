#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <string.h>
#include "LCP.hpp"

using namespace std;

struct EsRaiz{
    char CaraCa;
    EsRaiz *LigaIzqApEsRaiz;
    EsRaiz *LigaDerApEsRaiz;
};

class CsArbol{
    public:
    CsArbol (char[]);
    ~CsArbol(void){}
    EsRaiz *CreaArbolFaApEsRaiz(void);
    void PreOrdenFa(EsRaiz *);
    void EnOrdenFa(EsRaiz *);
    void PostOrdenFa(EsRaiz *);
    void PreOrdenInvFa(EsRaiz *);
    void EnOrdenInvFa(EsRaiz *);
    void PostOrdenInvFa(EsRaiz *);
    private:
    EsRaiz *pApEsRaiz;
    char ExpPostfija[12];
    CsPilas<EsRaiz*> LaPila;
    bool EsOpdoFaBo(char);
    bool EsOpdorFaBo(char);
};

CsArbol::CsArbol(char expPostfija[12]){
    strcpy(ExpPostfija, expPostfija);


}

EsRaiz *CsArbol::CreaArbolFaApEsRaiz(void){
    char CaraCa;
    EsRaiz *tApEsRaiz;
    EsRaiz *s1ApEsRaiz;
    EsRaiz *s2ApEsRaiz;
    EsRaiz *s3ApEsRaiz;
    int iEn = 1;
    CaraCa=ExpPostfija[0];
    while (CaraCa != '\0'){
    if(EsOpdoFaBo(CaraCa)){
        tApEsRaiz = new EsRaiz;
        tApEsRaiz-> CaraCa = CaraCa;
        tApEsRaiz-> LigaDerApEsRaiz=NULL;
        tApEsRaiz-> LigaIzqApEsRaiz=NULL;
        LaPila.AgregaFa(tApEsRaiz);
    }else {
        s1ApEsRaiz=LaPila.RemueveFaGn();
        s2ApEsRaiz=LaPila.RemueveFaGn();
        s3ApEsRaiz=new EsRaiz;
        s3ApEsRaiz-> CaraCa= CaraCa;
        s3ApEsRaiz->LigaDerApEsRaiz= s1ApEsRaiz;
        s3ApEsRaiz->LigaIzqApEsRaiz= s2ApEsRaiz;
        LaPila.AgregaFa(s3ApEsRaiz);
    }
    CaraCa=ExpPostfija[iEn++];
    }
      pApEsRaiz = LaPila.RemueveFaGn();
      return pApEsRaiz;
}
 // Se Visita Raiz
 void CsArbol::PreOrdenFa(EsRaiz *pApEsRaiz){
    if(pApEsRaiz != NULL){                         //¿Apuntador no es nulo?
        cout << pApEsRaiz ->CaraCa<<" ";            // Se vista raiz
        PreOrdenFa(pApEsRaiz->LigaIzqApEsRaiz);
        PreOrdenFa(pApEsRaiz->LigaDerApEsRaiz);
    }
 }

 void CsArbol::EnOrdenFa(EsRaiz *pApEsRaiz){
    if(pApEsRaiz != NULL){                         //¿Apuntador no es nulo?
        cout << pApEsRaiz ->CaraCa<<" ";            // Se vista raiz
        EnOrdenFa(pApEsRaiz->LigaDerApEsRaiz);
    }
 }

void CsArbol::PostOrdenFa(EsRaiz *pApEsRaiz){
    if(pApEsRaiz != NULL){
          PostOrdenFa(pApEsRaiz->LigaIzqApEsRaiz);
          PostOrdenFa(pApEsRaiz->LigaDerApEsRaiz);                        //¿Apuntador no es nulo?
        cout << pApEsRaiz ->CaraCa<<" ";            // Se vista raiz
    }
 }
void CsArbol::PreOrdenInvFa(EsRaiz *pApEsRaiz){
    if(pApEsRaiz != NULL){                         //¿Apuntador no es nulo?
        cout << pApEsRaiz ->CaraCa<<" ";            // Se vista raiz
        PreOrdenInvFa(pApEsRaiz->LigaDerApEsRaiz);
        PreOrdenInvFa(pApEsRaiz->LigaIzqApEsRaiz);
    }
 }

void CsArbol::EnOrdenInvFa(EsRaiz *pApEsRaiz){
    if(pApEsRaiz != NULL){
        EnOrdenInvFa(pApEsRaiz->LigaDerApEsRaiz);                    //¿Apuntador no es nulo?
        cout << pApEsRaiz ->CaraCa<<" ";            // Se vista raiz
        EnOrdenInvFa(pApEsRaiz->LigaIzqApEsRaiz);
    }
 }

void CsArbol::PostOrdenInvFa(EsRaiz *pApEsRaiz){
    if(pApEsRaiz != NULL){
          PostOrdenInvFa(pApEsRaiz->LigaDerApEsRaiz);
          PostOrdenInvFa(pApEsRaiz->LigaIzqApEsRaiz);       //¿Apuntador no es nulo?
        cout << pApEsRaiz ->CaraCa<<" ";            // Se vista raiz
    }
 }
//
bool CsArbol::EsOpdoFaBo(char CaraCa){
    return ((CaraCa >= 'a')&&(CaraCa <='z'));
}

//
bool CsArbol::EsOpdorFaBo(char CaraCa){
    return (CaraCa=='+')||(CaraCa=='-')||(CaraCa=='*')||(CaraCa=='/')||(CaraCa=='^');


}

main(void){

    char XArCa[]= {"abc*+"};
    CsArbol ElArbol(XArCa);
    EsRaiz *pApEsRaiz;

    pApEsRaiz = ElArbol.CreaArbolFaApEsRaiz();
    puts ("Expresion aritmetica en preorden");
    cout <<"\n+-------------------------------------------+\n";
    ElArbol.PreOrdenFa(pApEsRaiz);
    cout <<"\n+--------------------------------------------+\n";

    puts("\n Expresion aritmetica en Enorden");
    cout <<"\n+-------------------------------------------+\n";
    ElArbol.EnOrdenFa(pApEsRaiz);
    cout <<"\n+-------------------------------------------+\n";
    puts("\n Expresion aritmetica en postorden");
    cout <<"\n+-------------------------------------------+\n";
    ElArbol.PostOrdenFa(pApEsRaiz);
    cout <<"\n+-------------------------------------------+\n";
    puts("\n Expresion aritmetica en preorden inverso");
    cout <<"\n+-------------------------------------------+\n";
    ElArbol.PreOrdenInvFa(pApEsRaiz);
    cout <<"\n+-------------------------------------------+\n";
    puts("\n Expresion aritmetica en Enorden inverso");
    cout <<"\n+-------------------------------------------+\n";
    ElArbol.EnOrdenInvFa(pApEsRaiz);
    cout <<"\n+-------------------------------------------+\n";
    puts("\n Expresion aritmetica en postorden inverso");
    cout <<"\n+-------------------------------------------+\n";
    ElArbol.PostOrdenInvFa(pApEsRaiz);
    cout <<"\n+-------------------------------------------+\n";
    puts("\n");

    system("pause");
}
