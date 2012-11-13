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


name     := diffutils
home     := http://www.gnu.org/software/$(name)/
version  := 3.2
archive  := $(name)-$(version).tar.xz
download := http://ftp.gnu.org/gnu/$(name)/$(archive)
checksum := \
     md5:26ff64c332429c830c154be46b393382 \
    sha1:59b9742e96e2512d4d6f9af7964d71b6ea5a9ef0 \
  sha256:ab4fb75d0ef35f3c8c9a148cd3526ba6f4db71d10467a041eb45006436079149 \
    size:1148036
