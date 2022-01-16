case=1 2 3 4
CC:=gcc

all : $(case:%=test_%)

test_% : main.c
	$(CC) $^ -o $@ -DCASE_$* -llapack
