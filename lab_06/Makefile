CFLAGS := -std=c99 -lm
FILE_O := $(subst .c,.o,$(wildcard functions/*.c))
HEADERS_DIR := headers/

tree.exe:  tree.o $(FILE_O)
	gcc -o tree.exe $^  $(CFLAGS)

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
