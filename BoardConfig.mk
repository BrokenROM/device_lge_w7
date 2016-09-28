#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#


# Common specific options in device_w7.mk
-include device/lge/msm8226-common/BoardConfigCommon.mk

# Vendor Init
TARGET_UNIFIED_DEVICE := true
TARGET_INIT_VENDOR_LIB := libinit_w7
TARGET_OTA_ASSERT_DEVICE := w7,w7ds,w7n,w7nds
TARGET_RECOVERY_DEVICE_MODULES := libinit_w7
TARGET_RELEASETOOLS_EXTENSIONS := device/lge/w7

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := w7

# Kernel
BOARD_CUSTOM_BOOTIMG_MK := device/lge/w7/mkbootimg.mk
TARGET_KERNEL_CONFIG := stormysea_defconfig
###
TARGET_KERNEL_ARCH := arm
TARGET_KERNEL_SOURCE := kernel/lge/msm8226
KERNEL_TOOLCHAIN := $(ANDROID_BUILD_TOP)/prebuilts/gcc/$(HOST_OS)-x86/arm/arm-linux-androideabi-4.9-uber/bin
TARGET_KERNEL_CROSS_COMPILE_PREFIX := arm-linux-androideabi-

# Optimizations
CLANG_O3 := true
STRICT_ALIASING := false
KRAIT_TUNINGS := false
GRAPHITE_OPTS := false
ENABLE_GCCONLY := true

# Filesystem,
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_BOOTIMAGE_PARTITION_SIZE     := 16777216
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 16777216
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1950000000
BOARD_CACHEIMAGE_PARTITION_SIZE    := 884000000
BOARD_PERSISTIMAGE_PARTITION_SIZE := 33554432

# PDFIUM
TARGET_NEEDS_PDFIUM_BIGINT := true
