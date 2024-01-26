/****************************************************************************
** SAKARYA �N�VERS�TES�
** B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
** B�LG�SAYAR M�HEND�SL��� B�L�M�
** PROGRAMLAMAYA G�R��� DERS�
**
** �DEV NUMARASI: Odev2 Soru2
** ��RENC� ADI.:  Halit �nce
** ��RENC� NUMARASI: b171210001
** DERS GRUBU: 1C
****************************************************************************/


#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	int dizi[1000];
	int elSayisi;
	int random;
	int okYeri=0;
	char secim;
	
	cout<<"Eleman sayisini giriniz: ";
	cin>>elSayisi;
	
	//diziye istenilen sayida rasgele eleman ekler.
	//srand(time(NULL));
	for (int i =0;i<elSayisi;i++){
		random=rand() % 10;
		dizi[i] = random;
	}
	
	// c veya C girilmedikce dongu icinde kalmasini saglar.
	while(secim != 'c' && secim != 'C'){
		
		//Ok ile beraber dizi yazilmadan her defasinda ekrani temizler.
		system("cls");
		//Dizi elemanlarini basinda ya ok ile yada bosluk ile yazdirir. okYeri degiskeni
		//o an dizinin kacinci elemaninin gosteriyorsa oku o elemanin basina yazar.
		for (int i =0;i<elSayisi;i++){
		if (okYeri == i) 
			cout<<"--->"<<dizi[i]<<endl;
		else
			cout<<"    "<<dizi[i]<<endl;
		}
		
		// kullanicidan secimini alir.
		cout<<"(a veya A tusu asagi goturur)"<<endl
		    <<"(d veya D tusu yukari goturur)"<<endl
		    <<"(c veya C tusu programdan cikarir)"<<endl
		    <<"Ok yonunu secin:";
		
		cin>>secim;
		
		// a veya A girildiyse okYeri ni 1 artirir. d veya D girildiyse okYeri ni bir azaltir.
		// okYeri degiskeni dizinin eleman sayisini arti veya eksi yonde asmamas� icin mod islemi yapilir.
		if (secim == 'a' || secim == 'A')
			okYeri = (okYeri+1) % elSayisi;
		else if (secim == 'd' || secim == 'D')
			okYeri = (okYeri-1+elSayisi) % elSayisi;
	}
	
	
	return 0;	
}
