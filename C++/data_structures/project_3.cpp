#include <iostream>
using namespace std;


class Dugum{
	public:	
		int eleman;
		Dugum *ileri;
		Dugum(int eleman=0,Dugum *ilr=NULL){
			this->eleman=eleman;
			ileri=ilr;
		}
};

class ListeGezici{
	public:
		Dugum *simdiki; 
		ListeGezici(){  
			simdiki=NULL;
		}
		ListeGezici(Dugum *dugum){  
			simdiki=dugum;
		}
		bool SonaGeldimi() const{
			return simdiki == NULL;
		}
		bool SonaGeldimi2() const{
			return simdiki->ileri == NULL;
		}
		void ilerle() { 
			simdiki = simdiki->ileri;
		}
		const Dugum& Getir(){ 
			return simdiki->eleman;
		}
};

class BagilListe{
	private:
		Dugum *basDugum; 
		
	
		ListeGezici OncekiniBul(const int& aranan) {
			Dugum *gezici = basDugum;
			while(gezici->ileri != NULL){
				if(gezici->ileri->eleman == aranan) return ListeGezici(gezici);
				gezici = gezici->ileri;
			}
			
		}
		ListeGezici OncekiniKonumuIleBul(int konum){
			
			int indeks=0;
			Dugum *gezici = basDugum;
			while(gezici->ileri != NULL && konum != indeks++) gezici = gezici->ileri;
			return ListeGezici(gezici);
		}
	public:
		BagilListe(){
			basDugum = new Dugum(); 			
		}
		bool Bosmu() const{
			return basDugum->ileri == NULL;
		}
		int Uzunluk() {
			int elemanSayisi=0;
			if(Bosmu()) return 0;
			for(ListeGezici gezici=Ilk();!gezici.SonaGeldimi();gezici.ilerle())elemanSayisi++;
			return elemanSayisi;
		}		
		
		ListeGezici Ilk() {
			return ListeGezici(basDugum->ileri);
		}
		
		
		
		const Dugum& SonEleman() {
			ListeGezici gezici;
			for(gezici=Ilk();!gezici.SonaGeldimi2();gezici.ilerle()); 
			return gezici.Getir();
		}
		const int& SonEleman2() {
			ListeGezici gezici;
			for(gezici=Ilk();!gezici.SonaGeldimi();gezici.ilerle()); 
			return gezici.simdiki->eleman;
	   }
	
		void Ekle(const int& yeni){
			Ekle(yeni,Uzunluk());
		}
	
		void Ekle(const int& yeni,int konum) {
			ListeGezici gezici;
			
				gezici = OncekiniKonumuIleBul(konum);
			
		
			gezici.simdiki->ileri = new Dugum(yeni,gezici.simdiki->ileri);
		}

		void Sil(const int& aranan){
		
				ListeGezici onceki = OncekiniBul(aranan);
				if(onceki.simdiki->ileri != NULL)
				{
					Dugum *eskiDugum = onceki.simdiki->ileri;
				
					onceki.simdiki->ileri = onceki.simdiki->ileri->ileri;
					delete eskiDugum;
				}
			
		
		}
		void KonumdakiniSil(int konum) {
			ListeGezici onceki;
			
				onceki = OncekiniKonumuIleBul(konum);
						
		
			if(onceki.simdiki->ileri != NULL){
				Dugum *eskiDugum = onceki.simdiki->ileri;
				onceki.simdiki->ileri = onceki.simdiki->ileri->ileri;
				delete eskiDugum;
			}
		}
	
	
		void Temizle(){
			while(!Bosmu())
				Sil(Ilk().Getir().eleman);
		}
		~BagilListe(){
			Temizle();
			delete basDugum;
		}
	
};

class Sayi{
	public:
		BagilListe *liste;
	
		Sayi(){
			liste = new BagilListe();
			liste->Ekle(1);
		}
		void Carp(int x){
			int elde = 0;
			ListeGezici gezici;
			for(gezici=liste->Ilk();!gezici.SonaGeldimi();gezici.ilerle()){
				int prod = gezici.simdiki->eleman*x+elde;
				gezici.simdiki->eleman = prod%10;
				elde = prod/10;
			}
			 while (elde)
    		{
        		liste->Ekle(elde%10);
        		elde = elde/10;
    		}
    		
		}
		
		void Yaz(){
			while(!liste->Bosmu()){
				cout<<liste->SonEleman().eleman;
				liste->KonumdakiniSil(liste->Uzunluk()-1);
			}
		}
};


int main()
{
	
	
	int n;
	cout<<"Sayi:";
	cin>>n;
	Sayi *sayi = new Sayi();
	cout<<n<<"!=";
	for (int x=1; x<=n; x++)
        sayi->Carp(x);
    
    sayi->Yaz();
	delete sayi;
	
	return 0;
}
