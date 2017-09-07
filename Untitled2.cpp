#include "CsPila_Cola_Herencia_Plantilla.h"
//
int (*(*CreaMatrizFnApArApArEn(void))[10])[10]{
    int (*(*pApArApArEn)[10])[10] = (int (*(*)[10])[10])new(int (*[10])[10]);
    int iEn, jEn, kEn = 0;
    
    for(iEn = 0; iEn < 10; iEn++)
      (*pApArApArEn)[iEn] = (int (*)[10])new int [10];
    for(iEn = 0; iEn < 10; iEn++)
        for(jEn = 0; jEn < 10; jEn++)
            (*(*pApArApArEn)[iEn])[jEn] = kEn++;
    
    return pApArApArEn;
}
//
main(void){
  CsPilas<int (*(*)[10])[10]> LaPilaMatriz;
  int (*(*qApArApArEn)[10])[10];
  int iEn, jEn, kEn;
  
  for(iEn = 0; iEn < 10; iEn++){
    qApArApArEn = CreaMatrizFnApArApArEn();
    LaPilaMatriz.AgregaFa(qApArApArEn);
  }
  for(iEn = 0; iEn < 10; iEn++){
    qApArApArEn = LaPilaMatriz.RemueveFaGn();
    cout << "Hola ";
    for(kEn = 0; kEn < 10; kEn++){
      for(jEn = 0; jEn < 10; jEn++)
        cout << (*(*qApArApArEn)[kEn])[jEn] << " ";
      puts("");
    }
  }

  puts("\n");

  system("pause");
}
