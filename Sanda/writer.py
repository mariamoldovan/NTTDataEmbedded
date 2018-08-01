import os
import sys
while True:
	path = "/home/pi/Senzor/FIFO/myfifo"
	fifo = open(path, "r")
	line = fifo.read()
	fifo.close()
	#print(line)
	#print(len(line))
	#print( [ bin(ord(ch))[2:].zfill(8) for ch in line ] )
	if line=="Send data!\0":
		#print ("Data request was send!")
		fifo = open(path, "w")
		fifo.write("140 200 20 10 32\0")
		fifo.close()
		#print("Distante trimise")
		#fifo.flush()
	#else:
		#print ("Data request was not send!")
#fifo.close()
#os.unlink(path)
