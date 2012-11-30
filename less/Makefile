include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/64.mk

summary := free open-source file pager
license := GPL v3+
license-file := COPYING

build-depends += \
	library/ncurses

configure-options += \
	--sysconfdir=/etc \
	--with-editor=/usr/bin/editor \


name     := less
home     := http://www.greenwoodsoftware.com/less/
version  := 456
archive  := $(name)-$(version).tar.gz
download := http://www.greenwoodsoftware.com/$(name)/$(archive)
checksum := \
     md5:5dd335f9d77646e047de05c64eb152b8 \
    sha1:10d60bc863fb3d0f9b9ea802d51ce6b8d2e4a2f8 \
  sha256:fa3ec8a2b790ea369cb1994571e909c3bb39426f375ab5803233b961ff004677 \
    size:310727
