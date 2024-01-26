/**
* @file Dugum2.hpp
* @description 
* @course 2. Öğretim C Grubu
* @assignment 3. ödev
* @date 9.12.2017
* @author Halit İNCE (ince@sakarya.edu.tr)  
*/



#ifndef DUGUM2_HPP
#define DUGUM2_HPP


#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fstream>
using namespace std;


class Dugum2{
	public:
		string veri;
		Dugum2 *sol;
		Dugum2 *sag;
		
		Dugum2(const string& , Dugum2* , Dugum2*   );
};



#endif
