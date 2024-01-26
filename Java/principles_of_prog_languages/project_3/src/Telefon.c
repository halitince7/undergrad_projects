#include "Telefon.h"

Telefon TelefonOlustur(){
	Telefon this;
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->telNo=malloc(sizeof(char)*12);
	this->imeiNo = IMEINoOlustur();
	
	char* tels[] = {"30","31","32","33","34","05","06","07","40","41","42",
        "43","44","45","55"};
    char* rakamlar[] ={"0","1","2","3","4","5","6","7","8","9"};
    //time_t t;
	//srand((unsigned)time(&t));
	
	
	this->telNo[0] = '0';
	this->telNo[1] = '5';
	int rnd = rand()%15;
	this->telNo[2]=tels[rnd][0];
	this->telNo[3]=tels[rnd][1];
	int i;
	
	for(i=4;i<11;i++){
		rnd = rand()%10;
		this->telNo[i] = rakamlar[rnd][0];
	}
	this->telNo[11]='\0';
	
	//printf("TelNo: %s\n",this->telNo);
	
	this->Yoket = &_Yoket2;
	return this;
}


void _Yoket2(Telefon this){
	if(this==NULL) return;
	this->imeiNo->Yoket(this->imeiNo);
	free(this->telNo);
	free(this);
}