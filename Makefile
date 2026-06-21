# It builds all programs in the current directory.

SUFFIX   := cpp

BASENAME := basename
ECHO     := /bin/echo
RM       := rm
STRIP    := strip -s
TEST     := /bin/test
XARGS    := xargs

CXXFLAGS    := -Os #-Wall
LINKFLAGS   := #-lconfig++
BASENAMEOPT := -a -s .$(SUFFIX) -z
ECHOPT      := -e -n
ERRORMSG    := "Nothing to do!!"
XARGSOPT    := -0 -I {}

FILES     := $(wildcard *.$(SUFFIX))
NOSUFFIX  := $(BASENAME) $(BASENAMEOPT) $(FILES)
XARGSXE   := $(XARGS) $(XARGSOPT)
ECHOXE    := $(ECHO) $(ECHOPT)

CCFLAGS   := -Os
READLINE  := -lreadline

STUFF     != for F in *.$(SUFFIX); do \
    $(TEST) "$$($(BASENAME) -a -s .$(SUFFIX) $$F)" -ot "$$F" && \
    $(ECHOXE) "$$F "; done
    
NOSTUFFIX := $(BASENAME) $(BASENAMEOPT) $(STUFF)

all: .c .cpp 

unconditional:
	$(NOSUFFIX) | $(XARGSXE) $(CXX) $(CXXFLAGS) -o {} {}.$(SUFFIX) $(LINKFLAGS)
	$(NOSUFFIX) | $(XARGSXE) $(STRIP) {}

.c:
	$(CC) $(CCFLAGS) -o ascksum ascksum.c $(READLINE) && strip -s ascksum

.cpp:
	@if [ -z "$(STUFF)" ]; then echo $(ERRORMSG); exit 1; fi
	$(NOSTUFFIX) | $(XARGSXE) $(CXX) $(CXXFLAGS) -o {} {}.$(SUFFIX) $(LINKFLAGS)
	$(NOSTUFFIX) | $(XARGSXE) $(STRIP) {}

clean:
	$(RM) ascksum
	$(NOSUFFIX) | $(XARGSXE) $(RM) {}
