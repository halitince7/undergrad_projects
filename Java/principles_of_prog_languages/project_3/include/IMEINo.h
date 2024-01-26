#ifndef IMEINO_H
#define IMEINO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum BOOL{false, true}boolean;


struct IMEINO{
	char *imei;
	boolean (*isTrue)(struct IMEINO*);
	void(*Yoket)(struct IMEINO*);
};

typedef struct IMEINO* IMEINo;


IMEINo IMEINoOlustur();
boolean _isTrue(const IMEINo);
void _Yoket(IMEINo);


#endif