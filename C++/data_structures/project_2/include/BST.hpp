/**
* @file BST.hpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/



#ifndef BST_HPP
#define BST_HPP



#include "Dugum2.hpp"

class BST{
	private:
		Dugum2 *kok;
		
		void AraveEkle(Dugum2*& , const string&  );
		
		void Inorder(Dugum2*)const;

		bool ElemanVarmi(Dugum2*, const string& )const;
		
	public:
		
		
		BST();
		bool Bosmu();
		void Ekle(const string& );
		void inorder()const;
		
		bool elemanVarmi(string )const;
		
		
	
};


#endif
