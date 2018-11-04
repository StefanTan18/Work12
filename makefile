all: dirinfo.c
	gcc dirinfo.c	

run:
	./a.out

clean:
	rm a.out
