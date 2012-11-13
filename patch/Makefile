include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/64.mk

summary := Patch takes a patch file containing a difference listing produced \
	by the diff program and applies those differences to one \
	or more original files, producing patched versions.
license := GPL
license-file := COPYING

prefix := /usr/gnu

build-depends += \
	pkg:/compress/xz


name     := patch
home     := http://www.gnu.org/software/$(name)/
version  := 2.7
archive  := $(name)-$(version).tar.xz
download := http://ftp.gnu.org/gnu/$(name)/$(archive)
checksum := \
     md5:d443f9d9a7d1bf1715831883917699d9 \
    sha1:bcfbdaf75b77160c534571d696db5272b8e17207 \
  sha256:5c2c91fe41542962126f0be150aa4fa349485cf2edc0c7ea7dbc24cb817111ae \
    size:674544
