CC := gcc
CROSS_COMPILE :=

TARGET := writer

SRCS := writer.c

OBJS := $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -std=c11 -g

ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)$(CC)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean

