SHELL =/bin/sh

CC =`which cc`
AR =`which ar`

CP =`which cp`
MV =`which mv`
RM =`which rm`

LIB_DIRS =../LIB/

TARGET =libparse.a

SRCS = parse.c
OBJS = ${SRCS:.c=.o}

.SUFFIXES: .c .o

all: ${TARGET} install

${TARGET}: ${OBJS}
	${AR} rc $@ $^

clean: 
	${RM} -f ${TARGET} ${OBJS}

install: ${TARGET}
	${CP} ${TARGET} ${LIB_DIRS}
