CC = gcc
CFLAGS = -Wall -O2 -fPIC
LIBS = -luv -llua
TARGET = lasync.so  
SRC = $(wildcard src/*.c)
OBJS = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -shared -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
