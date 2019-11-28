CFLAGS := -std=c99 -Wall -Werror -pedantic -std=c99 -lm

app.exe: main.o io.o literature.o sort.o
	gcc -o app.exe $^

main.o: main.c
	gcc -c main.c 

io.o: io.c 
	gcc -c io.c

literature.o: literature.c
	gcc -c literature.c

sort.o: sort.c
	gcc -c sort.c

clean:
	rm *.o *.exe

run:
	./app.exe text/text_1.txt