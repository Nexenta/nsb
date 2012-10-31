include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/64.mk


summary      := v8 JavaScript engine
home         := http://code.google.com/p/v8/
license      := BSD
license-file := LICENSE.v8
version      := 3.8.9.20
so-version   := $(version)
name         := libv8
libSoname    := $(name).so.$(so-version)

build-depends += \
	pkg:/developer/build/gyp

archive := libv8_$(version).orig.tar.gz
download := http://ftp.de.debian.org/debian/pool/main/libv/libv8/$(archive)
checksum := \
     md5:42e6ebd3a04d4532a5bbc2eaf3375f46 \
    sha1:0f4898f5209014db2cd561d34c9eaf44cf98bec2 \
  sha256:b03af91f1a111a959f133ca930497294b8faf134203a610998be2b5dd64253d1 \
    size:11373638


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
gyp-stamp:
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

