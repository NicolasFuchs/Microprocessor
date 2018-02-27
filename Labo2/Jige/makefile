CC      = gcc
RM      = rm -f
EXEC  = ./

default:  all
all:
	$(CC) -Wall -Wextra -c time.c -o time.o
	$(CC) -Wall -Wextra time.o -o time
	make run
run:
	$(EXEC)time
ass:
	$(CC) -Wall -Wextra -S time.c
clean:
	$(RM) *.o
