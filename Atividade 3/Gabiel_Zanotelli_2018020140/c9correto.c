 #include <stdlib.h>

void f(void) {

    int* x = malloc(11 * sizeof(int));
    x[10] = 0; 
    free(x);
}

int main(void) {

    f();

    return 0;
}


