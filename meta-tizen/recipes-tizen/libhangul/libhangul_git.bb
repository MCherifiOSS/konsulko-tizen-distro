require libhangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libhangul;tag=35a2329d67aeee91547184adc9e78384a85e73c5;nobranch=1"

BBCLASSEXTEND += " native "

