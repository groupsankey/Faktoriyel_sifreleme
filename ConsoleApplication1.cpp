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

int toplama(int a, int b, int c) {

    int x = 0;
    int sonuc[4];
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


void Ascii_Cevirme(char kelime[], int Asciikarsiligi[]) {

    int i = 0;

    while (kelime[i] != '\0') {
        if (kelime[i] == 'Ð')
        {
            Asciikarsiligi[i] = 63;
        }

        else if (kelime[i] == 'Ý')
        {
            Asciikarsiligi[i] = 64;
        }
        else if (kelime[i] == 'Ç')
        {
            Asciikarsiligi[i] = 62;
        }
        else if (kelime[i] == 'Ö')
        {
            Asciikarsiligi[i] = 81;
        }
        else if (kelime[i] == 'Þ')
        {
            Asciikarsiligi[i] = 87;
        }
        else if (kelime[i] == 'Ü')
        {
            Asciikarsiligi[i] = 88;
        }
        else {
            Asciikarsiligi[i] = int(kelime[i]);
        }
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
    while (sayi > 0) {
        kalan[i] = sayi % a;
        sayi /= a;
        sonuc += kalan[i] * pow(10, i);
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
    int anahtar[] = { 2,9,1,0,1,9,2,3 };
    int bolum[20];
    int asallar[] = { 29,31,37,41,43,47,53,59,61,67,71,73,79,83,89 };
    int anahtarascii[20];
    char harf[20];
    gets_s(harf);
    int Asciikarsiligi[20];
    Ascii_Cevirme(harf, Asciikarsiligi);
    rakamAscii(anahtar, anahtarascii);



    while (harf[i] != '\0')
    {
        a = onluk_taban_faktoryel_cevirme(Asciikarsiligi[i]);
        b = onluk_taban_faktoryel_cevirme(asallar[i % 15]);
        c = onluk_taban_faktoryel_cevirme(anahtarascii[i]);
        d = toplama(a, b, c);

        e = d / 93;
        d = d % 93 + 33;

        bolum[i] = e;

        printf("%c", d);

        i++;
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", bolum[i]);
    }
}
