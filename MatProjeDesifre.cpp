
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
    //sayinin 2,3,4,5... sayýlarýyla bölümünün tam kýsmý 0'dan büyük olduðu sürece devam edecek.
    while (sayi > 0) {
        //bölümün kalanlarýný bir dizide tutalým

        kalan[i] = sayi % a;

        //kalanlarý tersten yazýnca faktoriyel tabandaki sayýyý elde ederiz.
        //bunu hafýzda dizi olarak deðil de sayý olarak tutabilmek için kalanlarý 10'un artan üsleriyle çarpýp topluyoruz.

        sonuc += kalan[i] * pow(10, i);

        //sayiyi 2'ye bölüp her döngüde böleni arttýralým. Döngü bölümün tam kýsmý sýfýr olana kadar devam eder

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

    //sayýmýzýn kaç bsamaklý olduðunu bulalým
    while (sayi / i > 0) {
        i *= 10;
        k++;
    }

    //sayýyýnýn basamaklarýný bir diziye atalým
    for (int i = 1; i <= k; i++)
    {
        sayibasamaklari[k - i] = sayi % 10;
        sayi /= 10;
        
    }
    //sayý basamaklarýný önceden yazdýðýmýz faktoriyel fonksiyonunu kullanarak sýrasý ile 1!,2!,3!.. sayýlarý ile çarpalým.
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
    //asal sayýlar
    int asallar[] = { 29,31,37,41,43,47,53,59,61,67,71,73,79,83,89 };
    //önceki sayýnýn 93'e kaç kez bölündüðü
    int bolum[] = { 22 ,24 ,11 ,24 ,24 ,13 ,32 };
    char sifre[20];
    int a[20];

    //þifrelenmiþ halini alalým
    printf("Sifreyi giriniz: ");
    gets_s(sifre);

    //rastgele sayý dizisinin ASCII kodlarýný bulup bir diziye atalým
    rakamAscii(anahtar, anahatarascii);
   
    while (sifre[i] != '\0') {
        //kelimenin harflerinin int deðerini yani ASCII kodunu a dizisine atalým.
        a[i] = int(sifre[i]);

        //Gelen deðerden 33 çýkarýp 93'e kaç kere bölündüðüyle çarpalým.
        a[i] = a[i] - 33;
        a[i] = a[i] + bolum[i] * 93;

        //Ýlk deðere ulaþmak için deðerleri birbirinden çýkartalým.
        x = cikarma(a[i], -onluk_taban_faktoryel_cevirme(asallar[i%15]));
        x = cikarma(x, -onluk_taban_faktoryel_cevirme(anahatarascii[i%8]));

        //en son gelen deðeri onluk tabana çevirelim
        b = faktoryel_onluk_taban_cevirme(x);
        
        //gelen deðeri char biçiminde yazdýralým
        printf("%c", b);
        i++;
    }
}
