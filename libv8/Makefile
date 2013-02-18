package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk


summary      := v8 JavaScript engine
home         := http://code.google.com/p/v8/
license      := BSD
license-file := LICENSE.v8
version      := 3.14.5.3
name         := libv8
libSoname    := libv8.so.$(version)
so-version   := $(version)

build-depends += \
	pkg:/developer/build/gyp

archive := v8-$(version).tar.bz2
download := http://mirror.yandex.ru/gentoo-distfiles/distfiles/$(archive)


v8arch.32 := ia32
v8arch.64 := x64
v8arch = $(v8arch.$(bits))

v8os := solaris
v8out = $(builddir)/out/$(v8arch).release/lib.target/$(libSoname)

GYPFLAGS = \
   -Dhost_arch=$(v8arch) \
   -DOS=$(v8os)

export GYPFLAGS

patch-stamp: gyp-stamp
gyp-stamp: unpack-stamp
	# Use system GYP
	gsed -i 's,build/gyp/,,g' $(sourcedir)/Makefile
	touch $@

configure-%-stamp: pre-configure-stamp
	touch $@

build-%-stamp: configure-%-stamp
	$(MAKE) -C $(builddir) \
		V=1 \
		CXX="$(CXX)" \
		LINK="$(CXX)" \
		library=shared \
		soname_version=$(so-version) \
		werror=no \
		$(v8arch).release
	touch $@

install-%-stamp: build-%-stamp
	mkdir -p $(protodir)/$(libdir)
	mkdir -p $(protodir)/usr/include
	cp $(v8out) $(protodir)/$(libdir)/
	cp $(builddir)/include/*.h $(protodir)/usr/include/
	touch $@

checksum-v8-3.14.5.3.tar.bz2 := \
     md5:b09a0b6038e46039647da0163a6337de \
    sha1:9b10a66b01e08ca6037c339bafe71a4d68474d26 \
  sha256:f91d851abd284589272f2b338c74e10f07ce667736e8e73cbd301172cb7f75a1 \
    size:10352249

