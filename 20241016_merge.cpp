#include<stdio.h>

// Complexidade de tempo e espaço = O(n)
void merge(int v[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        tmp[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

// Complexidade de tempo O(n log n) e espaço O(n)
void mergeSort(int v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        //printf("%d %d %d\n", s, m, e);
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void imprimirVetorC(int v[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", v[i]);
    }
}

int main() {
    int n, x, cp = 0, ci = 0;
    scanf("%d", &n);
    int pares[n], impares[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares[cp++] = x;
        } else {
            impares[ci++] = x;
        }
    }
    mergeSort(pares, 0, cp - 1);
    mergeSort(impares, 0, ci - 1);
    imprimirVetor(pares, cp);
    imprimirVetorC(impares, ci);
    return 0;
}
