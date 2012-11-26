include /usr/share/cibs/rules/32.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autoreconf.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/patch.mk

summary := library of containing many useful C routines for things such as trees, hashes, lists, and strings.
license := LGPL
license-file := COPYING.LIB

build-depends += \
	compress/xz \
	library/pcre \
	library/libffi \
	developer/pkg-config \
	developer/gnu-gettext \
	runtime/python

configure-env.32 = DTRACE="dtrace -32"
configure-env.64 = DTRACE="dtrace -64"

# glib requires >= i486
CFLAGS.32 += -march=i686

# Funny, dtrace is not supported on illumos/solaris.
configure-options += \
	 --with-pcre=system \
	 --disable-systemtap \
	 --disable-dtrace

# See https://www.illumos.org/issues/3263,
# https://www.illumos.org/issues/1587.
# Solved: https://github.com/illumos/illumos-gate/commit/4d1bea1
configure-options.32 = \
	--disable-largefile

configure-env += \
	MSGFMT="/usr/gnu/bin/msgfmt"

name     := glib
home     := http://www.gnu.org/software/$(name)/
release  := 2.32
version  := $(release).4
archive  := $(name)-$(version).tar.xz
download := http://ftp.gnome.org/pub/gnome/sources/$(name)/$(release)/$(archive)
checksum := \
     md5:bf84fefd9c1a5b5a7a38736f4ddd674a \
    sha1:5b6481cbb34f560e8ea78887200b6b7f5448dcb4 \
  sha256:a5d742a4fda22fb6975a8c0cfcd2499dd1c809b8afd4ef709bda4d11b167fae2 \
    size:6178556

