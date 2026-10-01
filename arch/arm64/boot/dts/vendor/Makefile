vendor := $(srctree)/$(src)

# Nokia/FIH boards share qcom,board-id values with the Qualcomm reference
# boards (CTL is <8 0>, like sdm636-mtp) and ABL only tells them apart by
# fih,hw-id, so don't append the reference dtbs to a Nokia kernel.
ifneq ($(CONFIG_ARCH_NOKIA_SDM660),y)
ifneq "$(wildcard $(vendor)/qcom)" ""
	subdir-y += qcom
endif
endif

ifneq "$(wildcard $(vendor)/fih)" ""
	subdir-y += fih
endif
