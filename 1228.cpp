#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void geraVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;
    }
}

void troca(int v[], int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

// Complexidade de espaco: O(1)
// Complexidade de tempo: O(n^2)
int bubbleSort(int v[], int n) {
    int trocas = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                trocas++;
            }
        }
    }
    return trocas;
}

void bubbleSortOtimizado(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool houveTroca = false;
        for (int j = 0; j < (n - 1) - i; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                houveTroca = true;
            }
        }
        if (!houveTroca) return;
    }
}

// Espaço O(1) Tempo O(n^2)
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                troca(v, i, j);
            }
        }
    }
}

// espaço O(1) tempo O(n^2)
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = v[i], j = i - 1;
        while(j >= 0 && aux < v[j]) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int v1[n], v2[n], p1[n + 1], p2[n + 1];
        for (int i = 0; i < n; i++) {
            scanf("%d", &v1[i]);
            p1[v1[i]] = i;
        }
        /*for (int i = 1; i <= n; i++) {
            printf("%d: %d\n", i, p1[i]);
        }*/
        for (int i = 0; i < n; i++) {
            scanf("%d", &v2[i]);
            p2[i + 1] = p1[v2[i]];
        }
        /*for (int i = 1; i <= n; i++) {
            printf("%d: %d\n", i, p2[i]);
        }
        printf("\n");*/
        printf("%d\n", bubbleSort(p2, n + 1));
    }
    return 0;
}
