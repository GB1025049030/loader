#include "path_utils.h"

#include "z_utils.h"

int start_with(const char *path, const char *start) {
    int len = strlen(start);
    if (len < 0) {
        return 0;
    }
    if (strncmp(path, start, len) == 0) {
        return 1;
    }
    return 0;
}

int end_with(const char *path, const char *end) {
    int len1 = strlen(path);
    int len2 = strlen(end);
    if (len2 < 0 || len2 > len1) {
        return 0;
    }
    if (strncmp(path + len1 - len2, end, len2) == 0) {
        return 1;
    }
    return 0;
}

int get_len(const char *str, const char *str2) {
    return strlen(str) + strlen(str2);
}

int is_need_translate(const char *path) {
    if (start_with(path, ROOT_PATH) && !start_with(path, APP_ROOTFS_PATH)) {
        return get_translate_len(path);
    }
    return 0;
}

int is_need_translate_interp(const char *path) {
    if (strcmp(path, LINKER_PATH_32) == 0 ||
        strcmp(path, LINKER_PATH_64) == 0) {
        return 1;
    }
    return 0;
}

int get_translate_len(const char *path) {
    return get_len(APP_ROOTFS_PATH, path);
}

void translate(char **path) {
    int len = get_len(APP_ROOTFS_PATH, *path);
    char buf[len];
    strcat(buf, APP_ROOTFS_PATH);
    strcat(buf, *path);
    strcpy(*path, buf);
}
