#CFLAGS+=-Wall -Wextra -ansi -pedantic -g
CFLAGS+=-Wall -Wextra -std=c11 -pedantic -g
LIBS = -lm

objects = use_timer1 \
		  use_timer2 \
		  
all: $(objects)

use_timer1: use_timer1.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

use_timer2: use_timer2.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	$(RM) $(objects)
	$(RM) vgcore.*