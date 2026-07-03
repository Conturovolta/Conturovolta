#include <stdio.h>

int main() {
    int r1, c1; // Matris A'nın Satır (row) ve Sütun (column) sayıları
    int r2, c2; // Matris B'nin Satır ve Sütun sayıları
    int i, j, k;

    // --- 1. ADIM: BOYUT ALMA VE HATA KONTROL DÖNGÜSÜ ---
    while (1) {
        printf("Matris A'nin satir ve sutun sayisini giriniz (Ornek: 2 3): ");
        scanf("%d %d", &r1, &c1);

        printf("Matris B'nin satir ve sutun sayisini giriniz (Ornek: 3 4): ");
        scanf("%d %d", &r2, &c2);

        // Lineer Cebir Kuralı Kontrolü: A'nın sütunu B'nin satırına eşit olmalı!
        if (c1 == r2) {
            break; // Boyutlar doğruysa sonsuz döngüyü kır ve ilerle
        } 
        
        // Boyutlar yanlışsa program buraya düşer, uyarır ve while sayesinde başa döner
        printf("\n[UYARI] Matrisler carpilamaz! Birinci matrisin SUTUN sayisi ile ikinci matrisin SATIR sayisi esit olmalidir.\n");
        printf("Lutfen boyutlari tekrar giriniz...\n\n");
    }

    printf("\nBoyutlar onaylandi! Matrisler hafizada olusturuluyor.\n");
    
    // Değişken boyutlu dizilerimizi (VLA) tanımlıyoruz
    int matrisA[r1][c1];
    int matrisB[r2][c2];
    int sonuc[r1][c2]; // Sonuç matrisinin boyutu r1 x c2 olur

    // --- 2. ADIM: SONUÇ MATRİSİNİN İÇİNİ SIFIRLAMA ---
    // Kumbara (+=) mantığımızın temiz çalışması için içini 0 ile dolduruyoruz
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            sonuc[i][j] = 0;
        }
    }

    // --- 3. ADIM: MATRİS A ELEMANLARINI KULLANICIDAN ALMA ---
    printf("\nMatris A elemanlarini giriniz:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrisA[i][j]);
        }
    }

    // --- 4. ADIM: MATRİS B ELEMANLARINI KULLANICIDAN ALMA ---
    printf("\nMatris B elemanlarini giriniz:\n");
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrisB[i][j]);
        }
    }

    // --- 5. ADIM: ASIL MATRİS ÇARPIM ALGORİTMASI (ÜÇLÜ DÖNGÜ) ---
    // i: Sol elimiz (A'nın satırı), j: Sağ elimiz (B'nin sütunu), k: Gözümüz (Eşleştirici)
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            for(k = 0; k < c1; k++) {
                // Çarpıyoruz ve sonuc[i][j] kumbarasında üst üste topluyoruz
                sonuc[i][j] += matrisA[i][k] * matrisB[k][j];
            }
        }
    }

    // --- 6. ADIM: ELDE EDİLEN SONUÇ MATRİSİNİ YAZDIRMA ---
    printf("\nCarpim Sonucu (Matris A x Matris B):\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            printf("%d ", sonuc[i][j]); // Elemanı yazdır ve boşluk bırak
        }
        printf("\n"); // Satır bitince alt satıra geç
    }

    return 0;
}