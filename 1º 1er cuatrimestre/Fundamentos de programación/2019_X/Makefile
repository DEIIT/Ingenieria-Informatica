###############################################################################
# (C) Algebro.
#
#	Makefile que permite compilar todos Los
# ficheros .cpp generando un ejecutable con el
# mismo nombre.
###############################################################################

SRC = $(wildcard *.cpp)
EXE = $(basename $(SRC))

CXXFLAGS = -std=c++11
LDFLAGS = -lrt

###############################################################################

default: $(EXE)

all: default

clean:
	$(RM) -fv $(EXE) core.* *~

###############################################################################

.PHONY: all clean default
.NOEXPORT:

###############################################################################
