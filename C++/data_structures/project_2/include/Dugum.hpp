
/**
* @file Dugum.hpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/



#ifndef DUGUM_HPP
#define DUGUM_HPP


#include "BST.hpp"

class Dugum
{
	public:
		Dugum(const string&, Dugum*);
		string eleman;
		Dugum *ileri;
		BST *agac;
};

#endif
