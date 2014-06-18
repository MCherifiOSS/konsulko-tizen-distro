DESCRIPTION = "Hardware identification and configuration data"
HOMEPAGE = "http://git.fedorahosted.org/git/hwdata.git"
SECTION = "System/Base"
LICENSE = "GPL-2.0+"

SRC_URI = ""

S = "${WORKDIR}/git"

inherit autotools-brokensep

BBCLASSEXTEND = ""
PROVIDES = ""

#PROVIDES by hwdata 
# the PROVIDES rules is ignore "pciutils-ids  "
PROVIDES += "pciutils-ids"
RPROVIDES_hwdata += "pciutils-ids"


#PROVIDES by hwdata-ivi 


RDEPENDS = ""
#RDEPENDS of hwdata-ivi (${PN}-ivi)
RDEPENDS_${PN}-ivi += "hwdata"


DEPENDS = ""

do_prep() {
 cd ${S}
 chmod -Rf a+rX,u+w,g-w,o-w ${S}
 #setup -q -n hwdata-0.260-1
 
 
}
do_patch_append() {
    bb.build.exec_func('do_prep', d)
}

do_configure() {
}

do_compile() {
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 CFLAGS="-O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables" ; export CFLAGS ; 
 CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
 FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
 LD_AS_NEEDED=1; export LD_AS_NEEDED ; 
 
 
   CFLAGS="${CFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CFLAGS ; 
   CXXFLAGS="${CXXFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables}" ; export CXXFLAGS ; 
   FFLAGS="${FFLAGS:--O2 -g -m64 -fmessage-length=0 -D_FORTIFY_SOURCE=2 -fstack-protector -funwind-tables -fasynchronous-unwind-tables -I%_fmoddir}" ; export FFLAGS ; 
   autotools_do_configure --build=${TARGET_SYS} --host=${HOST_SYS} \
         --target=noarch-tizen-linux \
         --program-prefix= \
         --prefix=${prefix} \
         --exec-prefix=${prefix} \
         --bindir=${prefix}/bin \
         --sbindir=${prefix}/sbin \
         --sysconfdir=${sysconfdir} \
         --datadir=${prefix}/share \
         --includedir=${prefix}/include \
         --libdir=${prefix}/lib \
         --libexecdir=${prefix}/libexec \
         --localstatedir=${localstatedir} \
         --sharedstatedir=${prefix}/com \
         --mandir=${mandir} \
         --infodir=${infodir}
 cp ${S}/packaging/hwdata.manifest .
 
 
 
 
}

do_install() {
 echo export RPM_BUILD_ROOT=${D}
 cd ${S}
 LANG=C
 export LANG
 unset DISPLAY
 rm -rf ${D} 
 mkdir -p ${D} 
 
 
   oe_runmake \
         DESTDIR=${D} \
         INSTALL_ROOT=${D} \
         BINDIR=${prefix}/bin \
   install  
   rm -f ${D}${infodir}/dir 
   find ${D} -regex ".*\.la$" | xargs rm -f -- 
   find ${D} -regex ".*\.a$" | xargs rm -f --
 /bin/mkdir -p ${D}${sysconfdir}/modprobe.d
 mv ${D}${prefix}/lib/modprobe.d/dist-blacklist.conf \
    ${D}${sysconfdir}/modprobe.d/blacklist.conf
 rm -rf ${D}${prefix}/lib
 install -m644 blacklist.conf ${D}/${sysconfdir}/modprobe.d
 install -m644 video.conf ${D}/${sysconfdir}/modprobe.d
 
 
 
}

PACKAGES += " hwdata-ivi "

hwdata_files = ""
hwdata_files += "hwdata.manifest"
hwdata_files += "${sysconfdir}/modprobe.d/blacklist.conf"
hwdata_files += "${prefix}/share/hwdata"
hwdata_files += "${prefix}/share/hwdata/*"

hwdata-ivi_files = ""
hwdata-ivi_files += "${sysconfdir}/modprobe.d/video.conf"

FILES_${PN} = "${hwdata_files}"
FILES_${PN}-ivi = "${hwdata-ivi_files}"

PKG_hwdata= "hwdata"
PKG_hwdata-ivi= "hwdata-ivi"

require hwdata-extraconf.inc
