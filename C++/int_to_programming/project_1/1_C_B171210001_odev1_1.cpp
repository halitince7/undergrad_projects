/****************************************************************************
** SAKARYA �N�VERS�TES�
** B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
** B�LG�SAYAR M�HEND�SL��� B�L�M�
** PROGRAMLAMAYA G�R��� DERS�
**
** �DEV NUMARASI: Odev1 Soru1
** ��RENC� ADI.:  Halit �nce
** ��RENC� NUMARASI: b171210001
** DERS GRUBU: 1C
****************************************************************************/




#include <iostream>
using namespace std;
int main()
{
	int i, j, k;

	// ilk 2 satiri ekrana bastiran d�ng�
	for (i = 1; i<4; i++) {
		for (j = 1; j<25; j++) {
			if (j == 1 || j == 24 || i == 1)
				cout << "* ";
			else if (i == 2 && j == 2)
				cout << "S ";
			else if (i == 2 && j == 3)
				cout << "A ";
			else if (i == 2 && j == 4)
				cout << "U ";
			else if (i == 2 && j == 6)
				cout << "B ";
			else if (i == 2 && j == 7)
				cout << "I ";
			else if (i == 2 && j == 8)
				cout << "L ";
			else if (i == 2 && j == 9)
				cout << "G ";
			else if (i == 2 && j == 10)
				cout << "I ";
			else if (i == 2 && j == 11)
				cout << "S ";
			else if (i == 2 && j == 12)
				cout << "A ";
			else if (i == 2 && j == 13)
				cout << "Y ";
			else if (i == 2 && j == 14)
				cout << "A ";
			else if (i == 2 && j == 15)
				cout << "R ";

			else
				cout << "  ";
		}
		cout << endl;
	}

	//iki b�y�k ��gen ve bir k���k ��geni ekrana bastiran d�ng�ler
	for (i = 1; i <= 6; i++)
	{
		cout << "* ";
		for (j = 5; j >= i; j--)
		{
			cout << "  ";
		}
		for (k = 1; k <= (2 * i - 1); k++)
		{
			cout << "* ";
		}
		for (j = 5; j >= i; j--)
		{
			cout << "    ";
		}

		for (k = 1; k <= (2 * i - 1); k++)
		{
			cout << "* ";
		}
		for (j = 5; j >= i; j--)
		{

			if (i == 1 && (j == 3 || j == 2 || j == 1))
				cout << "* ";
			else if (i == 2 && j == 3)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << "* ";

		cout << "\n";
	}

	// ��genler arasinda kalan kismi ekrana bastiran d�ng�
	for (i = 1; i<4; i++) {
		for (j = 1; j<25; j++) {
			if (j == 1 || j == 24)
				cout << "* ";
			else if (i == 2 && j == 2)
				cout << "M ";
			else if (i == 2 && j == 3)
				cout << "U ";
			else if (i == 2 && j == 4)
				cout << "H ";
			else if (i == 2 && j == 5)
				cout << "E ";
			else if (i == 2 && j == 6)
				cout << "N ";
			else if (i == 2 && j == 7)
				cout << "D ";
			else if (i == 2 && j == 8)
				cout << "I ";
			else if (i == 2 && j == 9)
				cout << "S ";
			else if (i == 2 && j == 10)
				cout << "L ";
			else if (i == 2 && j == 11)
				cout << "I ";
			else if (i == 2 && j == 12)
				cout << "G ";
			else if (i == 2 && j == 13)
				cout << "I ";
			else if (i == 2 && j == 15)
				cout << "B ";
			else if (i == 2 && j == 16)
				cout << "O ";
			else if (i == 2 && j == 17)
				cout << "L ";
			else if (i == 2 && j == 18)
				cout << "U ";
			else if (i == 2 && j == 19)
				cout << "M ";
			else if (i == 2 && j == 20)
				cout << "U ";

			else
				cout << "  ";
		}
		cout << endl;
	}


	//iki b�y�k ��gen ve bir k���k ��geni ekrana bastiran d�ng�ler
	for (i = 1; i <= 6; i++)
	{
		cout << "* ";
		for (j = 5; j >= i; j--)
		{
			cout << "  ";
		}
		for (k = 1; k <= (2 * i - 1); k++)
		{
			cout << "* ";
		}

		for (j = 5; j >= i; j--)
		{

			if (i == 1 && (j == 3 || j == 2 || j == 1))
				cout << "* ";
			else if (i == 2 && j == 3)
				cout << "* ";
			else
				cout << "  ";
		}



		for (j = 5; j >= i; j--)
		{
			cout << "  ";
		}

		for (k = 1; k <= (2 * i - 1); k++)
		{
			cout << "* ";
		}

		for (j = 5; j >= i; j--)
		{
			cout << "  ";
		}

		cout << "* ";

		cout << "\n";
	}

	// son iki satiri ekrana bastiran d�ng�
	for (i = 1; i<3; i++) {
		for (j = 1; j<25; j++) {
			if (i == 2 || j == 1 || j == 24)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}


	cin >> i;
	return 0;
}