/**
* @file BagliListe.cpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/


#include "BagliListe.hpp"


		ListeGezici BagliListe::OncekiniKonumuileBul(int konum){
			int indeks=0;
			Dugum *tmp; 
			tmp = basDugum;
			while(tmp->ileri != NULL && konum != indeks)
			{
				tmp = tmp->ileri;
				indeks++;
			}
			return ListeGezici(tmp);
		}

		BagliListe::BagliListe()
		{
			basDugum = new Dugum("",NULL);
			elemanSayisi = 0;
		}
		
		int BagliListe::Uzunluk()const{
			return elemanSayisi;
		}
		
		bool BagliListe::Bosmu(){
			return elemanSayisi == 0;
		}
		
		const string& BagliListe::ilk()const{
			return basDugum->ileri->eleman;
		}
		
		
		void BagliListe::Ekle(const string& eleman,const string& dizinAdres){
			Ekle(elemanSayisi,eleman,dizinAdres);
		}
		
		void BagliListe::Ekle(int konum, const string& eleman, const string& dizin ){
			ListeGezici onceki = OncekiniKonumuileBul(konum);
			onceki.simdiki->ileri = new Dugum(eleman,onceki.simdiki->ileri);
			elemanSayisi++;
						
						 
				char temp[70];
				for(int i=0;i<70;i++) temp[i] = dizin[i];
				char add[30];
				for(int j=0;j<eleman.length();j++){
				add[j] = eleman[j];
				}
				add[eleman.length()] = '\0';
				strcat(temp,"/");
				strcat(temp,add);
				ifstream input(temp); 
				if(!(input)){
					cout<<"okuma hatasi!";
					
				}
				string a;
				int j = 0;
				do{
					input >> a;
					onceki.simdiki->ileri->agac->Ekle(a);
			   	}while(input);
		}
		
		void BagliListe::Sil(const string& eleman){
			int konum = Konum(eleman);
			KonumdakiniSil(konum);
		}
		
		void BagliListe::KonumdakiniSil(int konum){
			ListeGezici onceki = OncekiniKonumuileBul(konum);
			Dugum *q = onceki.simdiki->ileri;
			onceki.simdiki->ileri = onceki.simdiki->ileri->ileri;
			delete q;
			elemanSayisi--;
		}
		
		const Dugum& BagliListe::KonumdakiniGetir(int konum){
			ListeGezici onceki = OncekiniKonumuileBul(konum);
			Dugum *q = onceki.simdiki->ileri;
			return *q;
		}
		
		int BagliListe::Konum(const string& eleman){
			int indeks = 0;
			for(ListeGezici gezici(basDugum->ileri); !gezici.SonaGeldimi();gezici.ilerle()){
				if(gezici.Getir() == eleman) return indeks;
				indeks++;
			}
		}
		
		bool BagliListe::Bul(const string& eleman)const{
			for(ListeGezici gezici(basDugum->ileri); !gezici.SonaGeldimi();gezici.ilerle()){
				if(gezici.Getir() == eleman) return true;
			}
			return false;
		}
		
		
		void BagliListe::Listele() const{
			for(Dugum *simdiki=basDugum;simdiki!=NULL;simdiki = simdiki->ileri){
				cout<<endl<<simdiki->eleman<<endl;
				simdiki->agac->inorder();
			}
		}
		
		bool BagliListe::AramaYap( string eleman) const{
			for(Dugum *simdiki=basDugum;simdiki!=NULL;simdiki = simdiki->ileri){
				if(simdiki->agac->elemanVarmi(eleman)){
					cout<<endl<<"Aranan kelime "<<simdiki->eleman<<" dosyasinda bulunmustur."<<endl;
					return true;
				}
			}
			cout<<"Aranan eleman hicbir dosyada yok."<<endl;
			return false;
		}
		
		void BagliListe::Temizle(){
			while(!Bosmu()){
				KonumdakiniSil(0);
			}
		}
		
		BagliListe::~BagliListe()
		{
			Temizle();
			delete basDugum;
		}



