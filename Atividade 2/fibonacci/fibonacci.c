#include <stdio.h>

int fibonacci(int n) {
    int a = 0, b = 1, c;
    if (n == 0) {
        return a;
    }
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char ** argv) {
    int n = 5;
    printf("Fibonacci sequence up to %d: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
