LOCAL_PATH       :=  $(call my-dir)
include              $(CLEAR_VARS)
LOCAL_MODULE     :=  loader
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_SRC_FILES  :=  loader.c
#LOCAL_FORCE_STATIC_EXECUTABLE=true
#include $(BUILD_EXECUTABLE)
include              $(BUILD_SHARED_LIBRARY)
