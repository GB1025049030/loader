#include <stdio.h>
#include <unistd.h>

#include "util.h"

//*/
const char interp[] __attribute__((section(".interp"))) =
    "/data/data/io.twoyi/rootfs/system/bin/linker64";
/*/
const char interp[] __attribute__((section(".interp"))) =
    "/system/bin/linker64";
//*/

int main(void) {
    int num = getToastID();
    while (1) {
        if (num % 2 == 0) {
            num++;
        } else {
            num--;
        }
    }
    return 0;
}

void _start(void) {
    int ret;
    ret = main();
    _exit(ret);
}
