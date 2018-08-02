#ifndef FIFO_H
#define FIFO_H

extern "C"
{
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <string.h>

    void makeFIFOforDistances();
    void getDistancesThroughFIFO(u_int8_t distancesOfSenzors[], u_int8_t  &franaDeMana);
    void closeFIFOforDistances();

}
#endif // FIFO_H
