# This Makefile builds the TestSuite for the StackUsage dynamic analizer.

VPATH = ./Tests
OBJS =  TestSuiteRunner.o functionsVector.o
CFLAG = -Wall
CC = gcc
TARGET = TestRunner

all: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o ${TARGET} ${OBJS}

clean:
	-rm -f *.o TestRunner

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

