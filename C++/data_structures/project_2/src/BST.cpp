/**
* @file BST.cpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/


#include "BST.hpp"

		void BST::AraveEkle(Dugum2 *&alt_dugum, const string& veri ){
			if( alt_dugum == NULL) alt_dugum = new Dugum2(veri,NULL,NULL);
			else if(veri < alt_dugum->veri)
				AraveEkle(alt_dugum->sol,veri);
			else if(veri > alt_dugum->veri)
				AraveEkle(alt_dugum->sag,veri);
			else return;
		}
		
		void BST::Inorder(Dugum2 *alt_dugum)const{
			if(alt_dugum != NULL){
				Inorder(alt_dugum->sol);
				cout<<alt_dugum->veri<<" ";
				Inorder(alt_dugum->sag);
			}
		}

		bool BST::ElemanVarmi(Dugum2 *alt_dugum, const string& eleman)const{
			while(alt_dugum != NULL){
				if(eleman<alt_dugum->veri)
					alt_dugum = alt_dugum->sol;
				else if (eleman>alt_dugum->veri)
					alt_dugum = alt_dugum->sag;
			 	else if (eleman == alt_dugum->veri)
			 		return true;
			}
			return false;
		}
	
		
		
		BST::BST(){
			kok=NULL;
		}
		bool BST::Bosmu(){
			return kok == NULL;
		}
		void BST::Ekle(const string& yeni){
			AraveEkle(kok,yeni);
		}
		void BST::inorder()const{
			Inorder(kok);
		}
		
		bool BST::elemanVarmi(string eleman)const{
			ElemanVarmi(kok,eleman);
		}
		
		


