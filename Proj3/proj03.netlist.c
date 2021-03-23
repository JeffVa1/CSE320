
/******************************************************************************
  	Jeffrey Valentic
	CSE 320 - Project #3
	9/24/2020
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
	Purpose: Pass user input values to Circuits function for interpretation
	Recieve: User keyboard input to iterate through 0000 - 1111
	Return:  Maps the values of present variables (a-g) to a figure 8 shape
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;
  // Generates four input signals
  
  Signal ResetA(1);  
  Signal ResetB(1);  
  Signal Strobe(1);  
  
  Pulser ((SD("1a"), "r = Reset Counter"), ResetA, 'r', 1000);
  Pulser ((SD("2a"), "s = Strobe Counter"), Strobe, 's', 1000);

  Not (SD("1b"), ResetA, ResetB);
  
  Counter ( (SD("1c-2c"), "4-bit counter"),( ResetB, Strobe ), (w,x,y,z) );

  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);

  // Displays eight output signals
  Probe ( (SD("1f"), "Present"), Present );  
  Probe ( (SD("2e-2g"), "a"), a);
  Probe ( (SD("2g-4g"), "b"), b);
  Probe ( (SD("4g-6g"), "c"), c);
  Probe ( (SD("6e-6g"), "d"), d);
  Probe ( (SD("4e-6e"), "e"), e);
  Probe ( (SD("2e-4e"), "f"), f);
  Probe ( (SD("4e-4g"), "g"), g);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.

	Purpose: Convert 4-bit signals to single digit display
	Recieve: 4-bit signals from Simnet function
	Returns: Logic behind which values are present and displayed
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Declarations for auxiliary Signals

  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9, and10;

  // Circuit implementation (Not, And, Or gates)
  Not ( SD(sd,"1a"), w, notw );
  Not ( SD(sd,"2a"), x, notx );
  Not ( SD(sd,"3a"), y, noty );
  Not ( SD(sd,"4a"), z, notz );

  And ( SD(sd,"1b"), (z, notw), and1 );
  And ( SD(sd,"2b"), (y, notx, notz), and2 );
  And ( SD(sd,"3b"), (x, z, notw), and3 );
  And ( SD(sd,"4b"), (y, z, notw), and4 );
  And ( SD(sd,"5b"), (z, notx, notw), and5 );
  And ( SD(sd,"6b"), (w, y, notx, notz), and6 );
  And ( SD(sd,"7b"), (y, notx, notw), and7 );
  And ( SD(sd,"8b"), (x, z, notw, noty), and8 );
  And ( SD(sd,"9b"), (x, noty), and9 );
  And ( SD(sd,"10b"), (y, notx), and10 );

  Or ( SD(sd,"1c"), (and1, and2), Present ); 
  Or ( SD(sd,"2c"), (and2, and3, and4), a);
  Or ( SD(sd,"3c"), (and2, and4, and5), b);
  Or ( SD(sd,"4c"), (and1, and6), c);
  Or ( SD(sd,"5c"), (and7, and8), d);
  Or ( SD(sd,"6c"), (and2), e);
  Or ( SD(sd,"7c"), (and6, and8), f);
  Or ( SD(sd,"8c"), (notz, and9, and10), g);
  
}





