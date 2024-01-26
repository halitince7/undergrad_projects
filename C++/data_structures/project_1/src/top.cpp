#include "top.h"
#include<string.h>
#include<cstdio>
#include<iostream>


top::top(void)
{
	strcpy(this->renk,"renksiz");
}

void top::setRenk(char* renk)
{
	strcpy(this->renk,renk);
}
char *top::getRenk()
{
	return renk;
}
top::~top(void)
{
	//heapten alınan yer yok fakat 
	//diğer nesne heapten oluşturulunca buda otomatik dinamik olacaktır.
}
void top::isimYazdir()
{
	cout<<this->renk;
}
void top::adresYazdir()
{
	cout<<&renk;
}
