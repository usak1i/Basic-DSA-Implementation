all: final

final: main.o kbhit.o
	@echo "Linking main and source object files"
	@gcc -o main main.o kbhit.o
	@echo "Compile completed"

main.o: main.c
	@echo "Compiling main source file"
	@gcc -c -lpthread main.c

clean:
	@echo "Removing object files"
	@rm main.o
	@echo "files removed"
