#ifndef KISI_H
#define KISI_H

#include "KimlikNo.h"

struct KISI{
	KimlikNo tcNo;
	char *adSoyad;
	int yas;
	Telefon tel;
	void(*Yoket)(struct KISI*);
};

typedef struct KISI* Kisi;

Kisi KisiOlustur();

void _Yoket4(Kisi);



#endif