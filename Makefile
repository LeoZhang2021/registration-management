RM = rm -f
CC = gcc
CFLAGS = -std=c99 -g 

default: all

all: hk

hk: hk.c
	$(CC) $< $(CFLAGS) -o hk

clean:
	$(RM) hk

.PHONY: hk
