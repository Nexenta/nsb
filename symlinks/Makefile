package ?= ips
include /usr/share/cibs/rules/$(package).mk
include /usr/share/cibs/rules/git.mk
include /usr/share/cibs/rules/patch.mk
include /usr/share/cibs/rules/64.mk


summary := scan/change symbolic links
license := PD-like
license-file := symlinks.license

home         := http://packages.debian.org/source/sid/symlinks
name         := symlinks
version      := 1.4
git-url      := http://anonscm.debian.org/git/users/joachim-guest/symlinks.git

# Tag, commit or branch. Passed to git checkout as is:
# git checkout $(git-checkout)
git-checkout := upstream/$(version)

configure-%-stamp:
	touch $@

build-%-stamp: download-stamp patch-stamp
	[ -d "$(builddir)" ] || mkdir -p "$(builddir)"
	$(CC) $(CFLAGS) $(sourcedir)/symlinks.c -o $(builddir)/symlinks
	touch $@

install-%-stamp: build-%-stamp
	mkdir -p $(protodir)/usr/bin
	cp $(builddir)/symlinks $(protodir)/usr/bin
	touch $@
