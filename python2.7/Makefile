include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/archive.mk

$(eval $(call add-variant,default))
%-default-stamp: bits = 64

summary := an interpreted, interactive, object-oriented, extensible programming language
license := Python License
license-file := LICENSE

name     := Python
pyver    := 2.7
version  := 2.7.3
home     := http://www.python.org/
archive  := $(name)-$(version).tar.bz2
download := http://www.python.org/ftp/python/$(version)/$(archive)

checksum-Python-2.7.3.tar.bz2 := \
     md5:c57477edd6d18bd9eeca2f21add73919 \
    sha1:842c4e2aff3f016feea3c6e992c7fa96e49c9aa0 \
  sha256:726457e11cb153adc3f428aaf1901fc561a374c30e5e7da6742c0742a338663c \
    size:11793433

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

configure-options += \
	--without-gcc \
	--enable-ipv6 \
	--enable-unicode=ucs4 \
	--with-dbmliborder=bdb:gdbm \
	--with-system-expat \
	--with-system-ffi \
	--enable-shared \


# We install libpython.X.Y.so.* in usual place (libdir),
# but runtime libraries go into the place where python
# looks them for:
install-default-stamp: make-vars += \
	LIBPL=$(prefix)/lib/python$(pyver)/config \
	DESTSHARED=$(prefix)/lib/python$(pyver)/lib-dynload

# Shorter name:
d := $(protodir.default)
scriptdir	=  usr/lib/python$(VER)
VER := $(pyver)

install-stamp: postinst-stamp
postinst-stamp: install-default-stamp
	mv $(d)/usr/lib/python$(VER)/site-packages \
		$(d)/usr/lib/python$(VER)/dist-packages
	: # remove files, which are not packaged
	rm -f $(d)/usr/bin/smtpd.py
	rm -rf $(d)/usr/lib/python$(VER)/ctypes/macholib
	rm -f $(d)/usr/lib/pkgconfig/python.pc
	rm -f $(d)/usr/bin/python2{,-config}
	rm -f $(d)/usr/share/man/man1/python2{,-config}.1
	: # Symlinks to /usr/bin for some tools
	ln -sf ../lib/python$(VER)/pdb.py $(d)/usr/bin/pdb$(VER)
	: # versioned install only
	rm -f $(d)/usr/bin/python-config
	mv $(d)/usr/bin/2to3 $(d)/usr/bin/2to3-$(VER)
	mv $(d)/usr/bin/pydoc $(d)/usr/bin/pydoc$(VER)
	: # Remove version information from the egg-info file
	mv $(d)/$(scriptdir)/lib-dynload/Python-$(VER)*.egg-info \
		$(d)/$(scriptdir)/lib-dynload/Python-$(VER).egg-info
	cp -p $(sourcedir)/Tools/i18n/pygettext.py $(d)/usr/bin/pygettext$(VER)

	touch $@

