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
so-version   := 1.0.0
version-base := 1.0.1
ips-version  := $(version-base).3
version      := $(version-base)c
archive      := $(name)-$(version).tar.gz
download     := $(home)/source/$(archive)
checksum := \
     md5:ae412727c8c15b67880aef7bd2999b2e \
    sha1:91b684de947cb021ac61b8c51027cc4b63d894ce \
  sha256:2a9eb3cd4e8b114eb9179c0d3884d61658e7d8e8bf4984798a5f5bd48e325ebe \
    size:4457113

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


