LOCAL_PATH := $(call my-dir)

ifeq "$(APP_ABI)" ""
    APP_ABI := arm64-v8a
endif

# make ARCH=i386 SMALL=1 DEBUG=1

ARCH = $(APP_ABI)
STDLIB = 1
SMALL = 0
DEBUG = 0

ARCHS32 := i386 armeabi-v7a
ARCHS64 := amd64 arm64-v8a
ARCHS := $(ARCHS32) $(ARCHS64)

CFLAGS_i386 = -m32

CFLAGS += -pipe -Wall -Wextra -fPIC -fno-ident -fno-stack-protector -U _FORTIFY_SOURCE
CFLAGS += -DSTDLIB=$(STDLIB)
ifeq "$(STDLIB)" "0"
#LDFLAGS += -nostartfiles -nodefaultlibs -nostdlib
LDFLAGS += -nostartfiles -e z_start
endif
LDFLAGS += -pie -Wl,-Bsymbolic,--no-undefined,--build-id=none
# TARGET := loader foreign_dlopen_demo

ifeq "$(filter $(ARCH),$(ARCHS))" ""
  $(error ARCH='$(ARCH)' is not supported)
endif

ifeq "$(filter $(ARCH),$(ARCHS32))" "$(ARCH)"
  CFLAGS += -DELFCLASS=ELFCLASS32
else
  CFLAGS += -DELFCLASS=ELFCLASS64
endif

CFLAGS += $(CFLAGS_$(ARCH))
LDFLAGS += $(CFLAGS_$(ARCH))

ifeq "$(DEBUG)" "1"
  CFLAGS += -O0 -g
else
  CFLAGS += -fvisibility=hidden
  # Disable unwind info to make prog smaller.
  CFLAGS += -Os -fno-asynchronous-unwind-tables -fno-unwind-tables
  LDFLAGS += -s
endif

ASFLAGS = $(CFLAGS)

SRC_FILES := loader.c z_err.c z_printf.c z_syscalls.c z_utils.c foreign_dlopen.c
SRC_FILES += $(patsubst $(LOCAL_PATH)/%.S,%.S, $(wildcard $(LOCAL_PATH)/$(ARCH)/*.S))

ifeq "$(SMALL)" "1"
  SRC_FILES := $(filter-out z_printf.%,$(SRC_FILES))
  SRC_FILES := $(filter-out z_err.%,$(SRC_FILES))
  CFLAGS += -DZ_SMALL
endif

LOADER_SRC_FILES := main.c $(SRC_FILES)
