#include<stdio.h>

// comp. tempo O(n)
bool buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) return true;
    }
    return false;
}

// comp. tempo O(log n)
// comp. espaco O(1)
bool buscaBinaria(int v[], int n, int x) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (v[m] == x) {
            return true;
        } else if (v[m] > x) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return false;
}

int main() {

    return 0;
}
