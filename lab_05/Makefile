# CFLAGS := -std=c99 -Wall -Werror -pedantic -std=c99 -lm -g
CFLAGS := -std=c99 -g
FILE_O := $(subst .c,.o,$(wildcard functions/*.c))
HEADERS_DIR := headers/

fragmentation.exe:  fragmentation.o $(FILE_O)
	gcc -o fragmentation.exe $^  $(CFLAGS)

app.exe:  main.o $(FILE_O)
	gcc -o app.exe $^  $(CFLAGS)

%.o: %.c
	gcc -c -I $(HEADERS_DIR) $^ $(CFLAGS)

functions/%.o: functions/%.c
	gcc -o $@ -c -I $(HEADERS_DIR) $^ $(CFLAGS)

clean:
	rm -f *.o *.exe functions/*.o

run:
	./app.exe