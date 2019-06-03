all: commandline testdir

.PHONY: all

commandline: commandline.c
	gcc -Wall -Wextra -o $@.exe $^

testdir: testdir.c
	gcc -Wall -Wextra -o $@.exe $^