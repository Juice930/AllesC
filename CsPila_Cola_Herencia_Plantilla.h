#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;
/*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
  |class CsListasSec<Gn>                                                      |
  |Esta clase - abstracta y genérica - es solo una pauta para las clases      |
  |derivadas: CsPilas y CsColas                                               |
  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*/
template <class Gn>
class CsListasSec{
public:
  virtual void AgregaFa(Gn)            = 0;
  virtual Gn RemueveFaGn(void)         = 0;
  virtual int CuantosFaEn(void) const  = 0;
  virtual void ExhibeFa(void) const    = 0;
protected:
  virtual bool EsVaciaFabo(void) const = 0;
  virtual bool EsLlenaFabo(void) const = 0;
  CsListasSec(void){};
  Gn *XApGn;
};
/*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
  |   class CsPilas: public CsListasS<Gn>                                    |
  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*/
template <class Gn>
class CsPilas: public CsListasSec<Gn>{
  enum {MaxItemsEn = 30};
public:
  CsPilas(void);
  ~CsPilas(void){};
  virtual void AgregaFa(Gn);
  virtual Gn RemueveFaGn(void);
  virtual int CuantosFaEn(void) const;
  virtual void ExhibeFa(void) const;
  void DespejaPilaFa(void);
  Gn TopeFaGn(void);
  Gn IteradorFaGn(int);
  void ExhibeIterFa(void);
  void ExhibeIteraFa(void);
  void ExhibeDatosFa(void);
private:
  virtual bool EsVaciaFabo(void) const;
  virtual bool EsLlenaFabo(void) const;
  Gn *PApGn;
  int TopeEn;
  int topeEn;
};
//
template <class Gn>
CsPilas<Gn>::CsPilas(void){
  TopeEn = -1;
  topeEn = -1;
  PApGn = new Gn [MaxItemsEn];
}

template <class Gn>
bool CsPilas<Gn>::EsVaciaFabo(void) const {
  return (TopeEn == -1);
}
//
template <class Gn>
Gn CsPilas<Gn>::TopeFaGn(void){
  if(!EsVaciaFabo())
    return PApGn[TopeEn];
  else{
    cerr << "Intento de tomar el item tope en pila vacia" << endl;
    exit(1);
  }
}
//
template <class Gn>
void CsPilas<Gn>::DespejaPilaFa(void){
  TopeEn = - 1;
}
//
template <class Gn>
bool CsPilas<Gn>::EsLlenaFabo(void) const {
  return (TopeEn == MaxItemsEn);
}

template <class Gn>
void CsPilas<Gn>::AgregaFa(Gn AGn){
  if(!EsLlenaFabo()){
    PApGn[++TopeEn] = AGn;
    ++topeEn;
  }else
    puts("Pila desbordada");
}
//
template <class Gn>
Gn CsPilas<Gn>::RemueveFaGn(void){
  Gn AGn;
  if(!EsVaciaFabo()){
    AGn = PApGn[TopeEn--];
    topeEn--;
  }else
    puts("Pila vacia");
  return AGn;
}
/*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
  | Un iterador es una función que cuando se llama repetidamente devuelve   |
  | cada elemento de la lista                                               |
  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*/
template <class Gn>
Gn CsPilas<Gn>::IteradorFaGn(int IndiceEn){
  return PApGn[IndiceEn];
}
//
template <class Gn>
int CsPilas<Gn>::CuantosFaEn(void) const {
  return (TopeEn + 1);
}
//
template <class Gn>
void CsPilas<Gn>::ExhibeFa(void) const {
  int topeEn = TopeEn;
  cout << "TopeEn->| " << PApGn[topeEn--] << " |" << "\n\t-----" << '\n';
  while(topeEn > -1)
    cout << "\t| " << PApGn[topeEn--] << " |" << "\n\t-----" << '\n';
}
// 
template <class Gn>
void CsPilas<Gn>::ExhibeIterFa(void){
  int NoEn = CuantosFaEn() - 1;
  int topeEn = TopeEn;

  cout << "TopeEn->| " << IteradorFaGn(topeEn) << " |" << "\n\t-----\n"; topeEn--;
  for(int iEn = 0; iEn < NoEn; iEn++){
    cout << "\t| " << IteradorFaGn(topeEn) << " |" << "\n\t-----\n"; topeEn--;
  }
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 	class CsColas: public CsListasS<Gn>
   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
template <class Gn>
class CsColas: public CsListasSec<Gn>{
  enum {MaxItemsEn = 10};
public:
  CsColas(void);
  ~CsColas(void){};
  virtual void AgregaFa(Gn);
  virtual Gn RemueveFaGn(void);
  virtual int CuantosFaEn(void) const;
  virtual void ExhibeFa(void) const;
  Gn IteradorFaGn(int);
  int FrenteFaEn(void);
  int FinalFaEn(void);
  void ExhibeDatosFa(void);
private:
  virtual bool EsVaciaFabo(void) const;
  virtual bool EsLlenaFabo(void) const;
  Gn *CApGn;
  int FrenteEn, FinalEn, CuentaEn;
};
//
template <class Gn>
CsColas<Gn>::CsColas(void){
  FrenteEn = FinalEn = CuentaEn = 0;
  CApGn = new Gn [MaxItemsEn];
}
// 
template <class Gn>
Gn CsColas<Gn>::IteradorFaGn(int IndiceEn){
  return CApGn[IndiceEn];
}
//
template <class Gn>
int CsColas<Gn>::FrenteFaEn(void){
  return FrenteEn;
}
//
template <class Gn>
int CsColas<Gn>::FinalFaEn(void){
  return FinalEn;
}

template <class Gn>
bool CsColas<Gn>::EsVaciaFabo(void) const {
  return (CuentaEn == 0);
}

template <class Gn>
bool CsColas<Gn>::EsLlenaFabo(void) const {
  return (CuentaEn == MaxItemsEn);
}

template <class Gn>
void CsColas<Gn>::AgregaFa(Gn ItemGn){
  if(!EsLlenaFabo()){
    CApGn[FinalEn] = ItemGn;
    CuentaEn++;
    FinalEn = (FinalEn + 1)%MaxItemsEn;
  }else{
    puts("Cola desbordada");
    exit(1);
  }
}
//
template <class Gn>
Gn CsColas<Gn>::RemueveFaGn(void){
  Gn ItemGn;
  if(!EsVaciaFabo()){
    ItemGn = CApGn[FrenteEn];
    CuentaEn--;
    FrenteEn = (FrenteEn + 1)%MaxItemsEn;
  }
  else{
    puts("Cola vacia");
    exit(1);
  }
  return ItemGn;
}
//
template <class Gn>
int CsColas<Gn>::CuantosFaEn(void) const {
  return CuentaEn;
}
//
template <class Gn>
void CsColas<Gn>::ExhibeFa(void) const {
  int frenteEn = FrenteEn;
  int finalEn = FinalEn;
  int iEn;
  if(FinalEn < FrenteEn){
    if(FinalEn == 0)
      cout << "FinalEn ->|   |" << "\n\t  -----\n";
    else{ // FinalEn <> 0
      for(iEn = 0; iEn < FinalEn; iEn++)
        cout << "\t  | " << CApGn[iEn] << " |" << "\n\t  -----\n";
      cout << "FinalEn ->|   |" << "\n\t  -----\n";
    }
    int DifEn = FrenteEn - FinalEn - 1;
    while(DifEn-- > 0)
      cout << "\t  |   |" << "\n\t  -----\n";
    cout << "FrenteEn->| " << CApGn[frenteEn++] << " |" << "\n\t  -----\n";
    while(frenteEn < MaxItemsEn)
      cout << "\t  | " << CApGn[frenteEn++] << " |" << "\n\t  -----\n";
  }else if(FinalEn == FrenteEn){
    puts("Cola vacia\n");
  }else{ //(FinalEn > FrenteEn)
    cout << "FrenteEn->| " << CApGn[frenteEn++] << " |" << "\n\t  -----\n";
    while(frenteEn < FinalEn)
      cout << "\t  | " << CApGn[frenteEn++] << " |" << "\n\b\t  -----\n";
    cout << "FinalEn ->|   |" << "\n\t  -----\n";
  }
}
//
