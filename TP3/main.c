/*****************************************************************************
 * TP3 - Programmation en Langage C
 * Tableaux, Pointeurs et Fonctions
 * 
 * Réalisé par : Manal RHONI AREF & Mariem TAOUIL (Génie Logiciel - Section 2, G8)
 * École : ENSIAS - Rabat
 * Année universitaire : 2026-2027
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =========================================================================
// EXERCICE 1 : Fonctions de base et logique de programmation
// =========================================================================

int A, B; // Variables globales

void MentionBac(float note) {
    if (note < 10.0) printf("Mention : Ajourne\n");
    else if (note < 12.0) printf("Mention : Passable\n");
    else if (note < 14.0) printf("Mention : Assez Bien\n");
    else if (note < 16.0) printf("Mention : Bien\n");
    else printf("Mention : Tres Bien\n");
}

void Lecture() {
    printf("Entrez la valeur de A : "); scanf("%d", &A);
    printf("Entrez la valeur de B : "); scanf("%d", &B);
}

int Somme(int a, int b) { return a + b; }
int Produit(int a, int b) { return a * b; }
int Min(int a, int b) { return (a < b) ? a : b; }
int Max(int a, int b) { return (a > b) ? a : b; }
void Carre(int *x) { *x = (*x) * (*x); }

void run_exo1() {
    printf("\n--- EXERCICE 1 ---\n");
    MentionBac(14.5);
    Lecture();
    printf("Somme(%d, %d) = %d\n", A, B, Somme(A, B));
    printf("Produit(%d, %d) = %d\n", A, B, Produit(A, B));
    printf("Min(%d, %d) = %d\n", A, B, Min(A, B));
    printf("Max(%d, %d) = %d\n", A, B, Max(A, B));
    
    int val = 5;
    Carre(&val);
    printf("Le carre de 5 (par passage par adresse) est : %d\n", val);
}


// =========================================================================
// EXERCICE 2 : Tableaux a une dimension et Pointeurs
// =========================================================================

void Lire1D(int *T, int N) {
    for(int i = 0; i < N; i++) {
        printf("Element [%d] : ", i);
        scanf("%d", T + i);
    }
}

void Afficher1D(int *T, int N) {
    printf("[ ");
    for(int i = 0; i < N; i++) printf("%d ", *(T + i));
    printf("]\n");
}

void Inverser(int *T, int N) {
    int temp;
    for(int i = 0; i < N / 2; i++) {
        temp = *(T + i);
        *(T + i) = *(T + N - 1 - i);
        *(T + N - 1 - i) = temp;
    }
}

void Trier(int *T, int N, int ordre) {
    int temp;
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if((ordre == 1 && *(T + i) > *(T + j)) || (ordre == 0 && *(T + i) < *(T + j))) {
                temp = *(T + i); *(T + i) = *(T + j); *(T + j) = temp;
            }
        }
    }
}

int est_premier(int n) {
    if (n <= 1) return 0;
    for(int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int Premier(int *T, int N) {
    for(int i = 0; i < N; i++) if(!est_premier(*(T + i))) return 0;
    return 1;
}

int Rechercher1D(int *T, int N, int val) {
    for(int i = 0; i < N; i++) if(*(T + i) == val) return i;
    return -1;
}

int Rechercher_Par_Dichotomie(int *T, int N, int val) {
    Trier(T, N, 1);
    int debut = 0, fin = N - 1, milieu;
    while(debut <= fin) {
        milieu = (debut + fin) / 2;
        if(*(T + milieu) == val) return milieu;
        else if(*(T + milieu) > val) fin = milieu - 1;
        else debut = milieu + 1;
    }
    return -1;
}

int* Concatener(int *T, int *N, int *T2, int M) {
    T = (int*) realloc(T, (*N + M) * sizeof(int));
    for(int i = 0; i < M; i++) *(T + *N + i) = *(T2 + i);
    *N += M;
    return T;
}

void run_exo2() {
    int N = 3;
    int *T = (int*) malloc(N * sizeof(int));
    printf("\n--- EXERCICE 2 (Demonstration rapide) ---\n");
    printf("Initialisation d'un tableau de %d elements:\n", N);
    Lire1D(T, N);
    printf("Tableau initial : "); Afficher1D(T, N);
    Inverser(T, N);
    printf("Tableau inverse : "); Afficher1D(T, N);
    Trier(T, N, 1);
    printf("Tableau trie (croissant) : "); Afficher1D(T, N);
    free(T);
}


// =========================================================================
// EXERCICE 3 : Gestion classique des chaines de caracteres (string.h)
// =========================================================================

typedef unsigned long size_t_custom;

char *mon_strcpy(char *dest, const char *src) {
    char *debut = dest;
    while (*src != '\0') { *dest = *src; dest++; src++; }
    *dest = '\0';
    return debut;
}

char *mon_strncpy(char *dest, const char *src, size_t_custom n) {
    char *debut = dest;
    size_t_custom i;
    for (i = 0; i < n && src[i] != '\0'; i++) dest[i] = src[i];
    for ( ; i < n; i++) dest[i] = '\0';
    return debut;
}

int mon_strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str1 == *str2) { str1++; str2++; }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

char *mon_strncat(char *dest, const char *src, size_t_custom n) {
    char *debut = dest;
    while (*dest != '\0') dest++;
    size_t_custom i;
    for (i = 0; i < n && src[i] != '\0'; i++) dest[i] = src[i];
    dest[i] = '\0';
    return debut;
}

void run_exo3() {
    char dest[50];
    char src[] = "ENSIAS";
    printf("\n--- EXERCICE 3 ---\n");
    printf("Copie de '%s' -> '%s'\n", src, mon_strcpy(dest, src));
    printf("Comparaison 'Apple' vs 'Zebra' : %d\n", mon_strcmp("Apple", "Zebra"));
}


// =========================================================================
// EXERCICE 4 : Manipulations avancees sur les chaines
// =========================================================================

int chaine_vers_entier(char *s) {
    int res = 0, i = 0;
    while (s[i] != '\0') { res = res * 10 + (s[i] - '0'); i++; }
    return res;
}

char* miroir(char *s) {
    int i = 0, j = strlen(s) - 1;
    char temp;
    while (i < j) { temp = s[i]; s[i] = s[j]; s[j] = temp; i++; j--; }
    return s;
}

char* cherche_remplace(char c, char r, char *s) {
    int i = 0;
    while (s[i] != '\0') { if (s[i] == c) s[i] = r; i++; }
    return s;
}

void run_exo4() {
    char num[] = "2026";
    char texte[] = "programmation";
    printf("\n--- EXERCICE 4 ---\n");
    printf("Chaine '%s' vers Entier : %d\n", num, chaine_vers_entier(num));
    printf("Remplacement de 'm' par 'M' dans 'programmation' : %s\n", cherche_remplace('m', 'M', texte));
    printf("Miroir du texte : %s\n", miroir(texte));
}


// =========================================================================
// EXERCICE 5 : Matrices et tableaux a deux dimensions
// =========================================================================
// Pour eviter les complications des VLA (Variable Length Arrays) dans le menu global,
// on utilise une taille fixe MAX pour la demonstration.
#define MAX 10

void Lire2D(int N, int M, int matrice[MAX][MAX]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            printf("Element [%d][%d] : ", i, j);
            scanf("%d", &matrice[i][j]);
        }
}

void Afficher2D(int N, int M, int matrice[MAX][MAX]) {
    for (int i = 0; i < N; i++) {
        printf("[ ");
        for (int j = 0; j < M; j++) printf("%d\t", matrice[i][j]);
        printf("]\n");
    }
}

void Somme2D(int N, int M, int A[MAX][MAX], int B[MAX][MAX], int Res[MAX][MAX]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) Res[i][j] = A[i][j] + B[i][j];
}

void run_exo5() {
    int N = 2, M = 2;
    int A[MAX][MAX];
    printf("\n--- EXERCICE 5 (Demonstration 2x2) ---\n");
    Lire2D(N, M, A);
    printf("Affichage de la matrice :\n");
    Afficher2D(N, M, A);
}


// =========================================================================
// MENU PRINCIPAL GLOBAL
// =========================================================================

int main() {
    int choix;
    do {
        printf("\n========== MENU TP3 : LANGAGE C ==========\n");
        printf("1. Lancer l'Exercice 1 (Fonctions de base)\n");
        printf("2. Lancer l'Exercice 2 (Tableaux 1D et Pointeurs)\n");
        printf("3. Lancer l'Exercice 3 (String.h)\n");
        printf("4. Lancer l'Exercice 4 (Chaines avancees)\n");
        printf("5. Lancer l'Exercice 5 (Matrices)\n");
        printf("0. Quitter le programme\n");
        printf("==========================================\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: run_exo1(); break;
            case 2: run_exo2(); break;
            case 3: run_exo3(); break;
            case 4: run_exo4(); break;
            case 5: run_exo5(); break;
            case 0: printf("Fin du TP3. Au revoir !\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while(choix != 0);

    return 0;
}
