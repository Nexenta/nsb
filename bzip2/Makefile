include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/32.mk
include /usr/share/cibs/rules/64.mk
include /usr/share/cibs/rules/copy.mk

summary := high-quality block-sorting file compressor
license := Bzip2
license-file := LICENSE

build-depends += \

name     := bzip2
home     := http://www.bzip.org/
version  := 1.0.6
archive  := $(name)-$(version).tar.gz
download := http://www.bzip.org/$(version)/$(archive)
checksum := \
     md5:00b516f4704d4a7cb50a1d97e6e8e15b \
    sha1:3f89f861209ce81a6bab1fd1998c0ef311712002 \
  sha256:a2848f34fcd5d6cf47def00461fcb528a0484d8edef8208d6d2e2909dc61d9cd \
    size:782025

build-%-stamp:
	cd "$(builddir)" && $(MAKE) $(make-jobs:%=-j%) CC="$(CC)"
	touch $@

install-%-stamp:
	mkdir -p $(protodir)
	touch $@
