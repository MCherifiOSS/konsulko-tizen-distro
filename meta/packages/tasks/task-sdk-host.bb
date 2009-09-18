#
# Copyright (C) 2007 OpenedHand Ltd
#

DESCRIPTION = "Host packages for the standalone SDK or external toolchain"
PR = "r8"
LICENSE = "MIT"
ALLOW_EMPTY = "1"

inherit nativesdk

PACKAGES = "${PN}"

RDEPENDS_${PN} = "\
    binutils-cross-canadian \
    gdb-cross-canadian \
    gcc-cross-canadian \
    pkgconfig-nativesdk \
    qemu-nativesdk \
    qemu-helper-nativesdk \
    opkg-nativesdk \
    "

RDEPENDS_${PN}_darwin8 = "\
    odcctools-cross-canadian \
    llvm-cross-canadian \
    pkgconfig-nativesdk \
    opkg-nativesdk \
    libtool-nativesdk \
    "
