/**
* @file BST.cpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/


#include "Dugum.hpp"

		Dugum::Dugum(const string& yeni="", Dugum *n=NULL)
		{
			eleman=yeni;
			ileri=n;
			agac = new BST();
		}
		
