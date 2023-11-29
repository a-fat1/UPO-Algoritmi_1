#CFLAGS+=-Wall -Wextra -ansi -pedantic -g
CFLAGS+=-Wall -Wextra -std=c11 -pedantic -g
LIBS = -lm

all: 02-NumApply

02-NumApply: 02-NumApply.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	$(RM) 02-NumApply vgcore.*