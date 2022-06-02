#include <stdio.h>

// #include "util.h"

const char interp[] __attribute__((section(".interp"))) =
    "/data/data/io.twoyi/rootfs/system/bin/linker64";

int main() {
    // printf("LOADER : Start\n");
    int num = 0;
    while (1) {
        // printf("LOADER : Working!\n");
        if (num % 2 == 0) {
            num++;
        } else {
            num--;
        }
        //  toast();
    }
    // printf("LOADER : End\n");
    return 0;
}
