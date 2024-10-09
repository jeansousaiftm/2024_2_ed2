#include<stdio.h>

int fibonacci(int x) {
    if (x == 1 || x == 2) {
        return 1;
    } else {
        return fibonacci(x - 1) + fibonacci(x - 2);
    }
}

int fatorial(int x) {
    if (x == 1) {
        return 1;
    } else {
        return x * fatorial(x - 1);
    }
}

int main() {
    printf("%d\n", fibonacci(5));
    return 0;
}
