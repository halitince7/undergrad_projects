#include <iostream>
#include <string.h>
using namespace std;


// icinde bir string dizisi(cumlenin kelimeleri), bir char dizisi (cumledeki noktalama isaretlerini tutacak) ,
// cumledeki kelime sayisi ve noktalama sayisini tutan bir struct yapisi
struct Cumle{
	string kelimeler[100];
	char noktalama[100];
	int KelimeSayisi;
	int NoktalamaSayisi;
};


//girdi olarak bir string alan ve bu stringfeki kelimeleri, noktalama isaretlerini birbirinden ayirip
//bir Cumle structý donduren fonksiyon
Cumle CumleParcala(string cumle){
	
	Cumle dizi;
	int len = cumle.length();
	int kelimeIndeks = 0; // kelime sayisini tutacak
	int noktalamaIndeks = 0; // noktalama sayisini tutacak
	char  gecici[100]; // cumledeki kelimeleri teker teker gecici ye kaydetmek icin
	int geciciIndeks = 0; // kaydedilen kelimenin kacinci harfinde oldugunu tutacak
	for(int i=0;i<len;i++){
		// eger noktalama isareti veya bosluk geldiyse buraya girecek
		if(cumle[i] == ' ' || cumle[i] == '.' || cumle[i] == ',' || cumle[i] == ';' || cumle[i] == ':' || cumle[i] == '-' ){
			// eger bosluk degilse gelen karakteri noktalam isretlerine atacak
			if(cumle[i] != ' '){
				dizi.noktalama[noktalamaIndeks] = cumle[i];
				noktalamaIndeks++;
			}
			// eger bir noktalama isareti veya bosluk geldiyse ve geciciIndeks 0dan buyukse
			// bu demektir ki bir kelime gecici ye kaydedilmistir. O halde bu gecici kelimeler e kaydedilsin
			// ve gerekli baslangic degerleri geciciye atansin
			if(geciciIndeks > 0){
				dizi.kelimeler[kelimeIndeks] = gecici;
				kelimeIndeks++;
				for(int i=0;i<100;i++) gecici[i] = {'\0'};
				geciciIndeks = 0;
			}
		}
		// araya bir noktalama isreti veya bosluk girmedikse gelen karakterleri geciciye kaydet
		else{
			gecici[geciciIndeks] = cumle[i];
			geciciIndeks++;
		}
	}
	
	// sonrasinda bir noktalama isareti bulunmayan son kelime icin geciciyi kelimelere kaydet
	if(geciciIndeks > 0){
		dizi.kelimeler[kelimeIndeks] = gecici;
		kelimeIndeks++;
		geciciIndeks = 0;
	}
	dizi.KelimeSayisi = kelimeIndeks;
	dizi.NoktalamaSayisi = noktalamaIndeks;
	
	return dizi;
}

// cumledeki harf sayisi donduren fonksiyon
int HarfSayisi(Cumle dizi){
	int harfSay = 0;
	for(int i=0;i<dizi.KelimeSayisi;i++){
		harfSay += dizi.kelimeler[i].length();
	}
	return harfSay;
}


// cumledeki kelime sayisini donduren fonksiyon
int kelimeSayisi(Cumle dizi){
	return dizi.KelimeSayisi;
}

//cumlede kullanilan noktalama isaretlerini donduren fonksiyon
void Noktalamalar(Cumle dizi){
	for(int i=0;i<dizi.NoktalamaSayisi;i++)
		cout<<dizi.noktalama[i]<<" ";	
}


// cumledeki kelimelerin harf sayilarini donduren fonksiyon
void KelimeHarfSay(Cumle dizi){
	for(int i=0;i<dizi.KelimeSayisi;i++){
		cout<<dizi.kelimeler[i].length()<<" ";
	}
	cout<<endl;
}


// verilen bir elimenin sesli harf sayisini veren foksiyon
int SesliHarfSay(string kelime){
	//string kel = kelime.tolower();
	int say=0;
	int len = kelime.length();
	for(int i=0;i<len;i++){
		if(kelime[i] == 'a' || kelime[i] == 'e' || kelime[i] == 'i' || kelime[i] == 'u' || kelime[i] == 'o' || kelime[i] == 'ý' || kelime[i] == 'ü' || kelime[i] == 'ö' || 
		   kelime[i] == 'A' || kelime[i] == 'E' || kelime[i] == 'Ý' || kelime[i] == 'U' || kelime[i] == 'O' || kelime[i] == 'I' || kelime[i] == 'Ü' || kelime[i] == 'Ö'){
			say++;
		}
	}
	return say;
}

//cumledeki kelimelerin sesli harf sayilarini donduren fonksiyon
void KelimeSesliHarfSay(Cumle dizi){
	for(int i=0;i<dizi.KelimeSayisi;i++){
		cout<<SesliHarfSay(dizi.kelimeler[i])<<" ";
	}
	cout<<endl;
}


// verilen bir string ifadenin polindrom olup olmadigini donduren fonksiyon
bool PolindromMu(string kelime){
	int len = kelime.length();
	char ters[len];
	int j=0;
	//verilen kelimeyi tersten yazilmis halini veren for dongusu
	for(int i=len-1;i>=0;i--){
		ters[j]=kelime[i];
		j++;
	}
	ters[j]='\0';
	for(int i=0; i<len;i++){
		if(kelime[i] != ters[i]) return false;
	}
	return true;
}


// girilen cumlenin polindrom olup olmadigini veren fonksiyon
bool CumlePolindromMu(Cumle dizi){
	char cumle[1000];
	int k=0;
	// cumlenin icindeki kelimeleri birlestiren ic ice iki for dongusu
	for(int i=0;i<dizi.KelimeSayisi;i++){
		for(int j=0;j<dizi.kelimeler[i].length();j++){
			cumle[k] = dizi.kelimeler[i][j];
			k++;
		}
	}
	cumle[k] = '\0';
	return PolindromMu(cumle);
}


//verilen cumledeki kelimelerin icinde polindrom olup olmadigina bakan fonksiyon
bool PolindromVarMi(Cumle dizi){
	for(int i=0;i<dizi.KelimeSayisi;i++){
		if(PolindromMu(dizi.kelimeler[i])) return true;
	}
	return false;
}


// icinde bir menu olan ve istenilen ozellige bakan main metodu
int main(){
	
	string cumle;
	cout<<"Bir cumle yaziniz:"<<endl;
	getline(cin,cumle);
	Cumle dizi = CumleParcala(cumle);
	
	int secim = 0;
	while(secim != 8){
		cout<<endl<<
			  "Seciminizi giriniz:"<<endl<<
		      "1. Cumledeki harf sayisi nedir?"<<endl<<
		      "2. Cumledeki kelime sayisi nedir?"<<endl<<
		      "3. Cumledeki noktalama isaretleri nelerdir?"<<endl<<
		      "4. Cumle palindrom mu?"<<endl<<
		      "5. Cumledeki kelimelerin harf sayilari nedir?"<<endl<<
		      "6. Cumledeki kelimelerin sesli harf sayilari nedir?"<<endl<<
		      "7. Cumlede palindrom kelime var mi?"<<endl<<
		      "8. Cikis"<<endl;
		cin>>secim;
		if(secim == 1){
			cout<<HarfSayisi(dizi)<<endl;
		}
		else if(secim ==2){
			cout<<kelimeSayisi(dizi)<<endl;
		}
		else if(secim ==3){
			Noktalamalar(dizi);
		}
		else if(secim ==4){
			if(CumlePolindromMu(dizi)){
				cout<<"Cumle palindrom."<<endl;
			}
			else{
				cout<<"Cumle palindrom degil."<<endl;
			}
		}
		else if(secim ==5){
			KelimeHarfSay(dizi);
		}
		else if(secim ==6){
			KelimeSesliHarfSay(dizi);
		}
		else if(secim ==7){
			if(PolindromVarMi(dizi)){
				cout<<"Palindrom kelime var."<<endl;
			}
			else{
				cout<<"Palindrom kelime yok."<<endl;
			}
		}
		else if(secim !=8){
			cout<<"Yanlis secim yaptiniz...";
		}
	}
	
	return 0;
}
