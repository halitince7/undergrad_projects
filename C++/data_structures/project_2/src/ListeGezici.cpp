/**
* @file ListeGezici.cpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/

#include "ListeGezici.hpp"


			ListeGezici::ListeGezici()
			{
				simdiki = NULL;
			}
			
			ListeGezici::ListeGezici(Dugum *dugum)
			{
				simdiki = dugum;
			}
			
			bool ListeGezici::SonaGeldimi()const{
			
				return simdiki == NULL;
			}
			
			void ListeGezici::ilerle()
			{
				simdiki = simdiki->ileri;
			}
			
			const string&  ListeGezici::Getir()const{
				return simdiki->eleman;
			}


