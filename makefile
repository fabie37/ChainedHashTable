test: main.o hashtable.o
	clang -Werror -Wall -o test main.o hashtable.o

main.o: main.c
	clang -Werror -Wall -o main.o -c main.c

hashtable.o: hashtable.c hashtable.h
	clang -Werror -Wall -o hashtable.o -c hashtable.c 

clean:
	-rm main.o hashtable.o test addr mem

mem-s: 
	clang -fsanitize=memory -fno-omit-frame-pointer -o2 -g main.o hashtable.o -o mem

addr-s: 
	clang -fsanitize=address -fno-omit-frame-pointer -o1 -g main.o hashtable.o -o addr