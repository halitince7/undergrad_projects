#include "IMEINo.h"


IMEINo IMEINoOlustur(){
	IMEINo this;
	
	this = (IMEINo)malloc(sizeof(struct IMEINO));
	this->imei=malloc(sizeof(char)*15);
	
	int i;
	int array[15];
	//time_t t;
	//srand((unsigned)time(&t));
	
	
	for(i=0;i<14;i++){
		array[i] = rand() %10; 
	}
	
	int top = 0;
    int temp;
    for(i=0; i<14; i++){
	    if(i % 2 == 0){
            top += array[i];
        }
        else{
            temp = (array[i]*2) % 10;
            if(array[i]*2 >= 10){
                temp += 1;
            }
            top += temp;
        }
    }
    if(top % 10 != 0) array[14] = 10 - (top % 10); else array[14] = 0;
	
	
	int n =0;
	for(i=0;i<15;i++){
		n+=sprintf(&this->imei[n],"%d",array[i]);
	}

	//printf("imeiNo: %s\n",this->imei);
	
	this->isTrue = &_isTrue;
	this->Yoket = &_Yoket;
	
	return this;
}


boolean _isTrue(const IMEINo this){
	int i;
	int array[15];
	for(i=0;i<15;i++){
		array[i] = this->imei[i] - '0';
	}
	int top = 0;
    int temp;
    for(i=0; i<14; i++){
	    if(i % 2 == 0){
            top += array[i];
        }
        else{
            temp = (array[i]*2) % 10;
            if(array[i]*2 >= 10){
                temp += 1;
            }
            top += temp;
        }
    }
    int den = 0;
    if(top % 10 != 0) den = 10 - (top % 10);
    
	return array[14] == den;
	
}

void _Yoket(IMEINo this){
	if(this==NULL) return;
	free(this->imei);
	free(this);
}