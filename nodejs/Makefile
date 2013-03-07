package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/64.mk
# Not autotools, but similar:
include /usr/share/cibs/rules/autotools.mk

# Must run from the current directory:
configure := ./configure

# Flock wrapper even does not return error on failure:
export LINK = $(CXX)

name         := nodejs
version      := 0.8.22
home         := http://nodejs.org
archive      := node-v$(version).tar.gz
download     := http://nodejs.org/dist/v$(version)/$(archive)
summary      := event-based server-side javascript engine
license      := BSD
license-file := $(sourcedir)/LICENSE

build-depends += \
	library/libv8 \
	library/c-ares \
	library/libev \
	library/zlib \
	library/openssl

# Node.js configure is a autotools lookalike confuserator:
configure-options := \
	--dest-os=solaris \
	--prefix=/usr \
	--without-npm \
	--shared-v8 \
	--shared-zlib \
	--shared-openssl \
	--no-ssl2


checksum-node-v0.8.20.tar.gz := \
     md5:dd8a977b8f38d6ccba25540fa8a8ffce \
    sha1:b780f58f0e3bc43d2380d4a935f2b45350783b37 \
  sha256:e4461bfded531f4880839829ab3bce5b824905d6e181876e3d0309a366bf57ee \
    size:12190186

checksum-node-v0.8.22.tar.gz := \
     md5:9f0e37afdc1e1005363940ada58c5f3d \
    sha1:1b7e65da70e2b3c2feacb1b13f673dfe43beb381 \
  sha256:3f61152cf5cd8fc1ab5c6c18101819841b947da79e1e44b51418c0ad2e6db8e8 \
    size:12200811

