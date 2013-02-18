package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/64.mk


summary := C library that performs DNS requests and name resolves asynchronously
license := MIT

home     := http://c-ares.haxx.se
name     := c-ares
version  := 1.9.1
archive  := $(name)-$(version).tar.gz
download := $(home)/download/$(archive)
checksum := \
	sha1:fe41e47f300bfd587b7f552a141ad3bf85437b0f \
	sha256:023f28001f2f839645c8700187391a011198950c73ddd91510c7549d87373936 \
	md5:389db4917a3b58c4ce4ebfe961fd84c4 \
	size:782945

