/****************************************************************************
** SAKARYA �N�VERS�TES�
** B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
** B�LG�SAYAR M�HEND�SL��� B�L�M�
** PROGRAMLAMAYA G�R��� DERS�
**
** �DEV NUMARASI: Odev2 Soru3
** ��RENC� ADI.:  Halit �nce
** ��RENC� NUMARASI: b171210001
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
