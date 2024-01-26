#include<iostream>
#include<conio.h>
#include"sepetKontrol.h"
#include<cstdlib>

// tanımlama
void menuKurucu(sepetKontrol **sepetler);
bool menuSepetDegistir(sepetKontrol **sepetler);
int girdiKontrol(int bas, int son);
using namespace std;


int main()
{	
	sepetKontrol* sepetler=new sepetKontrol();
	int secenek;
	while(true)
	{	
		
		
			cout  <<"1.Yeni sepet olustur."
			<<endl<<"2.Sepetleri degistir."
			<<endl<<"3.Ekrani temizle."
			<<endl<<"4.Cikis."
			<<endl<<"Secenek giriniz:";
			secenek= girdiKontrol(1,5);
			if(secenek==1)
			{	
				//kurucu yeni oluşturacağı için burada siliyoruz,
				delete sepetler;
				menuKurucu(&sepetler);
				sepetler->sepetleriYazdir();
			}
			else if(secenek==2)
			{
				if(menuSepetDegistir(&sepetler)==true)
					sepetler->sepetleriYazdir();
			}
			else if(secenek==3)
				system("cls"); 
			else if(secenek==4)
				return 0;
			 
			
			
	}
	
}
//bas dahil son dahil değil
int girdiKontrol(int bas, int son)
{
	int a;
	while(true)
	{
		
		cin>>a;
		if(bas<=a&&a<son)
			return a;
		else
		cout<<endl<<"Gecerli girdi degil."
			<<bas<<" ile "<<son<<" arasinda bir deger giriniz:";
	}
}
// sepet kurucunun hangi şartlara göre kuruklacağını söylüyor
void menuKurucu(sepetKontrol **sepetler)
{
		//değer almak zorunda
		
		int secenekSayisi=4;
		cout  <<"1.7 top barindiran 10 sepet olustur."
		<<endl<<"2.Sepet sayisini belirle(Top Sayisi:7)."
		<<endl<<"3.Top sayisini belirle(Sepet Sayisi:10)."
		<<endl<<"4.Sepet ve Top sayisini belirle."
		<<endl<<"Seciminizi giriniz:";
		
		int secenek= girdiKontrol(1,secenekSayisi+1);
		
		if(secenek==1)
			*sepetler=new sepetKontrol();
		else if(secenek==2)
		{
			cout<<"Sepet sayisi:";
			*sepetler=new sepetKontrol(girdiKontrol(1,101),7);
		}
		else if(secenek==3)
		{
			cout<<"Top sayisi:";
			*sepetler=new sepetKontrol(10,girdiKontrol(1,81));
		}
		else if(secenek==4)
		{
			cout<<"Sepet sayisi ve Top sayisini sirayla giriniz:";
			*sepetler=new sepetKontrol(girdiKontrol(1,101),girdiKontrol(1,101));
		}
	
}
bool menuSepetDegistir(sepetKontrol **sepetler)
{	int hedef, kaynak;

	cout<<"Degistirilmesi gereken sepetleri sirayla giriniz"
	<<endl<<"Degistirme islemini iptal etmek icin \"0\" giriniz."<<endl;
	cout<<"1.Sepeti Gir:";
	hedef=girdiKontrol(0,(*sepetler)->getSepetAdedi()+1);
	cout<<"2.Sepeti Gir:";
	kaynak=girdiKontrol(0,(*sepetler)->getSepetAdedi()+1);;
	
	//iptal isteği
	if(kaynak==0&&hedef==0)
		return false;

	//kontrol edilmiş değerlerle sepetin değiştirme işlemi yapılıyor
	
	(*sepetler)->sepetDegistir(hedef,kaynak);
	
	return true;
}
