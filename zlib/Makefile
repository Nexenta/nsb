package ?= ips
include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/32.mk
include /usr/share/cibs/rules/64.mk
include /usr/share/cibs/rules/copy.mk

# Not autotools, but similar.
include /usr/share/cibs/rules/autotools.mk

summary := a library implementing the deflate compression method found in gzip and PKZIP
license := ZLib
license-file := zlib.license

build-depends += \

name     := zlib
home     := http://zlib.net
version  := 1.2.7
archive  := $(name)-$(version).tar.bz2
download := http://zlib.net/$(archive)
checksum := \
     md5:2ab442d169156f34c379c968f3f482dd \
    sha1:858818fe6d358ec682d54ac5e106a2dd62628e7f \
  sha256:49e2e9658dfb036900da6ea0267a737fa3c4eee6666776d378c79d52e9334934 \
    size:505085

# This is autotools look-alike confuserator
configure-options = \
	--shared \
	--prefix=/usr \
	--libdir=/usr/lib$(lib-suffix.$(bits))


# XXX zlib does not know about Sun ld.
# XXX zlib.map is not suitable for sun ld.
configure-env += \
	LDSHARED="$(CC) $(CFLAGS) -shared"
build-%-stamp: make-vars = LDSHARED="$(CC) $(CFLAGS) -shared -Wl,-h,libz.so.1,-M,$(CURDIR)/mapfile -L ."
