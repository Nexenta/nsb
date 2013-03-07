package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/autoreconf.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/32.mk
include /usr/share/cibs/rules/64.mk

summary := C library for encoding, decoding and manipulating JSON data
license := MIT
license-file := $(sourcedir)/LICENSE

home     := http://www.digip.org/jansson/
name     := jansson
version  := 2.4
archive  := $(name)-$(version).tar.gz
download := $(home)/releases/$(archive)

# We use updates from git:
ips-version := $(version).99

checksum-jansson-2.4.tar.gz := \
     md5:c4629b89bf0432f3158c461e88fe0113 \
    sha1:994b84fd0b5d9050d01d250c7f90f038a3eeeed0 \
  sha256:1fcbd1ac3d8b610644acf86a5731d760bb228c9acbace20a2ad0f23baec79b41 \
    size:401597

