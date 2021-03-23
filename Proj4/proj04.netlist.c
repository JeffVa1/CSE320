
/******************************************************************************
  Project #4
  Jeffrey Valentic
  10/1/2020
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Replace with code for your Pulsers
  
  Pulser ((SD("1a"), "i = Init Signal"), Init, 'i', 1000);
  Pulser ((SD("2a"), "c = Clock Signal"), Clock, 'c', 1000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes
  Probe ( (SD("1e"), "w"), w);
  Probe ( (SD("2e"), "x"), x);
  Probe ( (SD("3e"), "y"), y);
  Probe ( (SD("4e"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3;
  Signal W, X, Y, Z;

  // Replace with code for your DFFs
  Dff (SD(sd,"1d"), (Init, W, Clock, Zero), w);
  Dff (SD(sd,"2d"), (Zero, X, Clock, Init), x);
  Dff (SD(sd,"3d"), (Init, Y, Clock, Zero), y);
  Dff (SD(sd,"4d"), (Zero, Z, Clock, Init), z);

  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd, "1a"), w, notw);
  Not ( SD(sd, "2a"), x, notx);
  Not ( SD(sd, "3a"), y, noty);
  Not ( SD(sd, "4a"), z, notz);

  And ( SD(sd, "1b"), (notx, noty), and1 );
  And ( SD(sd, "2b"), (notx, y, z), and2 );
  And ( SD(sd, "3b"), (notx, notw), and3 );

  Or ( SD(sd, "1c"), (and1), W);
  Or ( SD(sd, "2c"), (w, and2), X);
  Or ( SD(sd, "3c"), (noty, and3), Y);
  Or ( SD(sd, "4c"), (y), Z);

}

