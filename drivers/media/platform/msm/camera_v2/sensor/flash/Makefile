# SPDX-License-Identifier: GPL-2.0-only
ccflags-y += -I $(srctree)/drivers/media/platform/msm/camera_v2/sensor/cci
ccflags-y += -I $(srctree)/drivers/media/platform/msm/camera_v2
ccflags-y += -I $(srctree)/drivers/media/platform/msm/camera_v2/common
ccflags-y += -I $(srctree)/drivers/media/platform/msm/camera_v2/sensor/io
obj-$(CONFIG_MSMB_CAMERA) += msm_flash.o
# FIH: placeholder flash for cameras without one (DT qcom,camera-led-flash)
obj-$(CONFIG_MSMB_CAMERA) += dummy_flash.o
obj-$(CONFIG_MSMB_CAMERA) += qm215_gpio_flash.o
