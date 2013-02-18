package ?= ips
include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/64.mk

summary := manage compile and link flags for libraries
license := GPL v2+
license-file := COPYING

build-depends += \
	pkg:/library/glib2 \
	pkg:/library/popt

configure-options += \
	--with-installed-popt \
	--disable-shared \
	--with-pc-path=/usr/local/lib/pkgconfig:/usr/local/share/pkgconfig:/usr/lib/64/pkgconfig:/usr/lib/pkgconfig:/usr/share/pkgconfig:/usr/gnu/lib/64/pkgconfig:/usr/gnu/lib/pkgconfig \
	--with-system-library-path=/usr/lib:/usr/gnu/lib:/usr/lib/amd64:/usr/gnu/lib/amd64:/usr/lib/64:/usr/gnu/lib/64


# To bootstrap without pkg-config installed:
configure-env += \
	GLIB_LIBS="-lglib-2.0" \
	GLIB_CFLAGS="-I/usr/include/glib-2.0 -I/usr/lib/64/glib-2.0/include -I/usr/lib/glib-2.0/include"

name     := pkg-config
home     := http://www.freedesktop.org/wiki/Software/pkg-config
version  := 0.27.1
archive  := $(name)-$(version).tar.gz
download := http://pkgconfig.freedesktop.org/releases/$(archive)
# Insert this into Makefile:
checksum := \
     md5:5392b4e3372879c5bf856173b418d6a2 \
    sha1:08249417a51c0a7a940e4276105b142b77e576b5 \
  sha256:4f63d0df3035101b12949250da5231af49e3c3afcd8fb18554fa7c3cb92d8c17 \
    size:1908265
