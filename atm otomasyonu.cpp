#include <stdio.h>
#include <stdlib.h>

// Kullan�c� bakiyesini tan�mla
float bakiye = 1000.0;

// Fonksiyon prototipleri
void menuGoster();
void paraYatir();
void paraCek();
void bakiyeSorgula();

int main() {
    int secim;

    while (1) {
        menuGoster();
        printf("Bir islem secin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                paraYatir();
                break;
            case 2:
                paraCek();
                break;
            case 3:
                bakiyeSorgula();
                break;
            case 4:
                printf("Cikis yap�l�yor...\n");
                exit(0);
                break;
            default:
                printf("Gecersiz se�im! L�tfen tekrar deneyin.\n");
        }
    }

    return 0;
}

// Men� fonksiyonu
void menuGoster() {
    printf("\n--- ATM Otomasyon Sistemi ---\n");
    printf("1. Para Yatirma\n");
    printf("2. Para Cekme\n");
    printf("3. Bakiye Sorgulama\n");
    printf("4. Cikis\n");
}

// Para yat�rma fonksiyonu
void paraYatir() {
    float miktar;
    printf("Yatirmak istediginiz tutari girin: ");
    scanf("%f", &miktar);

    if (miktar <= 0) {
        printf("Ge�ersiz tutar! L�tfen tekrar deneyin.\n");
    } else {
        bakiye += miktar;
        printf("Basariyla yatirildi! Guncel bakiyeniz: %.2f\n", bakiye);
    }
}

// Para �ekme fonksiyonu
void paraCek() {
    float miktar;
    printf("Cekmek istediginiz tutari girin: ");
    scanf("%f", &miktar);

    if (miktar <= 0) {
        printf("Gecersiz tutar! L�tfen tekrar deneyin.\n");
    } else if (miktar > bakiye) {
        printf("Yetersiz bakiye! Mevcut bakiyeniz: %.2f\n", bakiye);
    } else {
        bakiye -= miktar;
        printf("Basariyla cekildi! Guncel bakiyeniz: %.2f\n", bakiye);
    }
}

// Bakiye sorgulama fonksiyonu
void bakiyeSorgula() {
    printf("Mevcut bakiyeniz: %.2f\n", bakiye);
}

