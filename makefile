out: cs3-b.o
	gcc -o out cs3-b.c
.c.o:
	gcc -c $<
clean:
	rm -f *.o