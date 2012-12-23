include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk
include /usr/share/cibs/rules/copy.mk

summary := free and open source distributed version control system
license := GPL v2
license-file := COPYING

build-depends += \
	library/libexpat \
	library/zlib \
	developer/gnu-gettext \
	file/gnu-coreutils \

configure-options += \
	--without-openssl

name     := git
version  := 1.8.0.2
home     := http://git-scm.com/
base-download := http://git-core.googlecode.com/files/

archive  := $(name)-$(version).tar.gz
download-$(archive) := $(base-download)$(archive)

manpages := $(name)-manpages-$(version).tar.gz
download-$(manpages) := $(base-download)$(manpages)

archives := $(manpages)

checksum-git-manpages-1.8.0.2.tar.gz := \
     md5:ab83283a5b3c73ab711a9f02896ca12e \
    sha1:ce0673256ce90451269a82a2464eab060adbfec6 \
  sha256:b04f0e7277927e8fb91c1c1f7b951b6d2770cfa6a7b69145462214954751be98 \
    size:523757

checksum-git-1.8.0.2.tar.gz := \
     md5:1aca109d4a719fe5bc43d25927fbc7d9 \
    sha1:1e1640794596da40f35194c29a8cc4e41c6b4f6d \
  sha256:c06d5d29389e90583d16ec41d5be931593196f6842f9b14e910a0b5781c10e07 \
    size:4231410

make-vars = \
	V=1 \
	CC="$(CC)" \
	NO_OPENSSL=1 \
	INSTALL=/usr/bin/ginstall \
	prefix=/usr

build-%-stamp:
	$(MAKE) -C $(builddir) $(make-vars) $(make-jobs:%=-j%)
	touch $@

install-%-stamp:
	$(MAKE) -C $(builddir) $(make-vars) $(make-jobs:%=-j%) install DESTDIR="$(protodir)"
	touch $@
