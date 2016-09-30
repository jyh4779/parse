SHELL =/bin/sh

MAKE =`which make`

DIR =LIBSRC SRC

all: APP

APP: ${patsubst %,__ALL__%,${DIR}}

${patsubst %,__ALL__%,${DIR}}:
	${MAKE} -C ${patsubst __ALL__%,%,$@}

clean: ${patsubst %,__CLEAN__%, ${DIR}}

${patsubst %,__CLEAN__%, ${DIR}}:
	${MAKE} -C ${patsubst __CLEAN__%,%,$@} clean
