
#include <stdio.h>

#include "/user/cse320/Projects/project07.hardware.h"

/**************************************************************************
  Demonstrate how to use functions "read_reg_file" and "write_reg_file".

  Translation:
    gcc -Wall /user/cse320/Projects/project07.driver.o \
      /user/cse320/Projects/project07.demo.c

  In general, you won't use hard-coded constants for the 4-bit register
  numbers or the 32-bit value on the "RD input port" in function "execute"
  when it calls functions "read_reg_file" and "write_reg_file".
**************************************************************************/ 

void execute()
{
  signal4 rd, rs1, rs2;
  signal32 RS1, RS2, RD;

  rs1 = 0x3;
  rs2 = 0x5;

  read_reg_file( rs1, rs2, &RS1, &RS2 );

  printf( "Inside execute -- rs1: %01X  RS1: %08X\n\n", rs1, RS1 );
  printf( "Inside execute -- rs2: %01X  RS2: %08X\n\n", rs2, RS2 );

  rd = 0x1;
  RD = 0x12345678;

  write_reg_file( rd, RD );
}

