include /usr/share/cibs/rules/ips.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/noarch.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/copy.mk

summary := easily manage large numbers of patches
description := Quilt allows you to easily manage large numbers of patches by keeping \
	track of the changes each patch makes. Patches can be applied, \
	un-applied, refreshed, and more.
license := GPLv2+
license-file := COPYING


build-depends += \
	gnu-coreutils \
	gnu-patch \
	gnu-diffutils \
	gnu-sed \
	gnu-findutils \
	gnu-grep \
	gawk \

gnu = cp date grep tail tr stat sed \
	  diff patch find xargs mktemp

configure-options += \
	--without-getopt \
	--with-awk=/usr/bin/gawk \
	--with-bash=/usr/bin/bash \
	--with-diffstat=/usr/bin/diffstat \
	$(foreach _,$(gnu),--with-$_=/usr/gnu/bin/$_)

# Where we want quilt to install files
export BUILD_ROOT = $(protodir)

name     := quilt
home     := http://savannah.nongnu.org/projects/quilt
version  := 0.60
archive  := $(name)-$(version).tar.gz
download := http://download.savannah.gnu.org/releases/$(name)/$(archive)
checksum := \
     md5:058a08a9b626bdec9ec8c519dc92158c \
    sha1:c93c79598c55ba288f60babcc74a9fc9b04404b6 \
  sha256:3d72a292e432beb9a73f9d0acfe3a77c9b4d7e42209919bb244e9958c7cfe64b \
    size:442369

