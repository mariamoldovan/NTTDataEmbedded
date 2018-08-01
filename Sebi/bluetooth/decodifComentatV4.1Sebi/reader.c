#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
	int fd;
	unlink("./myfifo");
	char* myfifo = "./myfifo";

	// create the FIFO (named pipe)
	int res = mkfifo(myfifo, 0666);
	if (res == -1)
	{
		perror("mkfifo() error: ");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
	// open the FIFO
	fd = open(myfifo, O_WRONLY);
	if (fd == -1)
	{
		perror("open() error: ");
		exit(EXIT_FAILURE);
	}
	
	// write a string to the FIFO
	char msg[]="Send data!";
	write(fd, msg, sizeof(msg));
//	printf("Data requiest was send!");
	close(fd);


	char buf[MAX_BUF];

	// open the FIFO for reading
	fd = open(myfifo, O_RDONLY);
	if (fd == -1)
	{
		perror("open() error: ");
		exit(EXIT_FAILURE);
	}

	// read message from FIFO
	read(fd, buf, MAX_BUF);
	printf("Message: %s\n", buf);
	
	close(fd);
	sleep(3);
	}
	// remove the FIFO
	unlink(myfifo);

	return 0;
}
