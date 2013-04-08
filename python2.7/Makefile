include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/archive.mk

movefiles := /usr/share/cibs/scripts/movefiles

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

PVER := python$(pyver)

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
	text/help2man \


configure-options += \
	--without-gcc \
	--enable-ipv6 \
	--enable-unicode=ucs4 \
	--with-dbmliborder=bdb:gdbm \
	--with-system-expat \
	--with-system-ffi \
	--enable-shared \

MIN_MODS := $(shell awk '/^  / && $$2 == "module" { print $$1 }' \
		debian/PVER-minimal.README.Debian.in)
MIN_EXTS := $(shell awk '/^  / && $$2 ~ /^extension/ { print $$1 }' \
		debian/PVER-minimal.README.Debian.in)
MIN_BUILTINS := $(shell awk '/^  / && $$2 == "builtin" { print $$1 }' \
		debian/PVER-minimal.README.Debian.in)
MIN_PACKAGES := $(shell awk '/^  / && $$2 == "package" { print $$1 }' \
		debian/PVER-minimal.README.Debian.in)
MIN_ENCODINGS := $(foreach i, \
			$(filter-out \
			  big5% bz2% cp932.py cp949.py cp950.py euc_% \
			  gb% iso2022% johab.py shift_jis% , \
			  $(shell cd $(sourcedir)/Lib/encodings && echo *.py)), \
			encodings/$(i)) \
		 codecs.py stringprep.py

# We install libpython.X.Y.so.* in usual place (libdir),
# but runtime libraries go into the place where python
# looks them for:
install-default-stamp: make-vars += \
	LIBPL=$(prefix)/lib/python$(pyver)/config \
	DESTSHARED=$(prefix)/lib/python$(pyver)/lib-dynload

# Shorter name:
d := $(protodir.default)
scriptdir = usr/lib/python$(VER)
VER := $(pyver)
d_min := work/proto/python2.7-minimal

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
	gfind $(d) -name 'wininst*.exe' | gxargs -r rm -f

	: # Symlinks to /usr/bin for some tools
	ln -sf ../lib/python$(VER)/pdb.py $(d)/usr/bin/pdb$(VER)
	: # versioned install only
	rm -f $(d)/usr/bin/python-config
	mv $(d)/usr/bin/pydoc $(d)/usr/bin/pydoc$(VER)
	: # Remove version information from the egg-info file
	mv $(d)/$(scriptdir)/lib-dynload/Python-$(VER)*.egg-info \
		$(d)/$(scriptdir)/lib-dynload/Python-$(VER).egg-info
	cp -p $(sourcedir)/Tools/i18n/pygettext.py $(d)/usr/bin/pygettext$(VER)

	mv $(d)/usr/bin/2to3 $(d)/usr/bin/2to3-$(VER)
	PYTHONPATH=$(d)/$(scriptdir) \
	help2man --no-info --version-string=$(VER) --no-discard-stderr \
	  --name 'Python2 to Python3 converter' \
	$(d)/usr/bin/2to3-$(VER) \
	> $(d)/usr/share/man/man1/2to3-$(VER).1

	: # install minimal set:
	mkdir -p $(d_min)
	cd $(d_min) && mkdir -p \
		etc/$(PVER) \
		usr/bin \
		usr/include/$(PVER) \
		usr/share/man/man1 \
		$(scriptdir)/lib-dynload \
		$(scriptdir)/config
	$(movefiles) -s $(d) -d$(d_min) \
		usr/bin/python$(VER) \
		usr/share/man/man1/python$(VER).1 \
		$(foreach i,$(MIN_MODS),$(scriptdir)/$(i).py) \
		$(foreach i,$(MIN_PACKAGES),$(scriptdir)/$(i)) \
		$(foreach i,$(MIN_ENCODINGS),$(scriptdir)/$(i)) \
		$(scriptdir)/config/Makefile \
		usr/include/$(PVER)/pyconfig.h \
		$(scriptdir)/site.py \
		$(shell cd $(d); for i in $(MIN_EXTS); do \
			test -e $(scriptdir)/lib-dynload/$$i.so \
			  && echo $(scriptdir)/lib-dynload/$$i.so; \
		  done; true)

	touch $@

