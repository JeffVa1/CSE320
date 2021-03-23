
/******************************************************************************

  Assume you need to process a 32-bit floating point value as both a single
  precision value and as an unsigned integer.

  Example:  display a floating point value and its internal representation.

  <prompt> gcc -Wall project06.view.c
  <prompt> a.out

  -5.625000 (c0b40000)
  +7.250000 (40e80000)
  -0.125000 (be000000)
  +0.100000 (3dcccccd)

******************************************************************************/

#include <stdio.h>

union ieee_single
{
  float frep;
  unsigned int irep;
};

void view_float( float );

int main()
{
  view_float( -5.625 );

  view_float( 7.25 );

  view_float( -0.125 );

  view_float( 0.1 );

  return 0;
}

void view_float( float value_to_view )
{
  union ieee_single copy_of_value_to_view;

  copy_of_value_to_view.frep = value_to_view;

  printf( "%+f (%08x)\n", copy_of_value_to_view.frep,
    copy_of_value_to_view.irep );
}

