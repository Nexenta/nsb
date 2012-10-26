include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/32.mk
include /usr/share/cibs/rules/64.mk
include /usr/share/cibs/rules/copy.mk
# it is not autotools, but quite close to them.
include /usr/share/cibs/rules/autotools.mk


description := Open Source toolkit implementing the Secure Sockets Layer (SSL v2/v3) \
	and Transport Layer Security (TLS v1) protocols as well \
	as a full-strength general purpose cryptography library

license := OpenSSL
license-file := LICENSE

build-depends += \

name         := openssl
home         := http://www.openssl.org
version-base := 0.9.8
ips-version  := $(version-base).23
version      := $(version-base)x
archive      := $(name)-$(version).tar.gz
download     := $(home)/source/$(archive)
checksum := \
     md5:ee17e9bc805c8cc7d0afac3b0ef78eda \
    sha1:8c3be5160513c0af1e558d3f932390ecb16f59e9 \
  sha256:7ce0c7f2c451070b4497ea7ca6f23eba6cef1a56db2e86e433f65926a7bc7497 \
    size:3782486

configure = ./Configure
configure-env =

configure-options.32 = solaris-x86-gcc
configure-options.64 = solaris64-x86_64-gcc

pkcs11.32 = /usr/lib/libpkcs11.so.1
pkcs11.64 = /usr/lib/64/libpkcs11.so.1

# We've patched Configure to support this:
enginesdir.32 = /usr/lib/openssl-$(version-base)/engines
enginesdir.64 = /usr/lib/openssl-$(version-base)/engines/64

# Yeah...
libdir.32 = lib
libdir.64 = lib/$(mach64)

configure-options = \
	-DSOLARIS_OPENSSL \
	-DNO_WINDOWS_BRAINDEATH \
	--pk11-libname=$(pkcs11.$(bits)) \
	--prefix=/usr \
	--openssldir=/etc/openssl \
	--install_prefix=$(protodir.$(bits)) \
	--enginesdir=$(enginesdir.$(bits)) \
	--libdir=$(libdir.$(bits)) \
	$(configure-options.$(bits)) \
	no-ec \
	no-ecdh \
	no-ecdsa \
	no-rc3 \
	no-rc5 \
	no-mdc2 \
	no-idea \
	no-hw_4758_cca \
	no-hw_aep \
	no-hw_atalla \
	no-hw_chil \
	no-hw_gmp \
	no-hw_ncipher \
	no-hw_nuron \
	no-hw_padlock \
	no-hw_sureware \
	no-hw_ubsec \
	no-hw_cswift \
	threads \
	shared \
	no-static \

patch-stamp: add-source-stamp
add-source-stamp:
	cp engines/pkcs11/* $(sourcedir)/crypto/engine/
	cp engines/devcrypto/* $(sourcedir)/engines/
	touch $@


