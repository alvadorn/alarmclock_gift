CC=xc8
ARGS=--chip=18F14K50 --asmlist --outdir=../bin/

all:
	$(CC) main.c $(ARGS) -Oalarmclock.hex

screen.o:
	$(CC) screen.c -C $(ARGS)

clean:
	rm -rf *.as *.cof *.hex *.hxl *.sdb *.sym *.pre *.lst *.d *.p1 *.obj *.rlf *.cmf