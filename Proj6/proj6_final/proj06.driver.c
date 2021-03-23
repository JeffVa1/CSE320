#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

//	Jeffrey Valentic
//	10/22/2020
//	CSE 320 Project 6
//	proj06.driver.c -> TESTING FILE

void get_testing() {
    // TESTING GET_ FUNCTIONS
    printf("TESTING GET_ FUNCTIONS\n\n");
    union ieee_single num;

    num.frep = get_infinity();
    printf("\tINFINITY: \tReal: %14.8e \tHex integer: %08x \n", num.frep, num.irep);

    num.frep = get_nan();
    printf("\tNaN: \t\tReal: %14.8e \tHex integer: %08x \n", num.frep, num.irep);

    num.frep = get_max_normal();
    printf("\tMAX NORMAL: \tReal: %10.8e \tHex integer: %08x \n", num.frep, num.irep);

    num.frep = get_min_normal();
    printf("\tMIN NORMAL: \tReal: %10.8e \tHex integer: %08x \n", num.frep, num.irep);

    num.frep = get_max_denormal();
    printf("\tMAX DENORMAL: \tReal: %10.8e \tHex integer: %08x \n", num.frep, num.irep);

    num.frep = get_min_denormal();
    printf("\tMIN DENORMAL: \tReal: %10.8e \tHex integer: %08x \n", num.frep, num.irep);
}

void is_testing() {
    // TESTING IS_ FUNCTIONS
    printf("\nTESTING IS_ FUNCTIONS\n");
    float testing_num;
    int result;

    //IS_ZERO TESTING
    printf("\nIS_ZERO:\n");

    testing_num = 0;
    result = is_zero(testing_num);
    printf("\tGiven Value: %10.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = get_infinity();
    result = is_zero(testing_num);
    printf("\tGiven Value: %14.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = negate(get_infinity());
    result = is_zero(testing_num);
    printf("\tGiven Value: %14.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = get_nan();
    result = is_zero(testing_num);
    printf("\tGiven Value: %14.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = get_max_normal();
    result = is_zero(testing_num);
    printf("\tGiven Value: %10.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = get_min_normal();
    result = is_zero(testing_num);
    printf("\tGiven Value: %10.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = get_max_denormal();
    result = is_zero(testing_num);
    printf("\tGiven Value: %10.8e \tIs Zero: %1x \n", testing_num, result);

    testing_num = get_min_denormal();
    result = is_zero(testing_num);
    printf("\tGiven Value: %10.8e \tIs Zero: %1x \n", testing_num, result);


    //IS_NEGATIVE TESTING
    printf("\nIS_NEGATIVE:\n");

    testing_num = -10;
    result = is_negative(testing_num);
    printf("\tGiven Value: %10.7e \tIs Negative: %1x \n", testing_num, result);

    testing_num = get_infinity();
    result = is_negative(testing_num);
    printf("\tGiven Value: %14.8e \tIs Negative: %1x \n", testing_num, result);

    testing_num = negate(get_infinity());
    result = is_negative(testing_num);
    printf("\tGiven Value: %14.8e \tIs Negative: %1x \n", testing_num, result);

    testing_num = get_nan();
    result = is_negative(testing_num);
    printf("\tGiven Value: %14.8e \tIs Negative: %1x \n", testing_num, result);

    testing_num = get_max_normal();
    result = is_negative(testing_num);
    printf("\tGiven Value: %10.8e \tIs Negative: %1x \n", testing_num, result);

    testing_num = get_min_normal();
    result = is_negative(testing_num);
    printf("\tGiven Value: %10.8e \tIs Negative: %1x \n", testing_num, result);

    testing_num = get_max_denormal();
    result = is_negative(testing_num);
    printf("\tGiven Value: %10.8e \tIs Negative: %1x \n", testing_num, result);

    testing_num = get_min_denormal();
    result = is_negative(testing_num);
    printf("\tGiven Value: %10.8e \tIs Negative: %1x \n", testing_num, result);


    //IS_INFINITY TESTING
    printf("\nIS_INFINITY:\n");

    testing_num = 0;
    result = is_infinity(testing_num);
    printf("\tGiven Value: %10.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = get_infinity();
    result = is_infinity(testing_num);
    printf("\tGiven Value: %14.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = negate(get_infinity());
    result = is_infinity(testing_num);
    printf("\tGiven Value: %14.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = get_nan();
    result = is_infinity(testing_num);
    printf("\tGiven Value: %14.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = get_max_normal();
    result = is_infinity(testing_num);
    printf("\tGiven Value: %10.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = get_min_normal();
    result = is_infinity(testing_num);
    printf("\tGiven Value: %10.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = get_max_denormal();
    result = is_infinity(testing_num);
    printf("\tGiven Value: %10.8e \tIs Infinity: %1x \n", testing_num, result);

    testing_num = get_min_denormal();
    result = is_infinity(testing_num);
    printf("\tGiven Value: %10.8e \tIs Infinity: %1x \n", testing_num, result);

    //IS_NAN TESTING
    printf("\nIS_NAN:\n");

    testing_num = 0;
    result = is_nan(testing_num);
    printf("\tGiven Value: %10.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = get_infinity();
    result = is_nan(testing_num);
    printf("\tGiven Value: %14.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = negate(get_infinity());
    result = is_nan(testing_num);
    printf("\tGiven Value: %14.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = get_nan();
    result = is_nan(testing_num);
    printf("\tGiven Value: %14.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = get_max_normal();
    result = is_nan(testing_num);
    printf("\tGiven Value: %10.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = get_min_normal();
    result = is_nan(testing_num);
    printf("\tGiven Value: %10.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = get_max_denormal();
    result = is_nan(testing_num);
    printf("\tGiven Value: %10.8e \tIs NaN: %1x \n", testing_num, result);

    testing_num = get_min_denormal();
    result = is_nan(testing_num);
    printf("\tGiven Value: %10.8e \tIs NaN: %1x \n", testing_num, result);


    //IS_DENORMAL TESTING
    printf("\nIS_DENORMAL:\n");

    testing_num = 0;
    result = is_denormal(testing_num);
    printf("\tGiven Value: %10.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = get_infinity();
    result = is_denormal(testing_num);
    printf("\tGiven Value: %14.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = negate(get_infinity());
    result = is_denormal(testing_num);
    printf("\tGiven Value: %14.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = get_nan();
    result = is_denormal(testing_num);
    printf("\tGiven Value: %14.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = get_max_normal();
    result = is_denormal(testing_num);
    printf("\tGiven Value: %10.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = get_min_normal();
    result = is_denormal(testing_num);
    printf("\tGiven Value: %10.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = get_max_denormal();
    result = is_denormal(testing_num);
    printf("\tGiven Value: %10.8e \tIs Denormal: %1x \n", testing_num, result);

    testing_num = get_min_denormal();
    result = is_denormal(testing_num);
    printf("\tGiven Value: %10.8e \tIs Denormal: %1x \n", testing_num, result);
}

void negate_testing() {
    // TESTING NEGATE
    printf("\nTESTING NEGATE FUNCTION\n\n");
    float testing_num;
    float result2;

    testing_num = 0;
    result2 = negate(testing_num);
    printf("\tGiven Value: %10.8e \tNegated: %10.8e \n", testing_num, result2);

    testing_num = get_infinity();
    result2 = negate(testing_num);
    printf("\tGiven Value: %14.8e \tNegated: %15.8e \n", testing_num, result2);

    testing_num = negate(get_infinity());
    result2 = negate(testing_num);
    printf("\tGiven Value: %14.8e \tNegated: %15.8e \n", testing_num, result2);

    testing_num = get_nan();
    result2 = negate(testing_num);
    printf("\tGiven Value: %14.8e \tNegated: %15.8e \n", testing_num, result2);

    testing_num = get_max_normal();
    result2 = negate(testing_num);
    printf("\tGiven Value: %10.8e \tNegated: %10.8e \n", testing_num, result2);

    testing_num = get_min_normal();
    result2 = negate(testing_num);
    printf("\tGiven Value: %10.8e \tNegated: %10.8e \n", testing_num, result2);

    testing_num = get_max_denormal();
    result2 = negate(testing_num);
    printf("\tGiven Value: %10.8e \tNegated: %10.8e \n", testing_num, result2);

    testing_num = get_min_denormal();
    result2 = negate(testing_num);
    printf("\tGiven Value: %10.8e \tNegated: %10.8e \n", testing_num, result2);
}

void absolute_testing() {
    // TESTING ABSOLUTE
    printf("\nTESTING ABSOLUTE FUNCTION\n\n");
    float testing_num;
    float result2;

    testing_num = -143;
    result2 = absolute(testing_num);
    printf("\tGiven Value: %10.7e \tAbsolute: %10.8e \n", testing_num, result2);

    testing_num = get_infinity();
    result2 = absolute(testing_num);
    printf("\tGiven Value: %14.8e \tAbsolute: %14.8e \n", testing_num, result2);

    testing_num = negate(get_infinity());
    result2 = absolute(testing_num);
    printf("\tGiven Value: %14.8e \tAbsolute: %14.8e \n", testing_num, result2);

    testing_num = get_nan();
    result2 = absolute(testing_num);
    printf("\tGiven Value: %14.8e \tAbsolute: %14.8e \n", testing_num, result2);

    testing_num = get_max_normal();
    result2 = absolute(testing_num);
    printf("\tGiven Value: %10.8e \tAbsolute: %10.8e \n", testing_num, result2);

    testing_num = get_min_normal();
    result2 = absolute(testing_num);
    printf("\tGiven Value: %10.8e \tAbsolute: %10.8e \n", testing_num, result2);

    testing_num = get_max_denormal();
    result2 = absolute(testing_num);
    printf("\tGiven Value: %10.8e \tAbsolute: %10.8e \n", testing_num, result2);

    testing_num = get_min_denormal();
    result2 = absolute(testing_num);
    printf("\tGiven Value: %10.8e \tAbsolute: %10.8e \n", testing_num, result2);
}

int main() {
    printf("############################Start Of Test############################\n\n");
    
    get_testing();

    printf("\n#####################################################################\n");

    is_testing();

    printf("\n#####################################################################\n");
    
    negate_testing();

    printf("\n#####################################################################\n");
    
    absolute_testing();

    printf("\n#############################End Of Test#############################\n");
    return 0;
}