include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/noarch.mk

# This must be rewritten to support
# multiple pythons and SVN.

summary := Generate Your Projects
license := BSD
license-file := LICENSE
version := 0.1~svn1395
ips-version := 0.1.0.1395
name := gyp
home := http://code.google.com/p/gyp/

build-depends += \
	pkg:/runtime/python

archive := gyp_0.1~svn1395.orig.tar.gz
download := http://ftp.de.debian.org/debian/pool/main/g/gyp/$(archive)
checksum := \
     md5:512dd02cdba611a94909812a086e1105 \
    sha1:1a02f725ceb642186d6a62472226125610181175 \
  sha256:51f116574a8226bfab2946fe054ba0103ac5d470e8e9309cc1333b9c5d6088d3 \
    size:399588

configure-%-stamp: pre-configure-stamp
	touch $@

build-%-stamp: configure-%-stamp
	cd $(builddir) && python setup.py build
	touch $@

install-%-stamp: build-%-stamp
	cd $(builddir) && python2.6 setup.py install --root="$(protodir)" \
		--install-lib=/usr/lib/python2.6/vendor-packages
	gsed -i 's,#!.*,#!/usr/bin/python2.6,' $(protodir)/usr/bin/gyp
	touch $@


