#CFLAGS+=-Wall -Wextra -ansi -pedantic -g
CFLAGS+=-Wall -Wextra -std=c11 -pedantic -g -I.
LIBS = -lm
TARGET = timer_program
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	$(RM) $(TARGET) $(OBJ)
	$(RM) vgcore.*