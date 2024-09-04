CC=gcc

build:
	$(CC) -o main src/main.c lib/tga/tga.c

paper:
	pandoc notes/description.md -o notes/paper.pdf
