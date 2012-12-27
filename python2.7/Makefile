include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk

summary := an interpreted, interactive, object-oriented, extensible programming language
license := Python License
license-file := LICENSE

build-depends += \
	compress/bzip2 \
	library/libbz2 \
	library/libdb-5.1 \
	library/libexpat \
	library/libffi \
	library/libgdbm \
	library/libsqlite3 \
	library/ncursesw \
	library/readline \
	library/tinfo \
	library/zlib \

name     := Python
pyver    := 2.7
version  := 2.7.3
home     := http://www.python.org/
archive  := $(name)-$(version).tar.bz2
download := http://www.python.org/ftp/python/$(version)/$(archive)

configure-options += \
	--without-gcc \
	--enable-ipv6 \
	--enable-unicode=ucs4 \
	--with-dbmliborder=bdb:gdbm \
	--with-system-expat \
	--with-system-ffi \
	--enable-shared \


# Ensure Makefile goes into /usr/lib/pythonX.Y/config
# (where runtime will look it for),
# not into /usr/lib/amd64/pythonX.Y/config:
install-%-stamp: make-vars += LIBPL=$(prefix)/lib/python$(pyver)/config

checksum-Python-2.7.3.tar.bz2 := \
     md5:c57477edd6d18bd9eeca2f21add73919 \
    sha1:842c4e2aff3f016feea3c6e992c7fa96e49c9aa0 \
  sha256:726457e11cb153adc3f428aaf1901fc561a374c30e5e7da6742c0742a338663c \
    size:11793433

