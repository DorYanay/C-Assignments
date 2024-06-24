all: isort txtfind

isort: isort.c
	gcc -Wall -g -o isort isort.c

runi:
	./isort < sort_input.txt > outputisort.txt

clean:
	rm -f ./isort ./txtfind ./outputA.txt ./outputB.txt ./outputisort.txt


txtfind: txtfind.c
	gcc -Wall -g -o txtfind txtfind.c

leakTest:
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./txtfind < find_inputa.txt > outputA.txt