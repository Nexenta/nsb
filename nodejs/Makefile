include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/copy.mk
include /usr/share/cibs/rules/64.mk
# Not autotools, but similar:
include /usr/share/cibs/rules/autotools.mk

# Must run from the current directory:
configure := ./configure

# Flock wrapper even does not return erro on failure:
export LINK = $(CXX)

name := nodejs
version := 0.8.14
home := http://nodejs.org
archive := node-v$(version).tar.gz
download := http://nodejs.org/dist/v$(version)/$(archive)
checksum := \
     md5:284fd2c7578064c339d9cf6a3a475ac7 \
    sha1:47a1186004f6ce5e25a8555429d72b15519bc7f1 \
  sha256:e5ce2aadb4df3ea4ca7a021106ffe09d286474476454038e9ed0135eac18e6d0 \
    size:11861540

summary := event-based server-side javascript engine
license := BSD
license-file := LICENSE

build-depends += \
	library/libv8 \
	library/c-ares \
	library/libev \
	library/openssl-headers

# Node.js configure is a autotools lookalike confuserator:
configure-options := \
	--dest-os=solaris \
	--prefix=/usr \
	--without-npm \
	--shared-v8 \
	--shared-zlib \
	--shared-openssl \
	--no-ssl2

