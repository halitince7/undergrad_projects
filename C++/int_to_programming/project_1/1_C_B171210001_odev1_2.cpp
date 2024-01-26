/****************************************************************************
** SAKARYA ÜNÝVERSÝTESÝ
** BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
** BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
** PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
** ÖDEV NUMARASI: Odev1 Soru2
** ÖÐRENCÝ ADI.:  Halit Ýnce
** ÖÐRENCÝ NUMARASI: b171210001
** DERS GRUBU: 1C
****************************************************************************/

#include <iostream>
#include<math.h>
using namespace std;



// odevde verilen fonksiyonun gerceklenmesi
int f(float x, int b, int a) {
	if (x<b) return -1;
	else if (x>a) return 1;
	else return 0;
}


int main()
{
	int b;
	int a;
	float x;
	float basla;
	float bitir;
	float artis;
	float fark;

	//kullanicidan alt ve üst degerlerini alir
	cout << "b:";
	cin >> b;
	cout << "a:";
	cin >> a;
	//baslangic bitis ve artis miktarini hesaplar
	fark = a - b;
	basla = b - fark;
	bitir = a + fark;
	artis = (bitir - basla) / 20;
	//her üc satira yazilacak yildizlari kontrol eder
	for (int satir = 1; satir<4; satir++) {
		if (satir == 1)      cout << " 1 ";
		else if (satir == 2) cout << " 0 ";
		else                cout << "-1 ";
		//baslangic bitis ve artis degerlerine gore satirlara yildiz koyar
		for (x = basla; x <= bitir; x = x + artis) {
			// fonsiyondan degeri alip buna gore ilgili satira yildiz veya bosluk basar
			if (satir == 1) {
				if (f(x, b, a) == 1)  cout << "* ";
				else            cout << "  ";
			}
			else if (satir == 2) {
				if (f(x, b, a) == 0)  cout << "* ";
				else            cout << "  ";
			}
			else if (satir == 3) {
				if (f(x, b, a) == -1)  cout << "* ";
				else             cout << "  ";
			}
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}