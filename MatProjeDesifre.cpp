
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//faktoriyel alma fonksiyonu
int faktoriyel(int sayi) {
    int faktoriyel = 1;
    for (int i = 2; i <= sayi; i++) {
        faktoriyel *= i;
    }
    return faktoriyel;
    
}

void rakamAscii(int dizi[], int Ascii[]) {


    for (int i = 0; i < 8; i++)
    {
        char a = dizi[i];


        Ascii[i] = a + '0';

    }

}




int onluk_taban_faktoryel_cevirme(int sayi) {
    int  a = 2, i = 0;
    int kalan[30];
    int sonuc = 0;
    //sayinin 2,3,4,5... say�lar�yla b�l�m�n�n tam k�sm� 0'dan b�y�k oldu�u s�rece devam edecek.
    while (sayi > 0) {
        //b�l�m�n kalanlar�n� bir dizide tutal�m

        kalan[i] = sayi % a;

        //kalanlar� tersten yaz�nca faktoriyel tabandaki say�y� elde ederiz.
        //bunu haf�zda dizi olarak de�il de say� olarak tutabilmek i�in kalanlar� 10'un artan �sleriyle �arp�p topluyoruz.

        sonuc += kalan[i] * pow(10, i);

        //sayiyi 2'ye b�l�p her d�ng�de b�leni artt�ral�m. D�ng� b�l�m�n tam k�sm� s�f�r olana kadar devam eder

        sayi /= a;
        a++;
        i++;

    }
    return sonuc;
}

int cikarma(int a, int b) {

    int x = 0;
    int sonuc[4];
    int c = 4444;
    int toplam = a + b + c;
    for (int i = 0;i < 4;i++) {
        sonuc[3 - i] = toplam % 10;
        toplam /= 10;
    }

    for (int i = 0;i < 4;i++) {
        if (sonuc[i] >= 4) {
            sonuc[i] = sonuc[i] % 4;

        }
        x += sonuc[i] * pow(10, 3 - i);
    }
    return x;
}


int faktoryel_onluk_taban_cevirme(int sayi) {
    int i = 1;
    int a = 0, x;
    int faktoryel_tabandaki_sayi = 0;
    int k = 0;
    int sayibasamaklari[100];

    //say�m�z�n ka� bsamakl� oldu�unu bulal�m
    while (sayi / i > 0) {
        i *= 10;
        k++;
    }

    //say�y�n�n basamaklar�n� bir diziye atal�m
    for (int i = 1; i <= k; i++)
    {
        sayibasamaklari[k - i] = sayi % 10;
        sayi /= 10;
        
    }
    //say� basamaklar�n� �nceden yazd���m�z faktoriyel fonksiyonunu kullanarak s�ras� ile 1!,2!,3!.. say�lar� ile �arpal�m.
    for (int i = 0; i < k; i++) {
        x = sayibasamaklari[i];
        faktoryel_tabandaki_sayi += x * faktoriyel(k - i);

    }

    return faktoryel_tabandaki_sayi;
}


int main()
{
  
    int b,x,i=0;
    //bize verilen anahtar
    int anahtar[] = { 2,9,1,0,1,9,2,3 };
    int anahatarascii[20];
    //asal say�lar
    int asallar[] = { 29,31,37,41,43,47,53,59,61,67,71,73,79,83,89 };
    //�nceki say�n�n 93'e ka� kez b�l�nd���
    int bolum[] = { 22 ,24 ,11 ,24 ,24 ,13 ,32 };
    char sifre[20];
    int a[20];

    //�ifrelenmi� halini alal�m
    printf("Sifreyi giriniz: ");
    gets_s(sifre);

    //rastgele say� dizisinin ASCII kodlar�n� bulup bir diziye atal�m
    rakamAscii(anahtar, anahatarascii);
   
    while (sifre[i] != '\0') {
        //kelimenin harflerinin int de�erini yani ASCII kodunu a dizisine atal�m.
        a[i] = int(sifre[i]);

        //Gelen de�erden 33 ��kar�p 93'e ka� kere b�l�nd���yle �arpal�m.
        a[i] = a[i] - 33;
        a[i] = a[i] + bolum[i] * 93;

        //�lk de�ere ula�mak i�in de�erleri birbirinden ��kartal�m.
        x = cikarma(a[i], -onluk_taban_faktoryel_cevirme(asallar[i%15]));
        x = cikarma(x, -onluk_taban_faktoryel_cevirme(anahatarascii[i%8]));

        //en son gelen de�eri onluk tabana �evirelim
        b = faktoryel_onluk_taban_cevirme(x);
        
        //gelen de�eri char bi�iminde yazd�ral�m
        printf("%c", b);
        i++;
    }
}
