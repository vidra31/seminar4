
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
void onePhase(const char* name) {
    int a1, a2, k, i, j, kol, tmp;
    FILE* f, * f1, * f2, * g1, * g2;
    kol = 0;
    if ((f = fopen(name, "r")) == NULL)
        printf("\nIshodniy file ne mozhet bit' prochitan...");
    else {
        while (!feof(f)) {
            fscanf(f, "%d", &a1);
            kol++;
        }
        fclose(f);
    }
    f = fopen(name, "r");
    f1 = fopen("smsort_1.txt", "w");
    f2 = fopen("smsort_2.txt", "w");
    k = 1;
    if (!feof(f))
        fscanf(f, "%d", &a1);
    while (!feof(f)) {
        for (i = 0; i < k && !feof(f); i++) {
            fprintf(f1, "%d ", a1);
            fscanf(f, "%d", &a1);
        }
        for (j = 0; j < k && !feof(f); j++) {
            fprintf(f2, "%d ", a1);
            fscanf(f, "%d", &a1);
        }
    }
    fclose(f2);
    fclose(f1);
    fclose(f);

    f1 = fopen("smsort_1.txt", "r");
    f2 = fopen("smsort_2.txt", "r");
    g1 = fopen("g1.txt", "w");
    g2 = fopen("g2.txt", "w");
    int fl = 0;
    k = 1;
    while (k < kol + 4) {
        if (!feof(f1))
            fscanf(f1, "%d", &a1);
        if (!feof(f2))
            fscanf(f2, "%d", &a2);
        f = g1;
        while (!feof(f1) && !feof(f2)) {
            i = 0;
            j = 0;
            while (i < k && j < k && !feof(f1) && !feof(f2)) {
                if (a1 < a2) {
                    fprintf(f, "%d ", a1);
                    fscanf(f1, "%d", &a1);
                    i++;
                }
                else {
                    fprintf(f, "%d ", a2);
                    fscanf(f2, "%d", &a2);
                    j++;
                }
            }
            while (i < k && !feof(f1)) {
                fprintf(f, "%d ", a1);
                fscanf(f1, "%d", &a1);
                i++;
            }
            while (j < k && !feof(f2)) {
                fprintf(f, "%d ", a2);
                fscanf(f2, "%d", &a2);
                j++;
            }
            if (f == g1)
                f = g2;
            else
                f = g1;


        }
        while (!feof(f1)) {
            fprintf(f, "%d ", a1);
            fscanf(f1, "%d", &a1);
        }
        while (!feof(f2)) {
            fprintf(f, "%d ", a2);
            fscanf(f2, "%d", &a2);
        }
        fclose(f2);
        fclose(f1);
        fclose(g1);
        fclose(g2);

        k *= 2;
        if (fl == 0) {

            g1 = fopen("smsort_1.txt", "w");
            g2 = fopen("smsort_2.txt", "w");
            f1 = fopen("g1.txt", "r");
            f2 = fopen("g2.txt", "r");
            fl = 1;
        }
        else
        {
            f1 = fopen("smsort_1.txt", "r");
            f2 = fopen("smsort_2.txt", "r");
            g1 = fopen("g1.txt", "w");
            g2 = fopen("g2.txt", "w");
            fl = 0;
        }

    }

}