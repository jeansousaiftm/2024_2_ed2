#include<stdio.h>

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Tempo: O(max(n, m)) onde m é o maior elemento do vetor
// Espaço: O(m)
void countingSort(int v[], int n, int m) {
    int tmp[m + 1];
    for (int i = 0; i < m + 1; i++) tmp[i] = 0;
    for (int i = 0; i < n; i++) {
        tmp[v[i]]++;
    }
    for (int i = 0, j = 0; i < m + 1; i++) {
        while(tmp[i] > 0) {
            v[j++] = i;
            tmp[i]--;
        }
    }
}

int main() {
    int v[] = { 1, 3, 5, 2, 4, 7, 8, 4, 1 };
    countingSort(v, 9, 8);
    imprimir(v, 9);
    return 0;
}
