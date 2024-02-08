CC=gcc

build:
	$(CC) src/main.cpp -o build/main

paper:
	pandoc notes/description.md -o notes/paper.pdf