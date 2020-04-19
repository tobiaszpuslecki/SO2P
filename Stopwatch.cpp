#include "Stopwatch.h"

Stopwatch::Stopwatch()
{
    //ctor
}

void Stopwatch::start()
{
    tstart = clock();
    measurement = 0;
}

double Stopwatch::read()
{
    tstop = clock();
    measurement = ((double)(tstop - tstart))/CLOCKS_PER_SEC;
    return measurement;
}
