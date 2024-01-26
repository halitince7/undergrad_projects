#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include "Kisi.h"

struct RASTGELEKISI{
	Kisi kisi;
	void(*Yoket)(struct RASTGELEKISI*);
};

typedef struct RASTGELEKISI* RastgeleKisi;

RastgeleKisi RastgeleKisiOlustur();
void _Yoket5(RastgeleKisi);




#endif