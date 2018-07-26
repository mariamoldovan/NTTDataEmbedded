import bluetooth
import time
bd_addr = "20:16:10:20:52:66"
port = 1
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))



def receive():
    data=""
    data += sock.recv(1024)
    data_end = data.find('\n')
    if data_end != -1:
        rec = data[:data_end]
        print data
        print([ bin(ord(ch))[2:].zfill(8) for ch in data ])
        f = open("test.txt", "a")
        f.write(data)
        f.close()
        data = data[data_end+1:]

def send():
	while 1:
		tosend = raw_input("Your message: ")
		if tosend !='q':
	    		sock.send(tosend)
		else:
    			meniu()
			break
def close_connection():
    sock.close()
