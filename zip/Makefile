package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/patch.mk


summary := a compression and file packaging/archive utility
license-file := LICENSE
license := Info-ZIP license

home     := http://www.info-zip.org/Zip.html
name     := zip
version  := 3.0
archive  := zip30.tar.gz
download := http://sourceforge.net/projects/infozip/files/Zip%203.x%20%28latest%29/$(version)/$(archive)


build-depends += \
	library/libbz2

CFLAGS += -Wall -I. -DUNIX

configure-%-stamp:
	cd $(builddir) && LDFLAGS="$(LDFLAGS)" sh unix/configure "$(CC)" "$(CFLAGS) $(CPPFLAGS)"
	touch $@

build-%-stamp:
	cd $(builddir) && $(MAKE) -f unix/Makefile generic
	touch $@

install-%-stamp:
	cd $(builddir) && $(MAKE) -f unix/Makefile install prefix=$(topdir)/$(protodir)/usr
	cd $(protodir)/usr && mkdir share && mv man share/
	touch $@


checksum-zip30.tar.gz := \
     md5:7b74551e63f8ee6aab6fbc86676c0d37 \
    sha1:c9f4099ecf2772b53c2dd4a8e508064ce015d182 \
  sha256:f0e8bb1f9b7eb0b01285495a2699df3a4b766784c1765a8f1aeedf63c0806369 \
    size:1118845

