#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exercice_1() {
    printf("\n--- Exercice 1 ---\n");
    int N, i, j, min, max, sum, occ, temp, dejacompte;
    printf("N = ");
    if (scanf("%d", &N) != 1) return;
    int T1[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &T1[i]);
    }

    min = T1[0];
    max = T1[0];
    sum = 0;
    for(i = 0; i < N; i++) {
        if(T1[i] < min) min = T1[i];
        if(T1[i] > max) max = T1[i];
        sum += T1[i];
    }
    printf("Min: %d, Max: %d, Moyenne: %f\n", min, max, (float)sum / N);

    for(i = 0; i < N; i++) {
        dejacompte = 0;
        for(j = 0; j < i; j++) {
            if(T1[i] == T1[j]) {
                dejacompte = 1;
            }
        }
        if(dejacompte == 0) {
            occ = 0;
            for(j = 0; j < N; j++) {
                if(T1[i] == T1[j]) {
                    occ++;
                }
            }
            printf("Occurrences de %d : %d\n", T1[i], occ);
        }
    }

    for(i = 0; i < N / 2; i++) {
        temp = T1[i];
        T1[i] = T1[N - 1 - i];
        T1[N - 1 - i] = temp;
    }
    printf("Tableau inverse : ");
    for(i = 0; i < N; i++) {
        printf("%d ", T1[i]);
    }
    printf("\n");

    for(i = 0; i < N - 1; i++) {
        int min_idx = i;
        for(j = i + 1; j < N; j++) {
            if(T1[j] < T1[min_idx]) {
                min_idx = j;
            }
        }
        temp = T1[i];
        T1[i] = T1[min_idx];
        T1[min_idx] = temp;
    }
    printf("Tableau trie: ");
    for(i = 0; i < N; i++) {
        printf("%d ", T1[i]);
    }
    printf("\n");
}

void exercice_2() {
    printf("\n--- Exercice 2 ---\n");
    int N, i, j, trie = 1, tab_premier = 1;
    printf("N = ");
    if (scanf("%d", &N) != 1) return;
    int T[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &T[i]);
    }

    for(i = 0; i < N - 1; i++) {
        if(T[i] > T[i+1]) {
            trie = 0;
        }
    }
    if(trie == 1) printf("Le tableau est trie\n");
    else printf("Le tableau n'est pas trie\n");

    for(i = 0; i < N; i++) {
        int premier = 1;
        if(T[i] <= 1) premier = 0;
        for(j = 2; j * j <= T[i]; j++) {
            if(T[i] % j == 0) premier = 0;
        }
        if(premier == 0) tab_premier = 0;
    }
    if(tab_premier == 1) printf("Le tableau est premier\n");
    else printf("Le tableau n'est pas premier\n");
}

void exercice_3() {
    printf("\n--- Exercice 3 ---\n");
    int N1, i, j, k, sum_N, sum_M;
    printf("N1 = ");
    if (scanf("%d", &N1) != 1) return;
    int T1[N1];
    for(i = 0; i < N1; i++) {
        scanf("%d", &T1[i]);
    }

    for(i = 0; i < N1; i++) {
        for(j = i + 1; j < N1; j++) {
            sum_N = 0;
            for(k = 1; k < T1[i]; k++) {
                if(T1[i] % k == 0) sum_N += k;
            }
            sum_M = 0;
            for(k = 1; k < T1[j]; k++) {
                if(T1[j] % k == 0) sum_M += k;
            }
            if(sum_N == T1[j] && sum_M == T1[i]) {
                printf("(%d, %d)\n", T1[i], T1[j]);
            }
        }
    }
}

void exercice_4() {
    printf("\n--- Exercice 4 ---\n");
    int N1, N2;
    printf("Entrer la taille de la 1ere chaine : ");
    if (scanf("%d", &N1) != 1) return;
    printf("Entrer la taille de la 2eme chaine : ");
    if (scanf("%d", &N2) != 1) return;
    
    // Clear input buffer
    while (getchar() != '\n');

    char S1[N1 + N2 + 1], S2[N2 + 1], S3[N1 + 1];

    printf("S1: ");
    fgets(S1, sizeof(S1), stdin);
    S1[strcspn(S1, "\n")] = 0; // Remove trailing newline

    printf("S2: ");
    fgets(S2, sizeof(S2), stdin);
    S2[strcspn(S2, "\n")] = 0;

    if(strcmp(S1, S2) == 0) printf("Egales\n");
    else if(strcmp(S1, S2) > 0) printf("S1 > S2\n");
    else printf("S1 < S2\n");

    if(strstr(S1, S2) != NULL) printf("S2 est une sous-chaine de S1\n");
    else printf("S2 n'est pas une sous-chaine de S1\n");

    strcpy(S3, S1);
    printf("S3: %s\n", S3);

    strcat(S1, S2);
    printf("S1+S2: %s\n", S1);
}

void exercice_5_1() {
    printf("\n--- Exercice 5 (Question 1) ---\n");
    int N, i, j, x;
    printf("N = ");
    if (scanf("%d", &N) != 1) return;
    int T[N];
    for(i = 0; i < N; i++) {
        printf("Entrer T[%d]= ", i+1);
        scanf("%d", &T[i]);
    }
    printf("x = ");
    scanf("%d", &x);

    printf("Ce nombre %d est apparu dans : \n", x);
    for(i = 0; i < N; i++) {
        if(T[i] == x) {
            printf("\tPosition: %d\n", i);
        }
    }

    for(i = 0; i < N; i++) {
        if(T[i] == x) {
            for(j = i; j < N - 1; j++) {
                T[j] = T[j+1];
            }
            N--;
            i--;
        }
    }

    printf("Le tableau apres suppression de %d est: ", x);
    for(i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void exercice_5_2() {
    printf("\n--- Exercice 5 (Question 2) ---\n");
    int N, i, j, x;
    printf("N = ");
    if (scanf("%d", &N) != 1) return;
    int T[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &T[i]);
    }
    printf("x = ");
    scanf("%d", &x);

    for(i = 0; i < N; i++) {
        if(T[i] == x) {
            printf("Position: %d\n", i);
        }
        if(T[i] > x) break;
    }

    for(i = 0; i < N; i++) {
        if(T[i] == x) {
            for(j = i; j < N - 1; j++) {
                T[j] = T[j+1];
            }
            N--;
            i--;
        }
        if(T[i] > x) break;
    }

    for(i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void exercice_6() {
    printf("\n--- Exercice 6 ---\n");
    int N1, N2, i = 0, j = 0, k = 0;
    printf("N1 = ");
    if (scanf("%d", &N1) != 1) return;
    int T1[N1];
    for(int n = 0; n < N1; n++) {
        scanf("%d", &T1[n]);
    }

    printf("N2 = ");
    if (scanf("%d", &N2) != 1) return;
    int T2[N2];
    for(int n = 0; n < N2; n++) {
        scanf("%d", &T2[n]);
    }

    int T3[N1 + N2];
    while(i < N1 && j < N2) {
        if(T1[i] < T2[j]) {
            T3[k] = T1[i];
            i++;
        } else {
            T3[k] = T2[j];
            j++;
        }
        k++;
    }

    while(i < N1) {
        T3[k] = T1[i];
        i++;
        k++;
    }

    while(j < N2) {
        T3[k] = T2[j];
        j++;
        k++;
    }

    for(i = 0; i < N1 + N2; i++) {
        printf("%d ", T3[i]);
    }
    printf("\n");
}

void exercice_7() {
    printf("\n--- Exercice 7 ---\n");
    int N, i, j, k;
    printf("N = ");
    if (scanf("%d", &N) != 1) return;
    int T1[N];
    for(i = 0; i < N; i++) {
        scanf("%d", &T1[i]);
    }

    for(i = 0; i < N; i++) {
        for(j = i + 1; j < N; j++) {
            if(T1[i] == T1[j]) {
                for(k = j; k < N - 1; k++) {
                    T1[k] = T1[k+1];
                }
                N--;
                j--;
            }
        }
    }

    for(i = 0; i < N; i++) {
        printf("%d ", T1[i]);
    }
    printf("\n");
}

int main() {
    int choix;
    do {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Exercice 1\n");
        printf("2. Exercice 2\n");
        printf("3. Exercice 3\n");
        printf("4. Exercice 4\n");
        printf("5. Exercice 5 (Question 1)\n");
        printf("6. Exercice 5 (Question 2)\n");
        printf("7. Exercice 6\n");
        printf("8. Exercice 7\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) break;

        switch(choix) {
            case 1: exercice_1(); break;
            case 2: exercice_2(); break;
            case 3: exercice_3(); break;
            case 4: exercice_4(); break;
            case 5: exercice_5_1(); break;
            case 6: exercice_5_2(); break;
            case 7: exercice_6(); break;
            case 8: exercice_7(); break;
            case 0: printf("Fin du programme.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
