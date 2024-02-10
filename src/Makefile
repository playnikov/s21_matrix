FILE_CAT=file_cat.txt
CFLAGS=-Wall -Wextra -Werror

all: s21_matrix clean

s21_matrix: 
	gcc $(CFLAGS) -c *.c
	gcc $(CFLAGS) *.o -o s21_matrix

clear: 
	rm -rf s21_matrix

clean:
	rm -rf *.o 

rebuild: clear all