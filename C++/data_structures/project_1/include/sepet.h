#ifndef sepet_h
#define sepet_h

#include "top.h"
class sepet
{
private:
	top* toplar;
	int topAdedi;
	int topRenkSayisi;
	char** renkler;
public:
	sepet();
	sepet(int topAdedi);
	~sepet(void);
	char* rndRenk();
	void yazdir();
	void renkleriOlustur();
	void toplaraRenkAta();
};

#endif