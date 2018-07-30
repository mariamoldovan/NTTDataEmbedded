import os
import sys
while True:
	path = "./myfifo"
	fifo = open(path, "r")
	line = fifo.read()
	fifo.close()
	#print(line)
	#print(len(line))
	#print( [ bin(ord(ch))[2:].zfill(8) for ch in line ] )
	if line=="Send data!\0":
		print ("Data request was send!")
		fifo = open(path, "w")
		fifo.write("Distante!\0")
		fifo.close()
		#print("Distante trimise")
		#fifo.flush()
	else:
		print ("Data request was not send!")
#fifo.close()
#os.unlink(path)
