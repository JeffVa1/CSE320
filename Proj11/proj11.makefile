proj11: /user/cse320/Projects/project11.driver.o proj11.support.o
	gcc /user/cse320/Projects/project11.driver.o proj11.support.o -o proj11

proj11.support.o: proj11.support.s /user/cse320/Projects/project11.support.h
	gcc -Wall -c -march=native proj11.support.s