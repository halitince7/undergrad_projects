// 1_C_B171210001_odev4.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

/****************************************************************************
**					           SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				            BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				              PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: 4. Ödev
**				ÖĞRENCİ ADI......: Halit İNCE
**				ÖĞRENCİ NUMARASI.: B171210001
**				DERS GRUBU…………:    C Grubu
****************************************************************************/

#include "stdafx.h"
#include <iostream> 
#include <iomanip> 
#include <stdlib.h>
#include <ctime>
using namespace std;


bool elemanKontrol(int kullanilanElemanlar[100], int kullanilanIndex, int random) {
	for (int i = 0; i<kullanilanIndex; i++) {
		if (kullanilanElemanlar[i] == random) return false;
	}
	return true;
}

int Olustur(int matris[10][10]) {
	int kullanilanElemanlar[100];
	int kullanilanIndex = 0;
	int random = rand() % 100 + 1;
	int sayac = 0;
	srand(time(NULL));
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			while (!elemanKontrol(kullanilanElemanlar, kullanilanIndex, random)) {
				sayac++;
				random = rand() % 100 + 1;
			}
			kullanilanElemanlar[kullanilanIndex] = random;
			matris[i][j] = random;
			kullanilanIndex++;
		}
	}
	return sayac;
}

void matrisYaz(int matris[10][10]) {
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			cout << matris[i][j] << " ";
		}
		cout << endl;
	}
}

void tersCevir(int matris[10][10]) {
	int dizi[100];
	int diziIndex = 0;
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			dizi[diziIndex] = matris[i][j];
			diziIndex++;
		}
	}

	int temp;
	for (int i = 0; i<100; i++) {
		for (int j = i + 1; j<100; j++) {
			if (dizi[i] < dizi[j])
			{
				temp = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = temp;
			}
		}
	}

	diziIndex = 0;
	for (int i = 0; i<10; i++) {
		for (int j = 0; j<10; j++) {
			matris[i][j] = dizi[diziIndex];
			diziIndex++;
		}
	}
}

int main()
{
	int matris[10][10];
	int say = Olustur(matris);
	cout << "Toplam rasgele cagrim adedi=" << say << endl;
	cout << "Rasgele olusan ve elemanlari birbirinden farkli matris" << endl;
	matrisYaz(matris);
	tersCevir(matris);
	cout << endl << endl;
	cout << "Buyukten kucuge siralanmis matris:" << endl;
	matrisYaz(matris);
	cin >> say;
    return 0;
}

