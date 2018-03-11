CC=xc8
ARGS=--chip=18F14K50 --asmlist --outdir=../bin/ --mode=pro -P --opt=+space,+speed -N255 -M
FILES=main.c settings.c i2c.c 5110.c dht11.c

all:
	$(CC) $(FILES) $(ARGS)

main.p1: 
	$(CC) main.c $(ARGS)
settings.p1:
	$(CC) settings.c $(ARGS)

screen.o:
	$(CC) screen.c -C $(ARGS)

clean:
	rm -rf ../bin/*