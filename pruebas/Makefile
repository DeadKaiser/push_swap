CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = push_swap
SRCDIR = src
#BINDIR = .
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
all: $(TARGET)
$(TARGET):	$(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)
fclean:clean
	rm -f ${TARGET}
re: fclean all

.PHONY: re fclean all clean
