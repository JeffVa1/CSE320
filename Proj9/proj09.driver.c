#include "/user/cse320/Projects/project09.support.h"
#include <stdio.h>
//	Jeffrey Valentic
//	11/12/2020
//	CSE 320 Project 9
//	Driver -> TESTING

int main()
{
    // Negate Testing =====================================================================================================
    int negate1 = negate(-10);
    int negate2 = negate(25);
    int negate3 = negate(0);

    int nActual1 = 10;
    int nActual2 = -25;
    int nActual3 = 0;

    printf("NEGATE TEST\n");
    printf("TEST 1: Negate -10 \n \t RESULT: %d \n \t EXPECTED: %d \n", negate1, nActual1);
    printf("TEST 2: Negate  25 \n \t RESULT: %d \n \t EXPECTED: %d \n", negate2, nActual2);
    printf("TEST 3: Negate   0 \n \t RESULT: %d \n \t EXPECTED: %d \n", negate3, nActual3);
    printf("\n");

    // Absolute Value Testing =====================================================================================================
    int absolute1 = absolute(-10);
    int absolute2 = absolute(25);
    int absolute3 = absolute(0);

    int absActual1 = 10;
    int absActual2 = 25;
    int absActual3 = 0;

    printf("ABSOLUTE VALUE TEST\n");
    printf("TEST 1: ABS -10 \n \t RESULT: %d \n \t EXPECTED: %d \n", absolute1, absActual1);
    printf("TEST 2: ABS  25 \n \t RESULT: %d \n \t EXPECTED: %d \n", absolute2, absActual2);
    printf("TEST 3: ABS   0 \n \t RESULT: %d \n \t EXPECTED: %d \n", absolute3, absActual3);
    printf("\n");

    // Addition Testing =====================================================================================================
    int add1 = add(10, 10);
    int add2 = add(-10, -10);
    int add3 = add(-10, 10);
    int add4 = add(100000000000, 100000000000);

    int addActual1 = 20;
    int addActual2 = -20;
    int addActual3 = 0;
    int addActual4 = 2147483648;

    printf("ADDITION TEST\n");
    printf("TEST 1: 10 + 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", add1, addActual1);
    printf("TEST 2: -10 + -10 \n \t RESULT: %d \n \t EXPECTED: %d \n", add2, addActual2);
    printf("TEST 3: -10 + 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", add3, addActual3);
    printf("TEST 4: inf + inf \n \t RESULT: %d \n \t EXPECTED: %d \n", add4, addActual4);
    printf("\n");

    // Subtraction Testing =====================================================================================================
    int sub1 = sub(10, 10);
    int sub2 = sub(10, -10);
    int sub3 = sub(-10, 10);
    int sub4 = sub(100000000000, -100000000000);

    int subActual1 = 0;
    int subActual2 = 20;
    int subActual3 = -20;
    int subActual4 = 2147483648;

    printf("SUBTRACTION TEST\n");
    printf("TEST 1: 10 - 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", sub1, subActual1);
    printf("TEST 2: 10 - -10 \n \t RESULT: %d \n \t EXPECTED: %d \n", sub2, subActual2);
    printf("TEST 3: -10 - 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", sub3, subActual3);
    printf("TEST 4: inf - -inf \n \t RESULT: %d \n \t EXPECTED: %d \n", sub4, subActual4);
    printf("\n");


    // Multiplication Testing =====================================================================================================
    printf("MULTIPLICATION TEST\n");
    int mul1 = mul(10, 10);
    int mul2 = mul(10, -10);
    int mul3 = mul(0, 10);
    int mul4 = mul(100000000000, 100000000000);

    int mulActual1 = 100;
    int mulActual2 = -100;
    int mulActual3 = 0;
    int mulActual4 = 2147483648;

    printf("TEST 1: 10 x 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", mul1, mulActual1);
    printf("TEST 2: 10 x -10 \n \t RESULT: %d \n \t EXPECTED: %d \n", mul2, mulActual2);
    printf("TEST 3: 0 x 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", mul3, mulActual3);
    printf("TEST 4: inf x -inf \n \t RESULT: %d \n \t EXPECTED: %d \n", mul4, mulActual4);
    printf("\n");

    // Division Testing =====================================================================================================
    int div1 = divide(10, 10);
    int div2 = divide(10, -10);
    int div3 = divide(0, 10);
    int div4 = divide(10, 0);

    int divActual1 = 1;
    int divActual2 = -1;
    int divActual3 = 0;
    int divActual4 = 2147483648;

    printf("DIVISION TEST\n");
    printf("TEST 1: 10 / 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", div1, divActual1);
    printf("TEST 2: 10 / -10 \n \t RESULT: %d \n \t EXPECTED: %d \n", div2, divActual2);
    printf("TEST 3: 0 / 10 \n \t RESULT: %d \n \t EXPECTED: %d \n", div3, divActual3);
    printf("TEST 4: 10 / 0 \n \t RESULT: %d \n \t EXPECTED: %d \n", div4, divActual4);
    printf("\n");

    // Exponent Testing =====================================================================================================
    int exp1 = power(10, 0);
    int exp2 = power(2, 4);
    int exp3 = power(0, 5);
    int exp4 = power(10, -2);

    int expActual1 = 1;
    int expActual2 = 16;
    int expActual3 = 0;
    int expActual4 = 2147483648;

    printf("EXPONENT TEST\n");
    printf("TEST 1: 10 ^ 0 \n \t RESULT: %d \n \t EXPECTED: %d \n", exp1, expActual1);
    printf("TEST 2: 2 ^ 4 \n \t RESULT: %d \n \t EXPECTED: %d \n", exp2, expActual2);
    printf("TEST 3: 0 ^ 5 \n \t RESULT: %d \n \t EXPECTED: %d \n", exp3, expActual3);
    printf("TEST 4: 10 ^ -2 \n \t RESULT: %d \n \t EXPECTED: %d \n", exp4, expActual4);
    printf("\n");

    // Factorial Testing =====================================================================================================
    int fac1 = factorial(5);
    int fac2 = factorial(0);
    int fac3 = factorial(50);
    int fac4 = factorial(-5);

    int facActual1 = 120;
    int facActual2 = 1;
    int facActual3 = 2147483648;
    int facActual4 = 2147483648;

    printf("FACTORIAL TEST\n");
    printf("TEST 1: 5! \n \t RESULT: %d \n \t EXPECTED: %d \n", fac1, facActual1);
    printf("TEST 2: 0! \n \t RESULT: %d \n \t EXPECTED: %d \n", fac2, facActual2);
    printf("TEST 3: 50! \n \t RESULT: %d \n \t EXPECTED: %d \n", fac3, facActual3);
    printf("TEST 4: -5! \n \t RESULT: %d \n \t EXPECTED: %d \n", fac4, facActual4);
    printf("\n");
}
