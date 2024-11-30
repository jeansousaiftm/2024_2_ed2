#include<stdio.h>

struct Competidor {

    int c, p, t;

    Competidor() {}

    Competidor(int _c) {
        c = _c;
        p = 0;
        t = 0;
    }

    void resolver(int _t, int _q) {
        p++;
        t += _t + ((_q - 1) * 20);
    }

    void imprimir() {
        printf("%d %d %d\n", c, p, t);
    }

    bool deveVirAntes(Competidor c2) {
        if (p > c2.p) {
            return true;
        } else if (p < c2.p) {
            return false;
        } else if (t < c2.t) {
            return true;
        } else if (t > c2.t) {
            return false;
        } else if (c < c2.c) {
            return true;
        } else {
            return false;
        }
    }

};

void swap(Competidor v[], int a, int b) {
    if (a == b) return;
    Competidor tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

int partition(Competidor v[], int s, int e) { // O(n)
    Competidor pivot = v[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (v[j].deveVirAntes(pivot)) {
            swap(v, ++i, j);
        }
    }
    swap(v, i + 1, e);
    return i + 1;
}

// O(n log n) caso médio, O(n^2) pior caso
// complexidade de espaço O(1)
void quickSort(Competidor v[], int s, int e) {
    if (s < e) {
        int p = partition(v, s, e);
        //imprimir(v, 8);
        //printf("%d %d %d\n", s, p, e);
        quickSort(v, s, p - 1);
        quickSort(v, p + 1, e);
    }

}

int main() {

    int c, n;
    scanf("%d %d", &c, &n);
    Competidor cps[c + 1];

    for (int i = 0; i <= c; i++) {
        cps[i] = Competidor(i);
    }

    for (int i = 0; i < n; i++) {
        int cp, t, p;
        scanf("%d %*c %d %d", &cp, &t, &p);
        cps[cp].resolver(t, p);
    }

    quickSort(cps, 1, c);

    for (int i = 1; i <= c; i++) {
        cps[i].imprimir();
    }


    return 0;
}
