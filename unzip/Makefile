package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/patch.mk


summary := De-archiver for .zip files
license-file := $(sourcedir)/LICENSE
license := Info-ZIP license

home     := http://www.info-zip.org/UnZip.html
name     := zip
version  := 6.0
archive  := unzip60.tar.gz
download := http://sourceforge.net/projects/infozip/files/UnZip%206.x%20%28latest%29/UnZip%206.0/$(archive)

checksum-unzip60.tar.gz := \
     md5:62b490407489521db863b523a7f86375 \
    sha1:abf7de8a4018a983590ed6f5cbd990d4740f8a22 \
  sha256:036d96991646d0449ed0aa952e4fbe21b476ce994abc276e49d30e686708bd37 \
    size:1376845


build-depends += \
	library/libbz2

CFLAGS += -Wall -I. -DUNIX

configure-%-stamp:
	touch $@

CPPFLAGS += -DACORN_FTYPE_NFS -DWILD_STOP_AT_DIR -DLARGE_FILE_SUPPORT \
 -DUNICODE_SUPPORT -DUNICODE_WCHAR -DUTF8_MAYBE_NATIVE -DNO_LCHMOD \
 -DDATE_FORMAT=DF_YMD -DUSE_BZIP2 -DIZ_HAVE_UXUIDGID -DNOMEMCPY

build-%-stamp:
	$(MAKE) -C $(builddir) \
		-f unix/Makefile D_USE_BZ2=-DUSE_BZIP2 L_BZ2=-lbz2 \
		CC="$(CC)" LF2="$(LDFLAGS)" \
		CF="$(CFLAGS) $(CPPFLAGS) -I." unzips
	touch $@

install-%-stamp:
	cd $(builddir) && $(MAKE) -f unix/Makefile install prefix=$(topdir)/$(protodir)/usr
	cd $(protodir)/usr && mkdir share && mv man share/
	gzip -r9 $(protodir)/usr/share/man
	touch $@

