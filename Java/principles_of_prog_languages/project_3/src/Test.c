#include "RastgeleKisi.h"


int main(){
	
	
	
	
	int i;
	int kisi_sayisi;
	
	int secim = 0;
	while(secim != 3){
		printf("1- Rastgele Kisi Uret\n");
		printf("2- Uretilmis Dosya Kontrol\n");
		printf("3- Cikis\n");
		scanf("%d",&secim);
		
		
		
		if(secim == 1){
			printf("Kac kisi uretmek istiyorsunuz?");
			scanf("%d",&kisi_sayisi);
			FILE *fp;
			fp=fopen("kisiler.txt","a");
			for(i=0;i<kisi_sayisi;i++){
				RastgeleKisi rs = RastgeleKisiOlustur();
				fprintf(fp,"%s %s %d %s %s\n",rs->kisi->tcNo->tcNo,rs->kisi->adSoyad,rs->kisi->yas,rs->kisi->tel->telNo,rs->kisi->tel->imeiNo->imei);
				rs->Yoket(rs);
				//if(i!=kisi_sayisi-1) fprintf(fp,"\n");
				//printf("\n");
			}
			fclose(fp);
		}
		
		else if(secim == 2){
			int dogrutc = 0;
			int dogruimei = 0;
			int yanlistc = 0;
			int yanlisimei = 0;
			FILE *fp;
			char buff1[100];
			char buff2[100];
			char buff3[100];
			char buff4[100];
			char buff5[100];
			char buff6[100];
			kisi_sayisi=0;
			
			RastgeleKisi rs = RastgeleKisiOlustur();
			
			fp=fopen("kisiler.txt","r");
			if(fp == NULL){
				printf("dosya acarken sorun!");
				return 0;
			}
			//else printf("dosya acildi");
			
			while(fscanf(fp, "%s %s %s %s %s %s", buff1, buff2, buff3, buff4, buff5, buff6) != EOF)
			{
				rs->kisi->tcNo->tcNo = buff1;
				rs->kisi->tel->imeiNo->imei = buff6;
				//printf("%s %s\n",buff1,buff6);
				if(rs->kisi->tcNo->isTrue(rs->kisi->tcNo))	dogrutc++; else yanlistc++;
				if(rs->kisi->tel->imeiNo->isTrue(rs->kisi->tel->imeiNo)) dogruimei++; else yanlisimei++;
			}
			
			//rs->Yoket(rs);
			fclose(fp);
			printf("TC Kimlik Kontrol \n%d     Gecerli\n%d     Gecersiz\n \nIMEI Kontrol\n%d     Gecerli\n%d     Gecersiz\n",dogrutc,yanlistc,dogruimei,yanlisimei );
		}
		
		else if(secim==3){
			break;
		}
		else secim=0;
	
	}
	
	
	
	
	
	
	return 0;
}