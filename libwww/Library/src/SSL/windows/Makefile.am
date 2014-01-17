## Process this file with Automake to create Makefile.in.

SUFFIXES = .files .def

SRC = *.c
MAK = *.mak
FLS = *.files

BUILT_SOURCES = \
	wwwssl.def

EXTRA_DIST = \
	$(BUILT_SOURCES) \
	wwwdll.def \
	$(SRC) \
	$(FLS) \
	$(MAK)

def-clean:
	test -z "$(BUILT_SOURCES)" || rm -f $(BUILT_SOURCES)

def: $(BUILT_SOURCES)

.files.def:




