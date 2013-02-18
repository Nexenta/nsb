package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/64.mk

# man pages are not installed if building out of source tree:
include /usr/share/cibs/rules/copy.mk


summary := The ZeroMQ messaging library
license := LGPL
license-file := COPYING.LESSER

build-depends += \
	library/libpgm	\
	developer/pkg-config

#/usr/gcc/4.3/bin/gcc -m32 -luuid   -o test
#ld: warning: file libdladm.so.1: required by /usr/lib/libdlpi.so.1, not found
configure-env.32 += LDFLAGS="-L/lib"

configure-options += --with-system-pgm

home     := http://www.zeromq.org
name     := zeromq
version  := 3.2.2
archive  := $(name)-$(version).tar.gz
download := http://download.zeromq.org/$(archive)
checksum-zeromq-3.2.2.tar.gz := \
     md5:df68431d9300da84a1a5f9a2784e33de \
    sha1:0e8734c773b6a757b474c16fc3c517993ba47283 \
  sha256:2b4eeda60fe47a9fa0804d53d76f656665c5f84dab7e63a1d496d9430b554f99 \
    size:2067590

