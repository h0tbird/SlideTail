#------------------------------------------------------------------------------
# all:
#------------------------------------------------------------------------------

all:		st_main st_cbuf
		gcc $(CFLAGS) st_main.o st_cbuf.o $(LFLAGS) -o ../bin/stail
		rm -f *.o

#------------------------------------------------------------------------------
# st_main:
#------------------------------------------------------------------------------

st_main:	st_main.o
		gcc $(CFLAGS) -c st_main.c

#------------------------------------------------------------------------------
# st_cbuf:
#------------------------------------------------------------------------------

st_cbuf:	st_cbuf.o
		gcc $(CFLAGS) -c st_cbuf.c

#------------------------------------------------------------------------------
# clean:
#------------------------------------------------------------------------------

clean:
		rm -f *.o
		rm -f ../bin/stail

#------------------------------------------------------------------------------
# install:
#------------------------------------------------------------------------------

install:
		mkdir -p $(bin-dir)
		install -m755 ../bin/stail $(bin-dir)
