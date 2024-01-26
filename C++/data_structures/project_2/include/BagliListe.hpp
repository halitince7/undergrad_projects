/**
* @file BagliListe.hpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/


#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP


#include "ListeGezici.hpp"
class BagliListe
{
	private:
		Dugum *basDugum;
		int elemanSayisi;
		
		ListeGezici OncekiniKonumuileBul(int);
		
	public:
		BagliListe();
		
		int Uzunluk()const;
		
		bool Bosmu();
		
		const string& ilk()const;
		
		
		void Ekle(const string& eleman,const string& dizinAdres);
		
		
		void Ekle(int konum, const string& , const string&  );
		
		void Sil(const string& );
		
		void KonumdakiniSil(int);
		
		const Dugum& KonumdakiniGetir(int);
		
		int Konum(const string& );
		
		bool Bul(const string& )const;
		
		
		void Listele() const;
		
		bool AramaYap( string ) const;
		
		void Temizle();
		
		~BagliListe();
		
};

#endif
