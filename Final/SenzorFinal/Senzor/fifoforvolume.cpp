#include "fifoforvolume.h"

mode_t const fifoPermissions=0666;

void makeFIFOforVolume()
{
    char const* fifoForVolume = "/home/sanda/SS/Senzor/FIFO/fifoForVolume";

    // create the FIFO (named pipe)
    mkfifo(fifoForVolume, fifoPermissions);
}

void closeFIFOforVolume()
{
    char const* fifoForVolume = "/home/sanda/SS/Senzor/FIFO/fifoForVolume";
    // remove the FIFO
    unlink(fifoForVolume);
}

void sentVolumeThroughFIFO(u_int8_t volume)
{
    char const* fifoForVolume = "/home/sanda/SS/Senzor/FIFO/fifoForVolume";
    // open the FIFO
    u_int8_t fifoForVolumeFileDescriptor = open(fifoForVolume, O_WRONLY);

    volume=volume+1;
    write(fifoForVolumeFileDescriptor, &volume, sizeof(volume));

    close(fifoForVolumeFileDescriptor);

}
