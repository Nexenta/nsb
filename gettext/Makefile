include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/64.mk

summary := GNU Internationalization utilities
license := GPL v3+
license-file := COPYING

build-depends += \
	pkg:/library/libunistring \
	pkg:/developer/versioning/git \
	pkg:/library/ncurses \
	pkg:/library/libxml2

prefix = /usr/gnu

name     := gettext
home     := http://www.gnu.org/software/$(name)/
version  := 0.18.1.1
archive  := $(name)-$(version).tar.gz
download := http://ftp.gnu.org/gnu/$(name)/$(archive)
checksum := \
     md5:3dd55b952826d2b32f51308f2f91aa89 \
    sha1:5009deb02f67fc3c59c8ce6b82408d1d35d4e38f \
  sha256:93ac71a7afa5b70c1b1032516663658c51e653087f42a3fc8044752c026443e9 \
    size:15139737
