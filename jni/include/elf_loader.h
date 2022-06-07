#ifndef ELF_LOADER_H
#define ELF_LOADER_H

#include "path_utils.h"

void init_exec_elf(char *argv[]);
void exec_elf(const char *file, int argc, char *argv[]);

#endif /* ELF_LOADER_H */
