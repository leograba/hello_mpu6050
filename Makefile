CC ?= gcc
CFLAGS ?=

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

hello: main.o
	$(CC) -o accel_read main.o

#install: accel_read
#	install -d ${DESTDIR}${PREFIX}/bin/
#	install -m 755 accel_read ${DESTDIR}${PREFIX}/bin/

clean:
	rm -f *.o accel_read
