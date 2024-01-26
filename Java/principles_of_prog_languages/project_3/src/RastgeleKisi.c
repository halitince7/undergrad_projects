#include "RastgeleKisi.h"

RastgeleKisi RastgeleKisiOlustur(){
	RastgeleKisi this;
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	this->kisi = KisiOlustur();
	this->Yoket = &_Yoket5;
	return this;
}

void _Yoket5(RastgeleKisi this){
	if(this==NULL) return;
	this->kisi->Yoket(this->kisi);
	free(this);
}