#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define kelimesayisi 10

char kelimeler[kelimesayisi][30]={"bilgisayar","muhendis","karanlik","namutenahi","ram","meyus","hissikablelvuku","tufeyli","merdumgiriz","lafuguzaf"};
char *kelime;
char *tahmin;
char harf;

void tahminyerayir(int uzunluk){
	
	int i=0;
	
	for(i=0;i<uzunluk;i++){
		tahmin[i]='_';
	}
	tahmin[i]='\0';
}

int harfarama(int uzunluk,char harf){
	
	int i,sonuc=0;
	
	for(i=0;i<uzunluk;i++){
		if(kelime[i]==harf){
			tahmin[i]=harf;
			sonuc=1;
		}
	}
	return sonuc;
}

void adamciz(int adam){
	
	switch(adam){
		
	case 1:{
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf("                \n");
		printf(" __             \n");
		break;				
	}
	case 2:{
		printf("                \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");		
		break;		
	}
	case 3:{
		printf(" __________     \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");	
		break;				
	}		
	case 4:{
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|               \n");
		printf("|__             \n");	
		break;	
	}
	case 5: {
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|__             \n");
		break;		
	}
	case 6: {
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|       \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|__             \n");		
		break;
	}
	case 7:{
	
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|       |       \n");
		printf("|__             \n");
		break;
		}		
	case 8: {
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|      /|       \n");
		printf("|__             \n");
		printf("\nBir tane yanlis yapma hakkın kaldi!\n");
		break;
		}		
	case 9: {
			
		printf(" __________     \n");
		printf("|      ( )      \n");
		printf("|       |       \n");
		printf("|      /|\\     \n");
		printf("|       |       \n");
		printf("|      / \\     \n");
		printf("|__             \n");
		printf("\nDogru tahmin edemediniz");
		printf("\nKelimeniz= %s",kelime);		
		break;
		}
	}	
}





int main(){
	
	srand(time(NULL));
	
	
	int i,uzunluk,kelimesec;
	int adam=0,arama=0,bulunan=0,sonuc=0;
	
	kelimesec=rand()%kelimesayisi;
	kelime=kelimeler[kelimesec];
	uzunluk=strlen(kelime);
	printf("Kelimeniz %d uzunlugundadir.",uzunluk);
	
	
	tahmin=(char*)malloc(uzunluk+1*sizeof(char));
	if(tahmin==NULL){
		printf("Bellek ayirma islemi tamamlanamadi");
		exit(0);
	}
	
	tahminyerayir(uzunluk);
	
	while(adam!=9 && bulunan!=uzunluk){
		
		printf("\nBir harf giriniz: ");
		scanf("%s",&harf);
		
		if(harfarama(uzunluk,harf)){
			bulunan++;
			arama=1;	
		}
		
		if(arama==1){
			arama=0;			
		}
		else{
			adam++;
		}
		adamciz(adam);
		
		printf("\nSon durum: %s\n",tahmin);	
	}
	
	if(adam!=9){
		printf("\nKelimeyi dogru tahmin ettiniz");
	}
	free(tahmin);
	free(kelime);	
		
	return 0;
}
