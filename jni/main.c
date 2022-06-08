#include "elf_loader.h"
#include "z_utils.h"

int main(int argc, char* argv[]) {
    init_exec_elf(argv);
    /*/ freeme
    if (argc < 2) z_errx(1, "no input file");
    exec_elf(argv[1], argc - 1, argv + 1);
    /*/
    if (argc > 0) {
        for (int i = 0; i < argc; i++) {
            int len = is_need_translate(argv[i]);
            if (len) {
                char* path = z_alloca(sizeof(char) * len);
                strcpy(path, APP_ROOTFS_PATH);
                strcat(path, argv[i]);
                argv[i] = path;
            }
        }
        if (start_with(argv[0], "./") && (end_with(argv[0], "/loader64") ||
                                          end_with(argv[0], "/libloader.so"))) {
            exec_elf(argv[1], argc - 1, argv + 1);
        } else {
            exec_elf(argv[0], argc, argv);
        }
    } else {
        z_errx(1, "no input file");
    }
    //*/
    return 0;
}
