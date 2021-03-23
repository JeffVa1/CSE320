#include <stdio.h>

//	Jeffrey Valentic
//	10/22/2020
//	CSE 320 Project 6
//	proj06.support.c

union ieee_single
{
    float frep;
    unsigned int irep;
};

//CONSTANT VALUE RETURN FUNCTIONS ##############################################
float get_infinity()
{
    //returns the float value of infinity
    union ieee_single infinity;
    infinity.irep = 0x7F800000;
    return infinity.frep;
};

float get_nan()
{
    //returns the float value of nan
    union ieee_single nan;
    nan.irep = 0x7FC00000;
    return nan.frep;
};

float get_max_normal()
{
    //returns the float value of the max possible normal number
    union ieee_single max_normal;
    max_normal.irep = 0x7f7fffff;
    return max_normal.frep;
};

float get_min_normal()
{
    //returns the float value of the min possible normal number
    union ieee_single min_normal;
    min_normal.irep = 0x00800000;
    return min_normal.frep;
};

float get_max_denormal()
{
    //returns the float value of the max possible denormal number
    union ieee_single max_denormal;
    max_denormal.irep = 0x007fffff;
    return max_denormal.frep;
};

float get_min_denormal()
{
    //returns the float value of the min possible denormal number
    union ieee_single min_denormal;
    min_denormal.irep = 0x00000001;
    return min_denormal.frep;
};

//TESTING FUNCTIONS ############################################################
int is_zero(float x)
{
    //checks if the float input is zero
    //returns 1 if zero, and 0 if not zero
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
    //checks if the float input is negative
    //returns 1 if negative, and 0 if not negative
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
    //checks if the float input is infinity
    //returns 1 if infinity, and 0 if not infinity
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
    //checks if the float input is NaN
    //returns 1 if NaN, and 0 if not NaN
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
    //checks if the float input is a denormal number
    //returns 1 if denormal, and 0 if not denormal
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
    //Inverts the sign of the float input
    //Returns the input with a flipped sign.
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
    //If the float input is negative, it inverts it to be positive
    //Returns the absolute value of the float input
    union ieee_single input_val;
    input_val.frep = x;

    if (is_negative(input_val.frep)) {
        return (negate(input_val.frep));
    }
    else {
        return (input_val.frep);
    }
};