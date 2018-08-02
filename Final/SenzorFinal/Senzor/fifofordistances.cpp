#include "fifofordistances.h"


#define MAX_BUF 1024 //maximum buffer size for reading the distances and the hand break from the fifo
mode_t const fifoPermissions=0666;
void makeFIFOforDistances()
{
    char const* fifoForDistances = "/home/sanda/SS/Senzor/FIFO/fifoForDistances";

    // create the FIFO (named pipe)
    mkfifo(fifoForDistances, fifoPermissions);
}

void closeFIFOforDistances()
{
    char const* fifoForDistances = "/home/sanda/SS/Senzor/FIFO/fifoForDistances";
    // remove the FIFO
    unlink(fifoForDistances);
}

void getDistancesThroughFIFO(u_int8_t distancesOfSenzors[], u_int8_t &franaDeMana)
{
    char const* fifoForDistances = "/home/sanda/SS/Senzor/FIFO/fifoForDistances";
    // open the FIFO
    u_int8_t fifoForDistancesFileDescriptor = open(fifoForDistances, O_WRONLY);


    // write a string to the FIFO
    u_int8_t dataRequestMessage[]="Send data!";
    write(fifoForDistancesFileDescriptor, dataRequestMessage, sizeof(dataRequestMessage));
    close(fifoForDistancesFileDescriptor);

    /*char bufferReadFromFIFO[MAX_BUF];

    // open the FIFO for reading
    fifoForDistancesFileDescriptor = open(fifoForDistances, O_RDONLY);

    // read message from FIFO
    read(fifoForDistancesFileDescriptor, bufferReadFromFIFO, MAX_BUF);
    char* tokensDataFromFIFO=strtok(bufferReadFromFIFO, " ");

    u_int8_t i=0;
    while (tokensDataFromFIFO!=NULL)
    {
        distancesOfSenzors[i++]=atoi(tokensDataFromFIFO);
        tokensDataFromFIFO=strtok(NULL, " ");
    }
    if (distancesOfSenzors[5]==0)
        franaDeMana=0;
    else
        franaDeMana=1;*/
    u_int8_t bufferReadFromFIFO[MAX_BUF];
    fifoForDistancesFileDescriptor = open(fifoForDistances, O_RDONLY);

    // read message from FIFO
    read(fifoForDistancesFileDescriptor, bufferReadFromFIFO, MAX_BUF);
    for (u_int8_t distancesIterator=0; distancesIterator<5; distancesIterator++)
        distancesOfSenzors[distancesIterator]=bufferReadFromFIFO[distancesIterator];
    franaDeMana=bufferReadFromFIFO[5]-48;

    close(fifoForDistancesFileDescriptor);
}
