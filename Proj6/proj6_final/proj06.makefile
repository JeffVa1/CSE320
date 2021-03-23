proj06: proj06.support.o proj06.driver.o
	gcc proj06.support.o proj06.driver.o -o proj06

proj06.support.o: proj06.support.c
	gcc -Wall -c proj06.support.c

proj06.driver.o: proj06.driver.c
	gcc -Wall -c proj06.driver.c