#include <iostream>
using namespace std;
int sonuc = 0;
double taban = 0.33333333334;
double tavan = 0.5;

/*
+ n ve d nin pozitif tam say�lar oldu�u n/d kesirini d���n�n.
+ n ve d, n < d ve EKOK(n,d)= 1 de�erlerini sa�lar.
+ d (ku��k e�it) 8 i�in i�lemleri tamamlarsak �unu elde ederiz:
+ 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7 , 1/2, 4/7, 3/ 5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
+ 1/3 ile 1/2 aras�nda 3 kesir oldu�u g�r�lmekte.
+ d (k���k e�it) 12.000 i�in 1/3 ile 1/2 aras�nda ka� tane kesir bulunur?
*/

int ortakBolenBul(int n, int d);

int araliktakiKesirleriBul(int limit);

int main() {
	cout << "Merhaba, program� ba�latmak i�in bir limit de�eri giriniz: " << endl;
	int limit = 0;
	cin >> limit;
	int araliktakiKesirSayisi = araliktakiKesirleriBul(limit);
	cout << "Verilen limit de�eri i�in aral�ktaki kesir say�s�: " << araliktakiKesirSayisi;
	// Bu programdan elde edilen sonu�: 7295372
	// �stenilen de�er �zerinden do�ru sonucun elde edilme s�resi: 3 dakika (yakla��k)
	// Sorunun do�ru yan�t�: 7295372
	return 0;
}

int araliktakiKesirleriBul(int limit) {
	// Bu fonksiyon verilen de�erlere g�re kesirler olu�turur ve kesirlerin istenilen aral�kta ve istenilen �zelliklere sahip olmas�n� sa�lar.
    int d = limit;
    // Pay� olu�tural�m (n).
	for (int n = 1; n < d; n++) {
		// Pay de�eri i�in olabilecek t�n payda (d) de�erlerini olu�tural�m.
		for (int d = limit; n < d ; d--) {
			// Olu�turulan de�erin kesrini elde edelim.
			double kesir = (double)n/(double)d;
			// Elde edilen kesrin verilen taban ve tavan de�erleri aras�nda olup olmad���n� belirleyelim.
			if (taban < kesir && kesir < tavan) {
				// Verilen kesrin pay ve paydas�n�n en k���k ortak b�leninin 1 olmas� ko�ulunu kontol edelim.
				if (ortakBolenBul(n, d) == 1) {
					sonuc++;
				}
			}
		}
	}
	return sonuc;
}

int ortakBolenBul(int n, int d) {
	// Bu fonksiyon verilen de�erlerin en k���k ortak b�lenini hesaplar.
	int ortakbolen = 1;
	for(int i = 1; i <= n ; i++){
		if(n % i == 0 && d % i == 0){
			ortakbolen = i;
		}
	}
	return ortakbolen;
}
