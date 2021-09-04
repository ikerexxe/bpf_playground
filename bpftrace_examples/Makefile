sleep: sleep.o
	cc 20_sleep.o -o myprog

sleep.o:
	cc -c 20_sleep.c -o 20_sleep.o

read: read.o
	cc 21_read.o -o myprog

read.o:
	cc -c 21_read.c -o 21_read.o

.PHONY: clean
clean:
	rm -f *.o myprog
