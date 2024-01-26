#include "KimlikNo.h"

KimlikNo KimlikNoOlustur(){
	KimlikNo this;
	this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->tcNo=malloc(sizeof(char)*11);
	//time_t t;
	//srand((unsigned)time(&t));
	int i;
	int array[11];
	array[0] = rand()%9+1;
    for(i=1;i<9;i++){
    	array[i]= rand()%10;
    }
    int top1 = (array[0]+array[2]+array[4]+array[6]+array[8])*7;
    int top2 = array[1]+array[3]+array[5]+array[7];
    array[9] = (top1-top2) % 10;
    int top=0;
    for(i=0;i<10;i++){
        top += array[i];
    }
    array[10] = top % 10;
	int n =0;
	for(i=0;i<11;i++){
		n+=sprintf(&this->tcNo[n],"%d",array[i]);
	}
	
	//printf("TcNo: %s\n",this->tcNo);
	
	
	this->isTrue = &_isTrue2;
	this->Yoket = &_Yoket3;
	return this;
}



boolean _isTrue2(const KimlikNo this){
	int i;
	int array[11];
	for(i=0;i<11;i++){
		array[i] = this->tcNo[i] - '0';
	}
	int top1 = (array[0]+array[2]+array[4]+array[6]+array[8])*7;
    int top2 = array[1]+array[3]+array[5]+array[7];
	if(array[9] != (top1-top2) % 10) return false;
	int top=0;
    for(i=0;i<10;i++){
        top += array[i];
    }
    if(array[10] != top % 10) return false;
    return true;
	
}

void _Yoket3(KimlikNo this){
	if(this==NULL) return;
	free(this->tcNo);
	free(this);
}