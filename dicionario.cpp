#include<stdio.h>
#include<string.h>

// Complexidade de tempo e espaço = O(n)
void merge(char v[][101], int s, int m, int e) {
    char tmp[(e - s) + 1][101];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        strcpy(tmp[k++], (strcmp(v[i], v[j]) < 0) ? v[i++] : v[j++]);
    }
    while (i <= m) {
        strcpy(tmp[k++], v[i++]);
    }
    while (j <= e) {
        strcpy(tmp[k++], v[j++]);
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        strcpy(v[i], tmp[k]);
    }
}

// Complexidade de tempo O(n log n) e espaço O(n)
void mergeSort(char v[][101], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        //printf("%d %d %d\n", s, m, e);
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

bool buscaBinaria(char v[][101], int n, char x[101]) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        int compara = strcmp(v[m], x);
        if (compara == 0) {
            return true;
        } else if (compara > 0) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return false;
}

int main() { // O(MAX(n log n, m log n))
    int n, m, q = 0;
    scanf("%d", &n);
    char dicionario[n][101];
    for (int i = 0; i < n; i++) {
        scanf("%s", dicionario[i]);
    }
    mergeSort(dicionario, 0, n - 1); // O(n log n * 100) = O (n log n)
    /*for (int i = 0; i < n; i++) {
        printf("%s\n", dicionario[i]);
    }*/
    scanf("%d", &m);
    char tmp[101];
    for (int i = 0; i < m; i++) { //O(m log n)
        scanf("%s", tmp);
        if (buscaBinaria(dicionario, n, tmp)) {
            q++;
        }
    }
    printf("%d\n", q);
    return 0;
}
