SHELL =/bin/sh

CC =`which gcc`
CP =`which cp`
RM =`which rm`

LIB_DIRS =-L../LIB
BIN_DIRS =../BIN

LIBS =-lparse

TARGET =PARSE

SRC =parse_main.c

all: ${TARGET} install

${TARGET}:
	${CC} -o ${TARGET} ${SRC} ${LIB_DIRS} ${LIBS}

install:
	${CP} ${TARGET} ${BIN_DIRS}

clean:
	${RM} -f ${TARGET}

