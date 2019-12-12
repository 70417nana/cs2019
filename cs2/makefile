# all: 
# 	gcc cs2-c.c -o cs2-c
# clean:
# 	rm -f *.o
cs2-c_main: cs2-c_main.o cs2-c_list.o   
	gcc -o cs2-c_main cs2-c_main.c cs2-c_list.c
cs2-c_main.o :
	gcc -c cs2-c_main.c
cs2-c_list.o :
	gcc -c cs2-c_list.c
clean:
	rm -f *.o
# cs2-c: cs2-c_main.c  cs2-c.c
# 	gcc -o cs2-c cs2-c_main.c cs2-c.c
# .c.o :
# 	gcc -c $<
# clean:
# 	rm -f *.o
