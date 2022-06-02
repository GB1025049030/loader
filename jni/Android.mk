LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := loader_util
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_SRC_FILES := util.c
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := loader
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_SRC_FILES := loader.c
LOCAL_SHARED_LIBRARIES := loader_util
include $(BUILD_SHARED_LIBRARY)

# include $(CLEAR_VARS)
# LOCAL_MODULE := loader
# LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
# LOCAL_SRC_FILES := loader.c
# #LOCAL_FORCE_STATIC_EXECUTABLE=true
# LOCAL_SHARED_LIBRARIES := loader_util
# include $(BUILD_EXECUTABLE)
