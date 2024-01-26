#include "sepetKontrol.h"
#include "sepet.h"
#include <iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
// 10 sepet 7 top oluşturur.
sepetKontrol::sepetKontrol(void)
{
	//program her çalıştığında farklı rastgele sayı üretir.
	srand(time(0));
	sepetAdedi=10;
	sepetler = new sepet* [sepetAdedi];
	
	for(int i = 0; i < sepetAdedi; i++)
	{
		sepetler[i]=new sepet(7) ;
	}
}
sepetKontrol::sepetKontrol(int sepetSayisi,int topSayisi)
{
	sepetAdedi=sepetSayisi;
	sepetler = new sepet* [sepetAdedi];
	
	for(int i = 0; i < sepetAdedi; i++)
	{
		sepetler[i]=new sepet(topSayisi) ;
	}
}

void sepetKontrol::sepetleriYazdir(void)
{
		for (int i = 0; i < sepetAdedi; i++)
		{
			cizgiBas(37); std::cout<<"SEPET"<<setw(2)<<i+1; cizgiBas(36);
			sepetler[i]->yazdir(); cout<<endl;//sorun burada ama neden
		}
}

void sepetKontrol::cizgiBas(int a)
{
	for(int i=0;i<a;i++)
	std::cout<<"=";
}

sepetKontrol::~sepetKontrol(void)
{
	delete[] sepetler;
}

void sepetKontrol::sepetOlustur()
{
	
}

void sepetKontrol::sepetDegistir(int hedef,int kaynak)
{
	sepet* yedek;
	yedek=sepetler[hedef-1];
	sepetler[hedef-1]=sepetler[kaynak-1];
	sepetler[kaynak-1]=yedek;
}

int sepetKontrol::getSepetAdedi()
{
	return this->sepetAdedi;
}