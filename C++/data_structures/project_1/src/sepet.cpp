#include "sepet.h"
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
sepet::sepet(void)
{
	topAdedi=7;

	toplar=new top  [topAdedi];
	
	renkleriOlustur();
	toplaraRenkAta();
}

void sepet::renkleriOlustur()
{
	//tüm renkler dinamik hale getiriliyor ve renkler dizisine aktarılıyor
	const int ANARENKSAYISI=10;
	topRenkSayisi=ANARENKSAYISI;
	char anaRenkler[ANARENKSAYISI][16]={"Red","Green","Blue","White","Yellow","Black","Purple","Gray","Orange","Brown"};
	renkler =new char* [topRenkSayisi];
	
	//renk için yer alınıyor
	for (int i = 0; i < topRenkSayisi; i++)
	{
		renkler[i]=new char  [16];
	}
	
	//renkler dinamik diziye aktarılıyor
	for (int i = 0; i < ANARENKSAYISI; i++)
	{
		strcpy(renkler[i],anaRenkler[i]);
	}
}

void sepet::toplaraRenkAta()
{
	//toplara renkleri rastgele atanıyor.
	for (int i = 0; i < this->topAdedi; i++)
	{
		toplar[i].setRenk(rndRenk());
	}
}

sepet::sepet(int topAdedi)
{
	renkleriOlustur();
	this->topAdedi=topAdedi;
	toplar=new top [this->topAdedi];
	toplaraRenkAta();
}

char* sepet::rndRenk()
{
	return renkler[rand()%topRenkSayisi];
}

void sepet::yazdir()
{
	
	cout<<endl;
	for (int i = 0; i < topAdedi; i++)
		{
			cout<<left<< setw(10);  toplar[i].isimYazdir();
		}
	cout<<endl;
	for (int i = 0; i < topAdedi; i++)
		{
			cout<<setw(10);  toplar[i].adresYazdir();
		}
	cout<<endl;
}

sepet::~sepet(void)
{
	delete[] toplar;
	delete[] renkler;
}
