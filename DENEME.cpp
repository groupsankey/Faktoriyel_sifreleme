// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int faktoriyel(int sayi) {
    int faktoriyel = 1;
    for (int i = 2; i <= sayi; i++) {
        faktoriyel *= i;
    }
    return faktoriyel;

}

//4'lük tabanda eldesiz toplama fonksiyonu
int toplama(int a, int b, int c) {

    int x = 0;
    int sonuc[4];
    int toplam = a + b + c;
    //bize gelen 3 sayıyı onluk tabanda toplayalım
    //sonra sayıyı basamaklarına ayırıp her basamağı dizinin bir elemanına atalım.
    for (int i = 0; i < 4; i++) {
        sonuc[3 - i] = toplam % 10;
        toplam /= 10;
    }
    //sayının basamaklarında 4'ten büyük bir rakam varsa 4 ile modunu alalım.
    for (int i = 0; i < 4; i++) {
        if (sonuc[i] >= 4) {
            sonuc[i] = sonuc[i] % 4;

        }
        //sayının basamaklarını değiştirdikten sonra 10'un azalan üsleriyle çarpıp sayıyı elde edelim.
        x += sonuc[i] * pow(10, 3 - i);
    }
    return x;
}

//kelimenin harflerinin ASCII kodlarını bulup diziye atan fonksiyon.
void Ascii_Cevirme(char kelime[], int Asciikarsiligi[]) {

    int i = 0;

    while (kelime[i] != '\0') {


        Asciikarsiligi[i] = int(kelime[i]);

        i++;

    }


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
    int kalan[50];
    int sonuc = 0;
    //sayinin 2,3,4... sayıları ile bölümünün tam kısmı 0'dan büyük olduğu sürece döner.
    while (sayi > 0) {
        //sayının kalanlarını bir diziye atalım.
        kalan[i] = sayi % a;
        sayi /= a;
        //faktoriyel tabandaki sayıyı elde etmek için kalanları tersten yazmamız gerekiyor.
        //sayıyı dizi olarak değil de sayı olarak tutmak için kalanları 10'un üsleriyle çarpalım.
        sonuc += kalan[i] * pow(10, i);
        //her döngüde bölen sayıyı arttıralım.
        a++;
        i++;

    }
    return sonuc;
}

int faktoryel_onluk_taban_cevirme(int sayi) {
    int i = 1;
    int a = 0, x;
    int faktoryel_tabandaki_sayi = 0;
    int k = 0;
    int sayibasamaklari[100];

    while (sayi / i > 0) {
        i *= 10;
        k++;
    }

    for (int i = 1; i <= k; i++)
    {
        sayibasamaklari[k - i] = sayi % 10;
        sayi /= 10;
        printf("%d \n", sayibasamaklari[k - i]);
    }

    for (int i = 0; i < k; i++) {
        x = sayibasamaklari[i];
        faktoryel_tabandaki_sayi += x * faktoriyel(k - i);

    }

    return faktoryel_tabandaki_sayi;
}

int main()
{
    int a, b, c, d, e, i = 0;
    char sifre[20];
    //kullandığımız rastgele sayı dizisi.
    int anahtar[] = { 2,9,1,0,1,9,2,3 };
    int bolum[20];
    //kullandığımız asal sayılar dizisi.
    int asallar[] = { 29,31,37,41,43,47,53,59,61,67,71,73,79,83,89 };
    int anahtarascii[20];
    char harf[20];
    printf("Sifrelenecek kelimeyi giriniz: ");
    gets_s(harf);
    int Asciikarsiligi[20];
    //girilen kelimenin ASCII kodlarını bulup Asciikarsiligi dizisne atar.
    Ascii_Cevirme(harf, Asciikarsiligi);
    //rastgele sayı dizisinin ASCII karşılıklarını bulur.
    rakamAscii(anahtar, anahtarascii);

    //Dizinin boş olan elemanına kadar döner.Böylece dizinin tüm değerlerini dönmüş olur. 
    while (harf[i] != '\0')
    {
        //harflerin ASCII karşılığını faktoriyel tabana çevirelim.
        a = onluk_taban_faktoryel_cevirme(Asciikarsiligi[i]);
        //asal sayıları faktoriyel tabana çevirelim.!5 elemanlı olduğu için 15 ile modunu alalım.
        b = onluk_taban_faktoryel_cevirme(asallar[i % 15]);
        //rastgele sayı dizisinin elemanlarının ASCII karşılığını faktoriyel tabana çevirelim.
        c = onluk_taban_faktoryel_cevirme(anahtarascii[i % 8]);

        //elde ettiğimiz sayılara 4'lük tabanda eldesiz toplama işlemini uygulayalım.
        d = toplama(a, b, c);

        //deşifre için sayının 93'e kaç kere bölündüğünü bulalım.
        e = d / 93;
        bolum[i] = e;

        //değerlerin istediğimiz aralıkta gelmesi için modunu alıp 33 ekleyelim.
        sifre[i] = d % 93 + 33;

        i++;
    }
    printf("Sifrelenmis hali: ");
    for (int i = 0; i < strlen(harf); i++)
    {
        printf("%c", sifre[i]);
    }
    printf("\n");
    int k = 0;
    printf("Bolumler: ");
    while (k < i)
    {
        printf("%d ,", bolum[k]);
        k++;
    }
}
