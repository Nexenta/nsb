include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk


summary      := v8 JavaScript engine
home         := http://code.google.com/p/v8/
license      := BSD
license-file := LICENSE.v8
version      := 3.14.5
so-version   := $(version)
name         := libv8
libSoname    := $(name).so.$(so-version)

build-depends += \
	pkg:/developer/build/gyp

archive := v8-$(version).tar.bz2
download := http://mirror.yandex.ru/gentoo-distfiles/distfiles/$(archive)
checksum := \
     md5:be8f17f7cfc2885ecc67ef6b367f2c0d \
    sha1:92ca5dd0872fcf06273a8994375ec1f4d5310879 \
  sha256:361ad3b63dc7c9d0943b72b1be592a8135e4ddb0e416b9bcf02b4d2df514fca7 \
    size:10351058


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
	touch $@

