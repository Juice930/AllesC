#include<stdio.h>
#include<string.h>
int main ()
{
    char cod[15];
    char clav[3];
    char ate[3];
    char tipo[3];
    char pas[3];
    char leng[3];
    char auxcod[15];
    char auxclav[3];
    int i, navg=0,desp, atev, varext, j;
    char aduana;
    desp=0;
    while(desp==0 || desp==1){
        printf("\n\n\nVas a aterrizar o vas a despegar? \n0 para aterrizar\n1 para despegar\nCualquier otro boton para salir\n");
        scanf("%i",&desp);
if(desp==0){
    do{    
        do {
        printf("\n\nDame el codigo de tu vuelo: ");
        fflush(stdin);
        gets(cod);
        }
        while(strlen(cod)!=15);
        for (i=0; i<=2; i++)
            clav[i]=cod[i];
        for (i=3; i<=5; i++)
            ate[i-3]=cod[i];
        for (i=6; i<=8; i++)
            tipo[i-6]=cod[i];
        for (i=9; i<=11; i++)
            pas[i-9]=cod[i];
        for (i=12; i<=15; i++)
            leng[i-12]=cod[i];
    if(leng[0]=='E' && leng[1]=='S' && leng[2]=='P')
        printf("\nHola");
    else if(leng[0]=='E' && leng[1]=='N' && leng[2]=='G')
        printf("\nHi");
    else if(leng[0]=='I' && leng[1]=='T' && leng[2]=='A')
        printf("\nCiao");
    else if(leng[0]=='K' && leng[1]=='N' && leng[2]=='G')
        printf("\nnuqneH");
    else if(leng[0]=='E' && leng[1]=='L' && leng[2]=='F')
        printf("\nAIYA");
    else if(leng[0]=='O' && leng[1]=='T' && leng[2]=='R')
        printf("\nDisculpe no hablamos ese idioma");
    else
        printf("\nPodria especificar mejor su idioma?");
    if(ate[0]=='F' && ate[1]=='I' && ate[2]=='N'){
        navg++;
        if(navg>10){
        printf("\nEstamos llenos, favor de pasar a otro aeropuerto");
        navg=10;}
        atev=0;}
    else if (ate[0]=='T' && ate[1]=='M' && ate[2]=='P')
        atev=1;
    else 
        printf("\nNo existe ese tipo de aterrizaje");
        //F=70,I=73,N=78,T=84,M=77,P=80
    if(tipo[0]=='E' & tipo[1]=='X' && tipo[2]=='T'){
        varext=0;//0 es extraterrestre
        printf("\nPasar a la aduana de MIB para revision");}
    else if(tipo[0]=='T' && tipo[1]=='E' && tipo[2]=='R'){
    varext=1;//1 es humano
            printf("\nPasar a la aduana de la STI para revision");}
    else if(tipo[0]=='C' && tipo[1]=='M' && tipo[2]=='B'){
    varext=2;//2 es combinado
    printf("\nHay mas pasajeros extraterrestres que humanos? (S/N): ");
    scanf("%c",&aduana);
    do{
        if(aduana=='S')
            printf("\nPasar a la aduana de MIB para revision");
        else
             printf("\nPasar a la aduana de la STI para revision");
    }
    while(aduana!='S' && aduana!='N');
}
    else
    printf("\nQue eres?");
    //E=69,X=88,T=84, B=66, C=67
    if ((pas[0]<48 || pas[0]>57) && (pas[1]<48 || pas[1]>57) && (pas[2]<48 || pas[2]>57))
    printf("\nEscribe correctamente el numero de pasajeros");
      
    }while((ate[0]!='T' && ate[0]!='F') || (ate[1]!='I' && ate[1]!='M') || (ate[2]!='N' && ate[2]!='P') || (tipo[0]!='E' && tipo[0]!='T' && tipo[0]!='C') 
    || (tipo[1]!='X' && tipo[1]!='E' && tipo[1]!='M') || (tipo[2]!='T' && tipo[2]!='R' && tipo[2]!='B') || ((pas[0]<48 || pas[0]>57) && (pas[1]<48 || pas[1]>57) 
    && (pas[2]<48 || pas[2]>57)));
}
if(desp==1){
    if(navg==0)
        printf("No hay naves en la base espacial\n");
    if(navg!=0){
        do{  
            fflush(stdin);
            printf("Dame el codigo de la nave que va a despegar\n");
              fflush(stdin);
        gets(auxclav);
        j=0;
        for(i=0;i<3;i++){
            if(auxclav[i]=clav[i])
            j++;}
             }
    while(strlen(auxclav)!=3);
		printf("%s",auxclav);
        /*if(j==3){
            for(i=-1;i<3;i++)
                printf("%c",auxclav[i]);*/
        printf("DEP");
        if(varext==0)
            printf("EXT");
        if(varext==1)
            printf("TER");
        if(varext==2)
            printf("CMB");
            
        for(i=0;i<3;i++){
                fflush(stdin);
                printf("%c",pas[i]);}
        for(i=0;i<3;i++)
                printf("%c",leng[i]);
   navg--;}
}
}
}
return 0;
}
