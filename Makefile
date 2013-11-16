
# Your C compiler.

CC=gcc

# Where your readline library is.
# You can compile with a hacked replacement of readline instead by
# doing this:

#INC=-Ifake-readline/
#LIB=fake-readline/readline.c

INC=-I/usr/include/readline
LIB=-lreadline

# Flags to the compiler: 
#
# -DMEM_DEBUG          Check for memory leaks.
#

#CFLAGS=-g -Wall -DMEM_DEBUG $(INC) -pg
CFLAGS=-O2 -g -Wall $(INC) -pg

# No need to change this stuff.

OBJS=list.o hash.o builtins.o esh.o format.o gc.o
VERS=0.8

all: $(OBJS)
	$(CC) esh.o list.o hash.o builtins.o format.o gc.o $(LIB) -o esh

backup:
	cp -f Makefile *.[ch] /home/backup/esh

clean:
	-rm *~ */*~ *.o core bold esh gmon.out

dist:
	-rm esh*tar.gz
	cd ..; tar -c esh/* > esh/esh-$(VERS).tar
	gzip esh-$(VERS).tar

depend:
	makedepend -Y $(OBJS:.o=.c)


# DO NOT DELETE

list.o: gc.h list.h hash.h
hash.o: gc.h list.h hash.h
builtins.o: common.h format.h list.h gc.h hash.h job.h esh.h builtins.h
esh.o: common.h format.h list.h gc.h hash.h job.h builtins.h
gc.o: gc.h format.h
