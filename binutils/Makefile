include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/32.mk

summary := GNU collection of binary tools, including the GNU linker and the GNU assembler
license := GPL v3+
license-file := COPYING3

prefix = /usr/gnu

PATH := /usr/perl5/bin:$(PATH)

build-depends += \
	flex \
	library/zlib

name     := binutils
home     := http://www.gnu.org/software/$(name)/
version  := 2.22
archive  := $(name)-$(version).tar.bz2
download := http://ftp.gnu.org/gnu/$(name)/$(archive)
checksum := \
     md5:ee0f10756c84979622b992a4a61ea3f5 \
    sha1:65b304a0b9a53a686ce50a01173d1f40f8efe404 \
  sha256:6c7af8ed1c8cf9b4b9d6e6fe09a3e1d3d479fe63984ba8b9b26bf356b6313ca9 \
    size:19973532
