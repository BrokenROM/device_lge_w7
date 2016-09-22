# Inherit some common Broken stuff.
$(call inherit-product, vendor/broken/config/common_full_phone.mk)
# Inherit system props w7 device
$(call inherit-product, device/lge/w7/system_prop.mk)

# Boot animation
TARGET_SCREEN_WIDTH := 540
TARGET_SCREEN_HEIGHT := 960

# Release name
PRODUCT_RELEASE_NAME := LG L90
PRODUCT_NAME := broken_w7
PRODUCT_MODEL := w7
PRODUCT_MANUFACTURER := LGE

# Broken Device Maintainers
PRODUCT_BUILD_PROP_OVERRIDES += \
	DEVICE_MAINTAINERS="Moshe Barash (mosimchah)"

$(call inherit-product, device/lge/w7/full_w7.mk)
