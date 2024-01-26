#ifndef TELEFON_H
#define TELEFON_H

#include "IMEINo.h"

struct TELEFON{
	char *telNo;
	IMEINo imeiNo;
	void(*Yoket)(struct TELEFON*);
};

typedef struct TELEFON* Telefon;

Telefon TelefonOlustur();

void _Yoket2(Telefon);




#endif