#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void geraVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n;
    }
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void swap(int v[], int a, int b) {
    if (a == b) return;
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

int partition(int v[], int s, int e) { // O(n)
    int pivot = v[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (v[j] < pivot) {
            swap(v, ++i, j);
        }
    }
    swap(v, i + 1, e);
    return i + 1;
}

// O(n log n) caso médio, O(n^2) pior caso
// complexidade de espaço O(1)
void quickSort(int v[], int s, int e) {
    if (s < e) {
        int p = partition(v, s, e);
        //imprimir(v, 8);
        //printf("%d %d %d\n", s, p, e);
        quickSort(v, s, p - 1);
        quickSort(v, p + 1, e);
    }

}


int main() {
    srand(time(NULL));
    int n = 200000;
    int v[n];
    geraVetor(v, n);
    quickSort(v, 0, n - 1);
    //imprimir(v, n);
    return 0;
}
