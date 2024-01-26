/**
* @file ListeGezici.hpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/



#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP


#include "Dugum.hpp"


class ListeGezici
{
		public:
			Dugum *simdiki;
			ListeGezici();
			
			ListeGezici(Dugum *dugum);
			
			bool SonaGeldimi()const;
			
			void ilerle();
			
			const string& Getir()const;
};

#endif
