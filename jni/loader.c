#include <stdio.h>

const char interp[] __attribute__((section(".interp"))) =
    "/system/bin/linker64";

int main() {
    printf("Hello Android!\n");
    return 0;
}
