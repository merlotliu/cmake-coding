#include <iostream>
#include <lumath/lumath.h>

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("usage : Add a b\n");
        return -1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d + %d = %d\n", a, b, add(a, b));
    return 0;
}