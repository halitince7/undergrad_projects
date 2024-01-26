/****************************************************************************
** SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
** BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
** PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
** ÖDEV NUMARASI: Odev2 Soru1
** ÖÐRENCÝ ADI.:  Halit Ýnce
** ÖÐRENCÝ NUMARASI: b171210001
** DERS GRUBU: 1C
****************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	double vize,odev1,odev2,ks1,ks2,final;
	double vizeEtki,odevEtki,ksEtki,yiliciEtki;
	double yiliciToplam;
	double toplamPuan;
	
	cout<<"vize notunu giriniz.......................................:";
	cin>>vize;
	cout<<"1.odev notunu giriniz.....................................:";
	cin>>odev1;
	cout<<"2.odev notunu giriniz.....................................:";
	cin>>odev2;
	cout<<"1. kisa sinav notunu giriniz..............................:";
	cin>>ks1;
	cout<<"2. kisa sinav notunu giriniz..............................:";
	cin>>ks2;
	cout<<"final sinavi notunu giriniz...............................:";
	cin>>final;
	cout<<"vizenin yil icine etkisi yuzde kac olacaktir..............:";
	cin>>vizeEtki;
	cout<<"odevlerin yil icine etkisi yuzde kac olacaktir............:";
	cin>>odevEtki;
	cout<<"kisa sinavlarin yil icine etkisi yuzde kac olacaktir......:";
	cin>>ksEtki;
	cout<<"yil ici puanin etkisi yuzde kac olacaktir.................:";
	cin>>yiliciEtki;
	
	
	yiliciToplam = (vize*vizeEtki + (odev1+odev2)*odevEtki + (ks1+ks2)*ksEtki)/100.0;
	toplamPuan = (yiliciToplam*yiliciEtki + final*(100.0-yiliciEtki))/100.0;
	string harfNotu;	
	
	// Toplam Puanin hangi not araligina denk geldigi kontrol ediliyor.
	if (toplamPuan < 50) 
		harfNotu = "F";
	else if (toplamPuan >= 50 && toplamPuan <= 57) 
		harfNotu = "DD";
	else if (toplamPuan >  57 && toplamPuan <= 64) 
		harfNotu = "DC";
	else if (toplamPuan >  64 && toplamPuan <= 74) 
		harfNotu = "CC";
	else if (toplamPuan >  74 && toplamPuan <= 79) 
		harfNotu = "CB";
	else if (toplamPuan >  79 && toplamPuan <= 84) 
		harfNotu = "BB";
	else if (toplamPuan >  84 && toplamPuan <= 89) 
		harfNotu = "BA";
	else if (toplamPuan > 89 && toplamPuan <= 100) 
		harfNotu = "AA";
	
	cout<<"Yil sonu puani: "<<toplamPuan<<" Harf notu: "<<harfNotu;
	
return 0;	
}
