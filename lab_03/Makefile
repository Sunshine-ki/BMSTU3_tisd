CFLAGS := -std=c99 -Wall -Werror -pedantic -std=c99 -lm

app.exe: *.o
	gcc -o app.exe $^  $(CFLAGS)

%.o: %.c
	gcc -c $^

clean:
	rm *.o *.exe

run:
	./app.exe < text/matrix_2.txt


# main.o: main.c 
# 	gcc -c $<

# matrix_multiplication.o: matrix_multiplication.c
# 	gcc -c $<

# cdio.o: cdio.c
# 	gcc -c $<