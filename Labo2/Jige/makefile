CC      = gcc
RM      = rm -f
EXEC  = ./

default:  Test1
Test1:
	$(CC) -Wall -Wextra -c Labo2_Part_2_1.c -o Labo2_Part_2_1.o
	$(CC) -Wall -Wextra Labo2_Part_2_1.o -o Labo2_Part_2_1
	make run1
Test2:
	$(CC) -Wall -Wextra -c Labo2_Part_2_2.c -o Labo2_Part_2_2.o
	$(CC) -Wall -Wextra Labo2_Part_2_2.o -o Labo2_Part_2_2
	make run2
run1:
	$(EXEC)Labo2_Part_2_1
run2:
	$(EXEC)Labo2_Part_2_2
ass:
	$(CC) -Wall -Wextra -S Labo2_Part_2_1.c
	$(CC) -Wall -Wextra -S Labo2_Part_2_2.c
clean:
	$(RM) *.o
