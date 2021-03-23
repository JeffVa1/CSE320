
/******************************************************************************
   The C string library
******************************************************************************/

#include <stdio.h>
#include <string.h>

/*-----------------------------------------------------------------------------
   Purpose:  Demonstrate selected operations from the C string library
-----------------------------------------------------------------------------*/

int main()
{
  const int MAX = 80;
  int num;

  const char A[] = "tiger", B[] = "aardvark", C[] = "ant";
  char D[MAX];

  printf( "\n" );
  printf( "A: %s\n", A );
  printf( "B: %s\n", B );
  printf( "C: %s\n", C );
  printf( "\n" );

  num = strlen( A );
  printf( "Number of characters in A: %d\n\n", num );

  printf( "The individual characters in A:\n" );
  for (unsigned i=0; i<strlen( A ); i++)
  {
    printf( "  %d: %c\n", i, A[i] );
  }
  printf( "\n" );

  printf( "Comparing B and C:\n" );
  printf( "  B .EQ. C:  %d\n", (strcmp( B, C ) == 0) );
  printf( "  B .NE. C:  %d\n", (strcmp( B, C ) != 0) );
  printf( "  B .GT. C:  %d\n", (strcmp( B, C ) >  0) );
  printf( "  B .GE. C:  %d\n", (strcmp( B, C ) >= 0) );
  printf( "  B .LT. C:  %d\n", (strcmp( B, C ) <  0) );
  printf( "  B .LE. C:  %d\n", (strcmp( B, C ) <= 0) );
  printf( "\n" );

  strcpy( D, A );
  printf( "Copied A to D; D now contains: %s\n\n", D );

  strcpy( D, B );
  printf( "Copied B to D; D now contains: %s\n\n", D );

  strcat( D, C );
  printf( "Appended C to D; D now contains: %s\n\n", D );
}
