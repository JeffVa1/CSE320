/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

union ieee_single
{
    float frep;
    unsigned int irep;
};

//CONSTANT VALUE RETURN FUNCTIONS ##############################################
float get_infinity()
{
    union ieee_single infinity;
    infinity.irep = 0x7F800000;
    return infinity.frep;
};

float get_nan()
{
    union ieee_single nan;
    nan.irep = 0x7FC00000;
    return nan.frep;
};

float get_max_normal()
{
    union ieee_single max_normal;
    max_normal.irep = 0x7f7fffff;
    return max_normal.frep;
};

float get_min_normal()
{
    union ieee_single min_normal;
    min_normal.irep = 0x00800000;
    return min_normal.frep;
};

float get_max_denormal()
{
    union ieee_single max_denormal;
    max_denormal.irep = 0x007fffff;
    return max_denormal.frep;
};

float get_min_denormal()
{
    union ieee_single min_denormal;
    min_denormal.irep = 0x00000001;
    return min_denormal.frep;
};

//TESTING FUNCTIONS ############################################################
int is_zero(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    if ((0x7FFFFFFF & input_val.irep) != 0)
    {
        return 0;
    }
    else {
        return 1;
    }
};


int is_negative(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    if ((0x80000000 & input_val.irep) == 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}

int is_infinity(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    union ieee_single exp_mask;
    exp_mask.irep = 0x7F800000;
    union ieee_single exp_field;
    exp_field.irep = (exp_mask.irep & input_val.irep) >> 23;

    union ieee_single frac_mask;
    frac_mask.irep = 0x007FFFFF;
    union ieee_single frac_field;
    frac_field.irep = (frac_mask.irep & input_val.irep);

    if (is_zero(frac_field.frep))
    {
        if (exp_field.irep == 255)
        {
            return 1;
        }
    }
    return 0;
};

int is_nan(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    union ieee_single exp_mask;
    exp_mask.irep = 0x7F800000;

    union ieee_single frac_mask;
    frac_mask.irep = 0x007FFFFF;

    union ieee_single exp_field;
    exp_field.irep = (exp_mask.irep & input_val.irep) >> 23;

    union ieee_single frac_field;
    frac_field.irep = (frac_mask.irep & input_val.irep);

    if (is_zero(frac_field.frep))
    {
        return 0;
    }
    else {
        if (exp_field.irep == 255) {
            return 1;
        }
    }
    return 0;
};



int is_denormal(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    union ieee_single exp_mask;
    exp_mask.irep = 0x7F800000;

    union ieee_single frac_mask;
    frac_mask.irep = 0x007FFFFF;

    union ieee_single exp_field;
    exp_field.irep = (exp_mask.irep & input_val.irep) >> 23;

    union ieee_single frac_field;
    frac_field.irep = (frac_mask.irep & input_val.irep);

    if (is_zero(exp_field.frep)) {
        if (is_zero(frac_field.frep)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
};

//OPERATION FUNCTIONS ##########################################################
float negate(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    union ieee_single sign_mask;
    sign_mask.irep = 0x80000000;

    union ieee_single flipped_val;
    flipped_val.irep = (sign_mask.irep ^ input_val.irep);

    return flipped_val.frep;
};

float absolute(float x)
{
    union ieee_single input_val;
    input_val.frep = x;

    if (is_negative(input_val.frep)) {
        return (negate(input_val.frep));
    }
    else {
        return (input_val.frep);
    }
};

int main() {
    printf("############################Start Of Test############################\n\n");
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

    printf("\n#####################################################################\n");


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


    printf("\n#####################################################################\n");
    // TESTING NEGATE
    printf("\nTESTING NEGATE FUNCTION\n\n");
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


    printf("\n#####################################################################\n");
    // TESTING ABSOLUTE
    printf("\nTESTING ABSOLUTE FUNCTION\n\n");

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

    printf("\n#############################End Of Test#############################\n");
    return 0;
}







