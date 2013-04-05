package ?= ips
include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/git.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/noarch.mk


summary := programmable completion for the bash shell
license := GPL-2+
license-file := $(sourcedir)/COPYING

home     := http://bash-completion.alioth.debian.org/
name     := bash-completion
version  := 2.0
archive  := $(name)-$(version).tar.bz2
download := http://bash-completion.alioth.debian.org/files/$(archive)

configure-options += --sysconfdir=/etc

checksum-bash-completion-2.0.tar.bz2 := \
     md5:0d903f398be8c8f24bc5ffa6f86127f8 \
    sha1:3011add35574b4042c04b95fc0fd0f14006adc69 \
  sha256:e5a490a4301dfb228361bdca2ffca597958e47dd6056005ef9393a5852af5804 \
    size:250560

