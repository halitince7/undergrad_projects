/****************************************************************************
** SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
** BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
** PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
** ÖDEV NUMARASI: Odev2 Soru3
** ÖÐRENCÝ ADI.:  Halit Ýnce
** ÖÐRENCÝ NUMARASI: b171210001
** DERS GRUBU: 1C
****************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c;
	double delta,kok1,kok2;
	cin>>a;
	cin>>b;
	cin>>c;
	
	
	
	// Delta degerinin 0 da kucuk olup olamdigi kontrol ediliyor.
	if (delta < 0)
		cout<<"Kokler kompleks sayi!"<<endl;
	// Delta 0 dan kucuk degilse kokler hesaplaniyor.
	else
	{
		kok1 = (-b + sqrt(delta))/2*a;
		kok2 = (-b - sqrt(delta))/2*a;
		cout<<"1. kok: "<<kok1<<endl
			<<"2. kok: "<<kok2<<endl;
	}
		
	return 0;	
}
