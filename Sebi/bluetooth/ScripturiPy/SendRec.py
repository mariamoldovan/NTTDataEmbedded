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
        #print(map(bin,bytearray(data)))
        print data
        print '\n'
        print([ bin(ord(ch))[2:].zfill(8) for ch in data ])
        f = open("test.txt", "a")
        f.write(data)
        f.close()
        data = data[data_end+1:]

def send():
    tosend = "1"
    sock.send(tosend)
    time.sleep(1)
    tosend = "0"
    sock.send(tosend)
    
def close_connection():
    sock.close()