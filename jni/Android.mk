LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := loader
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_SRC_FILES := $(LOADER_SRC_FILES)
LOCAL_CFLAGS := $(CFLAGS)
LOCAL_LDFLAGS := $(LDFLAGS)
LOCAL_ASFLAGS := $(ASFLAGS)
include $(BUILD_EXECUTABLE)
