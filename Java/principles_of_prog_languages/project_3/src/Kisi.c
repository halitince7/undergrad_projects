#include "Kisi.h"

Kisi KisiOlustur(){
	Kisi this;
	char *gecici_ad;
	this = (Kisi)malloc(sizeof(struct KISI));
	this->tcNo = KimlikNoOlustur();
	this->tel = TelefonOlustur();
	this->adSoyad=malloc(sizeof(char)*20);
	//time_t t;
	//srand((unsigned)time(&t));
	this->yas = rand()%100;
	int temp = rand()%3000;
	int sayac = 0;
	
	FILE *fp;
	fp=fopen("random_isimler.txt","r");
	char adSoy[100];
	while(1){
		fgets(adSoy,255,(FILE*)fp);
		if(sayac == temp ){
			gecici_ad = adSoy;
			//this->adSoyad = adSoy;
			fclose(fp);
			break;
		}
		sayac++;
	}
	int i=0;
	while(gecici_ad[i] != '\n'){
		this->adSoyad[i] = gecici_ad[i];
		i++;
	}
	this->adSoyad[i] = '\0';
	
	//printf("Yas: %d\n",this->yas);
	//printf("isim: %s\n",this->adSoyad);
	
	
	this->Yoket = &_Yoket4;
	return this;
}

void _Yoket4(Kisi this){
	if(this==NULL) return;
	this->tcNo->Yoket(this->tcNo);
	this->tel->Yoket(this->tel);
	free(this->adSoyad);
	free(this);
}