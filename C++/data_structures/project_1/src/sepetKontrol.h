#ifndef sepetKontrol_h
#define sepetKontrol_h


#include "sepet.h"


using namespace std;

class sepetKontrol
{
private:
	sepet ** sepetler;
	int sepetAdedi;
public:	
	sepetKontrol(void);
	sepetKontrol(int sepetSayisi,int topSayisi);
	sepetKontrol(int sepetSayisi);
	
	~sepetKontrol(void);
	void sepetOlustur();
	void cizgiBas(int);
	void sepetleriYazdir(void);
	void sepetDegistir(int hedef,int kaynak);
	int getSepetAdedi();
	
};
#endif