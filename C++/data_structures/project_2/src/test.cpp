/**
* @file test.cpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/




#include "BagliListe.hpp"


int main()
{
	  printf("klasor adresi yaz\n");
	  DIR *p;
	  struct dirent *pp;
	  char dizin[70];
	  cin>>dizin;
	  p = opendir (dizin);
	
	  string dosyalar[100]; 
	  int dosyaSay = 0;
	  if (p != NULL)
	  {
	    while ((pp = readdir (p))!=NULL) {
	      int length = strlen(pp->d_name);
	      if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0) {
	          dosyalar[dosyaSay] = pp->d_name;
	          dosyaSay++;
	      }
	    }
	
	    (void) closedir (p);
	  }
	  
		BagliListe *dizi = new BagliListe();
		for(int i=0; i<dosyaSay; i++){
			dizi->Ekle(dosyalar[i],dizin);
		}
		
		int secim=0;
		while(secim!=3){
			cout<<endl<<endl<<"Seciminizi giriniz:"<<endl<<
		      "1. Arama Yap"<<endl<<
		      "2. Listele"<<endl<<
		      "3. Cikis"<<endl;
			cin>>secim;
			if(secim==2){
				dizi->Listele();
			}
			else if(secim==1){
				string aranan;
				cout<<"Aranan:";
				cin>>aranan;
				dizi->AramaYap(aranan);
			}
			
		}
		
	
    
    	delete dizi;
    
    return 0;
}
