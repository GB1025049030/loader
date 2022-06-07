#ifndef PATH_UTILS_H
#define PATH_UTILS_H

#include <string.h>

#define APP_ROOTFS_PATH "/data/data/io.twoyi/rootfs"
#define ROOT_PATH "/"
#define LINKER_PATH_32 "/system/bin/linker"
#define LINKER_PATH_64 "/system/bin/linker64"

int start_with(const char *path, const char *start);
int end_with(const char *path, const char *end);
int get_len(const char *str, const char *str2);
int is_need_translate(const char *path);
int is_need_translate_interp(const char *path);
int get_translate_len(const char *path);
void translate(char **path);

#endif /* PATH_UTILS_H */
