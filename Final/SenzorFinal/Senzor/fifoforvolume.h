#ifndef FIFOFORVOLUME_H
#define FIFOFORVOLUME_H

extern "C"
{
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <string.h>

    void makeFIFOforVolume();
    void sentVolumeThroughFIFO(u_int8_t volume);
    void closeFIFOforVolume();

}

#endif // FIFOFORVOLUME_H
