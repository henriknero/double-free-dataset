BIN=./bin/
SRC=./src/
all: example0 example1 example2 example3 example4 example5 example6 example7 example8 example9
example0: ${SRC}example0.c
	gcc ${SRC}example0.c -o ${BIN}example0
example1: ${SRC}example1.c
	gcc ${SRC}example1.c -o ${BIN}example1
example2: ${SRC}example2.c
	gcc ${SRC}example2.c -o ${BIN}example2
example3: ${SRC}example3.c
	gcc ${SRC}example3.c -o ${BIN}example3
example4: ${SRC}example4.c
	gcc ${SRC}example4.c -o ${BIN}example4
example5: ${SRC}example5.c
	gcc ${SRC}example5.c -o ${BIN}example5
example6: ${SRC}example6.c
	gcc ${SRC}example6.c -o ${BIN}example6
example7: ${SRC}example7.c
	gcc ${SRC}example7.c -o ${BIN}example7
example8: ${SRC}example8.c
	gcc ${SRC}example8.c -o ${BIN}example8
example9: ${SRC}example9.c
	gcc ${SRC}example9.c -o ${BIN}example9
