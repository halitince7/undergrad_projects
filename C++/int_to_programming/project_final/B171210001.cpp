// B171210001.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

/****************************************************************************
**					           SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				            BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				              PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: Proje/Tasarım
**				ÖĞRENCİ ADI......: Halit İNCE
**				ÖĞRENCİ NUMARASI.: B171210001
**				DERS GRUBU…………:    C Grubu
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include "string"
using namespace std;



class Oda {
public:
	int odaNo;
	int ucret;
	int musteriNo = 0;
	Oda(int odaNum = 0, int ucr = 0) {
		odaNo = odaNum;
		ucret = ucr;
	}
	void MusteriAta(int musNo) {
		musteriNo = musNo;
	}
	void MusteriSil(int musNo) {
		musteriNo = 0;
	}
};

class Musteri {
public:
	int musteriNo;
	string ad;
	string soyad;
	int tcNo;
	int odaNo = 0;
	Musteri(int no = 0, string ism = " ", string soy = " ", int tc = 0) {
		musteriNo = no;
		ad = ism;
		soyad = soy;
		tcNo = tc;
	}
};

class Otel {
public:
	Otel() {
		AnaMenu();
	}
	void OdaEkle() {
		ofstream cikti("odalar.txt", ios::app);
		int odano, ucrt;
		cout << "Oda no ve Ucreti giriniz:" << endl;
		cin >> odano;
		cin >> ucrt;
		Oda oda(odano, ucrt);
		cikti << oda.odaNo << "         " << oda.ucret << "         " << oda.musteriNo << endl;
		cikti.close();
	}

	void OdaSil(int sil) {

		string satir;
		ifstream dosya("odalar.txt");
		ofstream cikti("gecici.txt");
		if (dosya.is_open())
		{
			while (getline(dosya, satir))
			{
				int temp = atoi(satir.c_str());
				if (temp != sil) {
					cikti << satir << endl;
				}
			}
			dosya.close();
		}
		cikti.close();

		ifstream dosya2("gecici.txt");
		ofstream cikti2("odalar.txt");
		if (dosya2.is_open())
		{
			while (getline(dosya2, satir))
			{
				cikti2 << satir << endl;
			}
			dosya2.close();
		}
		cikti2.close();
		remove("gecici.txt");
	}

	void OdalarListele() {
		string satir;
		ifstream dosya("odalar.txt");
		if (dosya.is_open())
		{
			cout << "Oda No    Ucret    Kalan Musteri No" << endl
				<< "---------------------------------------" << endl;
			while (getline(dosya, satir))
			{
				cout << satir << endl;
			}
			dosya.close();
		}
	}

	void MusteriEkle() {
		ofstream cikti("musteriler.txt", ios::app);
		int musno, tc;
		string ad, soyad;
		cout << "Yeni musterinin adini ve soyadini giriniz:" << endl;
		cin >> ad;
		cin >> soyad;
		cout << "Yeni musterinin musteri nosunu ve tc nosunu giriniz:" << endl;
		cin >> musno;
		cin >> tc;
		Musteri musteri(musno, ad, soyad, tc);
		cikti << musteri.musteriNo << "          " << musteri.ad << "  " << musteri.soyad << "   " << musteri.tcNo << "    " << musteri.odaNo << endl;
		cikti.close();
	}

	void MusteriSil(int sil) {
		string satir;
		ifstream dosya("musteriler.txt");
		ofstream cikti("gecici.txt");
		if (dosya.is_open())
		{
			while (getline(dosya, satir))
			{
				int temp = atoi(satir.c_str());
				if (temp != sil) {
					cikti << satir << endl;
				}
			}
			dosya.close();
		}
		cikti.close();

		ifstream dosya2("gecici.txt");
		ofstream cikti2("musteriler.txt");
		if (dosya2.is_open())
		{
			while (getline(dosya2, satir))
			{
				cikti2 << satir << endl;
			}
			dosya2.close();
		}
		cikti2.close();
		remove("gecici.txt");
	}

	void MusterilerListele() {
		string satir;
		ifstream dosya("musteriler.txt");
		if (dosya.is_open())
		{
			cout << "Musteri No   Ad   Soyad   Tc No    Oda No" << endl
				<< "-----------------------------------------" << endl;
			while (getline(dosya, satir))
			{
				cout << satir << endl;
			}
			dosya.close();
		}
	}

	void MusteriyeOdaVer() {

		Musteri musteri;
		Oda oda;
		int m;
		int o;
		cout << "Oda vermek istediginiz musterinin numarasini giriniz:" << endl;
		cin >> m;
		cout << "Kaç  numarali odayi vermek istiyorsunuz?" << endl;
		cin >> o;

		ifstream dosyaOku;
		dosyaOku.open("musteriler.txt");
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.musteriNo >> musteri.ad >> musteri.soyad >> musteri.tcNo >> musteri.odaNo;
			if (musteri.musteriNo == m) {
				musteri.odaNo = o;
				dosyaOku.close();
				MusteriSil(m);
				ofstream cikti("musteriler.txt", ios::app);
				cikti << musteri.musteriNo << "          " << musteri.ad << "  " << musteri.soyad << "   " << musteri.tcNo << "    " << musteri.odaNo << endl;
				cikti.close();
			}
		}

		ifstream dosyaOku2;
		dosyaOku2.open("odalar.txt");
		while (!dosyaOku2.eof()) {
			dosyaOku2 >> oda.odaNo >> oda.ucret >> oda.musteriNo;
			if (oda.odaNo == o) {
				oda.musteriNo = m;
				dosyaOku2.close();
				OdaSil(o);
				ofstream cikti2("odalar.txt", ios::app);
				cikti2 << oda.odaNo << "         " << oda.ucret << "         " << m << endl;
				cikti2.close();
			}
		}
	}

	void MusteriyiOdadanCikar() {
		Musteri musteri;
		Oda oda;
		int m;
		cout << "Kac numarali musteriyi odadan cikarmak istiyorsunuz?" << endl;
		cin >> m;
		ifstream dosyaOku;
		dosyaOku.open("musteriler.txt");
		while (!dosyaOku.eof()) {
			dosyaOku >> musteri.musteriNo >> musteri.ad >> musteri.soyad >> musteri.tcNo >> musteri.odaNo;
			if (musteri.musteriNo == m) {
				musteri.odaNo = 0;
				dosyaOku.close();
				MusteriSil(m);
				ofstream cikti("musteriler.txt", ios::app);
				cikti << musteri.musteriNo << "          " << musteri.ad << "  " << musteri.soyad << "   " << musteri.tcNo << "    " << musteri.odaNo << endl;
				cikti.close();
			}
		}

		ifstream dosyaOku2;
		dosyaOku2.open("odalar.txt");
		while (!dosyaOku2.eof()) {
			dosyaOku2 >> oda.odaNo >> oda.ucret >> oda.musteriNo;
			if (oda.musteriNo == m) {
				oda.musteriNo = 0;
				dosyaOku2.close();
				OdaSil(oda.odaNo);
				ofstream cikti2("odalar.txt", ios::app);
				cikti2 << oda.odaNo << "         " << oda.ucret << "         " << oda.musteriNo << endl;
				cikti2.close();
			}
		}
	}

	void AnaMenu() {
		int secim = 0;
		while (secim != 99) {
			system("cls");
			cout << "Otel Islemleri" << endl
				<< "--------------" << endl
				<< "1.Oda Islemleri" << endl
				<< "2.Musteri Islemleri" << endl
				<< "3.Oda Kayit Islemleri" << endl
				<< "99.Cikis" << endl
				<< "Seciminiz: ";
			cin >> secim;
			if (secim == 1) {
				OdaMenu();
			}
			else if (secim == 2) {
				MusteriMenu();
			}
			else if (secim == 3) {
				KayitMenu();
			}
			else if (secim == 99) {
				break;
			}
			else {
				cout << "Hatali secim, tekrar giriniz.." << endl;
				cin >> secim;
			}

		}
	}

	void OdaMenu() {
		int secim = 0;
		while (true) {
			system("cls");
			cout << "Oda Islemleri" << endl
				<< "--------------" << endl
				<< "1.Oda Ekle" << endl
				<< "2.Oda Sil" << endl
				<< "3.Odalari Listele" << endl
				<< "99.ust menu" << endl
				<< "Seciminiz: ";
			cin >> secim;
			if (secim == 1) {
				system("cls");
				OdaEkle();
				AnaMenu();
			}
			else if (secim == 2) {
				system("cls");
				int sil;
				cout << "Silmek istediginiz oda numarasini giriniz:" << endl;
				cin >> sil;
				OdaSil(sil);
				AnaMenu();
			}
			else if (secim == 3) {
				system("cls");
				OdalarListele();
				cout << "Devam etmek icin bir tusa basiniz..." << endl;
				char temp;
				cin >> temp;
				AnaMenu();
			}
			else if (secim == 99) {
				AnaMenu();
			}
			else {
				cout << "Hatali secim, tekrar giriniz.." << endl;
				cin >> secim;
			}
		}
	}

	void MusteriMenu() {
		int secim = 0;
		while (true) {
			system("cls");
			cout << "Musteri Islemleri" << endl
				<< "--------------" << endl
				<< "1.Musteri Ekle" << endl
				<< "2.Musteri Sil" << endl
				<< "3.Musterileri Listele" << endl
				<< "99.ust menu" << endl
				<< "Seciminiz: ";
			cin >> secim;
			if (secim == 1) {
				system("cls");
				MusteriEkle();
				AnaMenu();
			}
			else if (secim == 2) {
				system("cls");
				int sil;
				cout << "Silmek istediginiz musterinin numarasini giriniz:" << endl;
				cin >> sil;
				MusteriSil(sil);
				AnaMenu();
			}
			else if (secim == 3) {
				system("cls");
				MusterilerListele();
				cout << "Devam etmek icin bir tusa basiniz..." << endl;
				char temp;
				cin >> temp;
				AnaMenu();
			}
			else if (secim == 99) {
				AnaMenu();
			}
			else {
				cout << "Hatali secim, tekrar giriniz.." << endl;
				cin >> secim;
			}
		}
	}

	void KayitMenu() {
		int secim = 0;
		while (true) {
			system("cls");
			cout << "Oda Kayit Islemleri" << endl
				<< "--------------" << endl
				<< "1.Musteriye Oda Ver" << endl
				<< "2.Musteriyi Odadan Cikar" << endl
				<< "99.ust menu" << endl
				<< "Seciminiz: ";
			cin >> secim;
			if (secim == 1) {
				system("cls");
				MusteriyeOdaVer();
				AnaMenu();
			}
			else if (secim == 2) {
				system("cls");
				MusteriyiOdadanCikar();
				AnaMenu();
			}
			else if (secim == 99) {
				AnaMenu();
			}
			else {
				cout << "Hatali secim, tekrar giriniz.." << endl;
				cin >> secim;
			}
		}
	}

};



int main() {
	Otel otel;
	return 0;
}

