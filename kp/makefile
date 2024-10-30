GCC=gcc
CFLAGS=-std=c99 -Wall
all: temp

temp: temp_main.o temp_functions.o
	$(GCC) $(CFLAGS) -o temp temp_main.o temp_functions.o

temp_main.o: temp_main.c
	$(GCC) $(CFLAGS) -c -o temp_main.o temp_main.c

temp_functions.o: temp_functions.c
	$(GCC) $(CFLAGS) -c -o temp_functions.o temp_functions.c

clean:
	del *.o
	del temp.exe