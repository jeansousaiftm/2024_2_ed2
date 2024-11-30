#include<stdio.h>
#include<string.h>

void countingSort(char v[], int n, int m) {
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

    char tmp1[1001], tmp2[1001];

    scanf("%s", tmp1);
    scanf("%s", tmp2);

    countingSort(tmp1, strlen(tmp1), 255);
    countingSort(tmp2, strlen(tmp2), 255);

    printf("%s %s\n", tmp1, tmp2);

    if (strcmp(tmp1, tmp2) == 0) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}
