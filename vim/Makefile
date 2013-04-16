package ?= ips
include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/hg.mk
bits = 64

summary := the Editor
license := 
license-file := symlinks.license

hg-url  := https://vim.googlecode.com/hg/
home    := http://www.vim.org
name    := vim
version := 7.3.905
# hg update $(hg-update)
hg-update := v$(subst .,-,$(version))

build-depends += \
	developer/build/autoconf \
	developer/python

pre-configure-stamp: autoconf-stamp
autoconf-stamp: patch-stamp
	cp $(sourcedir)/src/config.mk.dist $(sourcedir)/src/auto/config.mk
	$(MAKE) -C $(sourcedir)/src autoconf
	$(MAKE) -C $(sourcedir) distclean
	touch $@

$(eval $(call add-variant,nox))
$(eval $(call add-variant,tiny))
$(eval $(call add-variant,basic))

configure-options := \
	--prefix=/usr \
	--mandir='$${prefix}'/share/man \
	--without-local-dir \
	--enable-fail-if-missing \

configure-options.nox := $(configure-options) \
	--without-x --enable-gui=no \
	--enable-pythoninterp \

configure-options.tiny := $(configure-options) \
	--with-features=small \
	--disable-gui \
	--disable-xsmp \
	--disable-xsmp-interact \
	--disable-netbeans \
	--enable-nls \
	--enable-multibyte \
	--enable-acl \

configure-options.basic := $(configure-options.nox) \
	--disable-luainterp \
	--disable-mzschemeinterp \
	--disable-perlinterp \
	--disable-pythoninterp \
	--disable-python3interp \
	--disable-rubyinterp \
	--disable-tclinterp \


# We are building in source dir, but within subdirs:
configure-%-stamp:
	$(MAKE) -C $(sourcedir)/src shadow SHADOWDIR=$(*)
	cd $(sourcedir) && if test -f src/auto/config.cache; then make distclean; fi
	cd $(sourcedir)/src/$(*) && \
		LDFLAGS="$(LDFLAGS)" CPPFLAGS="$(CPPFLAGS)" CFLAGS="$(CFLAGS)" CC="$(CC)"\
		./configure $(configure-options.$*)
	touch $@

build-%-stamp:
	$(MAKE) -C $(sourcedir)/src/$(*)
	touch $@


