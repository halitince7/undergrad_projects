#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include "Telefon.h"

struct KIMLIKNO{
	char *tcNo;
	boolean (*isTrue)(struct KIMLIKNO*);
	void(*Yoket)(struct KIMLIKNO*);
};

typedef struct KIMLIKNO* KimlikNo;

KimlikNo KimlikNoOlustur();
boolean _isTrue2(const KimlikNo);
void _Yoket3(KimlikNo);




#endif