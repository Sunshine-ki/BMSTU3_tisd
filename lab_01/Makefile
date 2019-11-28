
main.out: lab_01.o help_func.o
	gcc -o $@ $^

lab_01.o: lab_01.c help_func.h
	gcc -c $<

help_func.o: help_func.c help_func.h
	gcc -c $<

clean:
	rm *.o *.out

run:
	./main.out