#include <stdio.h>

int main()
{
    int secim = 0;

    while (1)
    { // Kullanıcı çıkış yapana kadar menü sürekli dönecek
        printf("\n=========================================\n");
        printf("       CELEYANTRONIK MUHENDISLIK MOTORU   \n");
        printf("=========================================\n");
        printf("1 - Matris Carpimi Hesapla\n");
        printf("2 - Islem Oncelikli Hesap Makinesi\n");
        printf("3 - Cikis\n");
        printf("Seciminiz: ");
        if (scanf("%d", &secim) != 1)
        {
            printf("[HATA]: Gecersiz karakter girdiniz!\n");
            break;
        }

        if (secim == 3)
        {
            printf("Programdan cikiliyor... Iyi calismalar!\n");
            break;
        }

        switch (secim)
        {
        case 1:
        {
            printf("\n--- MATRIS CARPIM MOTORU ALGORITMASI ---\n");
            int r1, c1, r2, c2;

            // Boyutları alalım
            printf("1. Matrisin satir ve sutun sayisini girin (Ornek: 2 3): ");
            scanf("%d %d", &r1, &c1);
            printf("2. Matrisin satir ve sutun sayisini girin (Ornek: 3 2): ");
            scanf("%d %d", &r2, &c2);

            // Matris çarpım kuralı kontrolü
            int r1, c1, r2, c2;
            while (1)
            {
                printf("1. Matrisin satir ve sutun sayisini girin (Ornek: 2 3): ");
                scanf("%d %d", &r1, &c1);
                printf("2. Matrisin satir ve sutun sayisini girin (Ornek: 3 2): ");
                scanf("%d %d", &r2, &c2);

                if (c1 == r2)
                {
                    break; // Boyutlar doğru, döngüden çık ve elemanları almaya geç!
                }
                printf("\n[SISTEM HATASI]: 1. matrisin sutun sayisi (%d), 2. matrisin satir sayisina (%d) esit olmalidir!\n Lutfen tekrar giriniz.\n\n", c1, r2);
            }

            int matris1[20][20], matris2[20][20], sonuc_matris[20][20] = {0};

            // 1. Matris Elemanları
            printf("\n1. Matrisin elemanlarini girin:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    printf("Matris1[%d][%d]: ", i, j);
                    scanf("%d", &matris1[i][j]);
                }
            }

            // 2. Matris Elemanları
            printf("\n2. Matrisin elemanlarini girin:\n");
            for (int i = 0; i < r2; i++)
            {
                for (int j = 0; j < c2; j++)
                {
                    printf("Matris2[%d][%d]: ", i, j);
                    scanf("%d", &matris2[i][j]);
                }
            }

            // Efsanevi 3'lü döngü ile matris çarpımı algoritması
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c2; j++)
                {
                    for (int k = 0; k < c1; k++)
                    {
                        sonuc_matris[i][j] += matris1[i][k] * matris2[k][j];
                    }
                }
            }

            // Sonucu Ekrana Basma
            printf("\n--- CARPIM SONUCU MATRISI ---\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c2; j++)
                {
                    printf("%d\t", sonuc_matris[i][j]);
                }
                printf("\n");
            }
            printf("\n[Sistem]: Matris hesaplamasi basariyla tamamlandi.\n");
            break;
        }
        case 2:
        {
            printf("\n--- STRING HESAP MAKINESI ALGORITMASI ---\n");
            char ifade[100];
            int idx = 0;

            int sayilar[100];
            char islemler[100];
            int sayi_sayac = 0;
            int islem_sayac = 0;

            printf("Matematiksel ifadeyi girin (Bosluksuz, Orn: 2+3*5-4/2): ");
            scanf("%s", ifade);

            // --- 1. ADIM: PARSING (METNİ PARÇALAMA) ---
            while (ifade[idx] != '\0')
            {
                if (ifade[idx] >= '0' && ifade[idx] <= '9')
                {
                    int gecici_sayi = 0;
                    while (ifade[idx] >= '0' && ifade[idx] <= '9')
                    {
                        gecici_sayi = (gecici_sayi * 10) + (ifade[idx] - '0');
                        idx++;
                    }
                    sayilar[sayi_sayac] = gecici_sayi;
                    sayi_sayac++;
                }
                else if (ifade[idx] == '+' || ifade[idx] == '-' || ifade[idx] == '*' || ifade[idx] == '/')
                {
                    islemler[islem_sayac] = ifade[idx];
                    islem_sayac++;
                    idx++;
                }
                else
                {
                    idx++;
                }
            }

            // --- 2. ADIM: 1. TUR (ÇARPMA VE BÖLME ERİTME) ---
            idx = 0;
            while (idx < islem_sayac)
            {
                if (islemler[idx] == '*' || islemler[idx] == '/')
                {
                    int sol_sayi = sayilar[idx];
                    int sag_sayi = sayilar[idx + 1];
                    int islem_sonucu = 0;

                    if (islemler[idx] == '*')
                    {
                        islem_sonucu = sol_sayi * sag_sayi;
                    }
                    else
                    {
                        if (sag_sayi == 0)
                        {
                            printf("[HATA]: Sifira bolme hatasi!\n");
                            islem_sonucu = 0;
                        }
                        else
                        {
                            islem_sonucu = sol_sayi / sag_sayi;
                        }
                    }

                    sayilar[idx] = islem_sonucu;

                    // Sayıları sola kaydırıp boşluğu kapatıyoruz (Senin yazdığın o meşhur döngü!)
                    for (int j = idx + 1; j < sayi_sayac - 1; j++)
                    {
                        sayilar[j] = sayilar[j + 1];
                    }
                    sayi_sayac--;

                    // İşlemleri sola kaydırıp boşluğu kapatıyoruz
                    for (int j = idx; j < islem_sayac - 1; j++)
                    {
                        islemler[j] = islemler[j + 1];
                    }
                    islem_sayac--;
                    // DİKKAT: idx++ yapmıyoruz, üst koltuktan kayan elemana bakacağız!
                }
                else
                {
                    idx++; // Çarpma/Bölme değilse normal ilerle
                }
            }

            // --- 3. ADIM: 2. TUR (TOPLAMA VE ÇIKARMA ERİTME) ---
            int nihai_sonuc = sayilar[0];
            for (int m = 0; m < islem_sayac; m++)
            {
                if (islemler[m] == '+')
                {
                    nihai_sonuc += sayilar[m + 1];
                }
                else if (islemler[m] == '-')
                {
                    nihai_sonuc -= sayilar[m + 1];
                }
            }

            printf("\nIslem Onceligine Gore Sonuc: %d\n", nihai_sonuc);
            printf("[Sistem]: String analizi basariyla tamamlandi.\n");
            break;
        }
        default:
            printf("\n[HATA]: Gecersiz bir secim yaptiniz! Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}