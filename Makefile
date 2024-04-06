build: main.c src/stack.c
	mkdir -p bin
	gcc -o bin/main main.c src/stack.c
