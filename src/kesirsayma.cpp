#include <iostream>
using namespace std;
int sonuc = 0;
double taban = 0.33333333334;
double tavan = 0.5;

/*
+ n ve d nin pozitif tam sayýlar olduðu n/d kesirini düþünün.
+ n ve d, n < d ve EKOK(n,d)= 1 deðerlerini saðlar.
+ d (kuçük eþit) 8 için iþlemleri tamamlarsak þunu elde ederiz:
+ 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7 , 1/2, 4/7, 3/ 5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
+ 1/3 ile 1/2 arasýnda 3 kesir olduðu görülmekte.
+ d (küçük eþit) 12.000 için 1/3 ile 1/2 arasýnda kaç tane kesir bulunur?
*/

int ortakBolenBul(int n, int d);

int araliktakiKesirleriBul(int limit);

int main() {
	cout << "Merhaba, programý baþlatmak için bir limit deðeri giriniz: " << endl;
	int limit = 0;
	cin >> limit;
	int araliktakiKesirSayisi = araliktakiKesirleriBul(limit);
	cout << "Verilen limit deðeri için aralýktaki kesir sayýsý: " << araliktakiKesirSayisi;
	// Bu programdan elde edilen sonuç: 7295372
	// Ýstenilen deðer üzerinden doðru sonucun elde edilme süresi: 3 dakika (yaklaþýk)
	// Sorunun doðru yanýtý: 7295372
	return 0;
}

int araliktakiKesirleriBul(int limit) {
	// Bu fonksiyon verilen deðerlere göre kesirler oluþturur ve kesirlerin istenilen aralýkta ve istenilen özelliklere sahip olmasýný saðlar.
    int d = limit;
    // Payý oluþturalým (n).
	for (int n = 1; n < d; n++) {
		// Pay deðeri için olabilecek tün payda (d) deðerlerini oluþturalým.
		for (int d = limit; n < d ; d--) {
			// Oluþturulan deðerin kesrini elde edelim.
			double kesir = (double)n/(double)d;
			// Elde edilen kesrin verilen taban ve tavan deðerleri arasýnda olup olmadýðýný belirleyelim.
			if (taban < kesir && kesir < tavan) {
				// Verilen kesrin pay ve paydasýnýn en küçük ortak böleninin 1 olmasý koþulunu kontol edelim.
				if (ortakBolenBul(n, d) == 1) {
					sonuc++;
				}
			}
		}
	}
	return sonuc;
}

int ortakBolenBul(int n, int d) {
	// Bu fonksiyon verilen deðerlerin en küçük ortak bölenini hesaplar.
	int ortakbolen = 1;
	for(int i = 1; i <= n ; i++){
		if(n % i == 0 && d % i == 0){
			ortakbolen = i;
		}
	}
	return ortakbolen;
}
