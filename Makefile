#------------------------------------------------------------------------------
# exports:
#------------------------------------------------------------------------------

export CFLAGS = -Wall -Werror -g
export LFLAGS = -pthread
export bin-dir = $(basedir)/usr/bin

#------------------------------------------------------------------------------
# all:
#------------------------------------------------------------------------------

all:
	if [ ! -d 'bin' ]; then mkdir bin; fi
	make -C src

#------------------------------------------------------------------------------
# clean:
#------------------------------------------------------------------------------

clean:
	if [ -d 'bin' ]; then rm -rf bin; fi
	make -C src clean

#------------------------------------------------------------------------------
# install:
#------------------------------------------------------------------------------

install:
	make -C src install
