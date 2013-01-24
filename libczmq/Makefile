package ?= ips

include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/archive.mk
include /usr/share/cibs/rules/autotools.mk
include /usr/share/cibs/rules/32.mk
include /usr/share/cibs/rules/64.mk

# Manpages are not installed if building out-of-source.
# Yes! Just like libzmq
include /usr/share/cibs/rules/copy.mk

summary := High-level C Binding for ZeroMQ
license := LGPL
license-file := COPYING.LESSER

build-depends += \
	library/libzmq	\
	developer/pkg-config

home     := http://czmq.zeromq.org/
name     := czmq
version  := 1.3.2
archive  := $(name)-$(version).tar.gz
download := http://download.zeromq.org/$(archive)

checksum-czmq-1.3.2.tar.gz := \
     md5:513fb1f9a7030c71c7d9a3a61f9970db \
    sha1:09354c07cad4570d1360ad197c5f979c8f58847e \
  sha256:c9459a2b78f604f956b2ba99abd5608653ff2ef5ab70e405ab05f2b9f2d3656c \
    size:422847

