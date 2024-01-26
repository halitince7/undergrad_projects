#ifndef top_h
#define top_h


using namespace std;
class top
{
private:
	char renk[16];
public:
	top(void);

	~top(void);
	void setRenk(char *renk);
	char *getRenk();
	void isimYazdir();
	void adresYazdir();
};

#endif