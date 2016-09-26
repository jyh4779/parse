SHELL = /bin/sh
CC = `which gcc`
LIB = libparse.a
TARGET = parse
AR = ar rc
LIBDIR = ./LIB/
MD = mkdir
SRC = parse_main.c parse.c
OBJS = $(SRC:.c=.o)
LIBS = -lparse
.SUFFIXES : .c .o

ALL : $(TARGET)

$(TARGET) : $(LIB)
			  $(CC) -o $@ $(SRC) -L$(LIBDIR) $(LIBS)

$(LIB) : $(OBJS)
		   $(MD) $(LIBDIR)
		   $(AR) $(LIBDIR)$@ $^

clean : 
		rm -fr $(OBJS) $(LIBDIR) $(TARGET)
