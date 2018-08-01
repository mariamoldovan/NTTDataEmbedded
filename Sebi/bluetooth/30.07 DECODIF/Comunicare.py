import bluetooth
import decodif as d
bd_addr = "20:16:10:20:52:66"
port = 1
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))

def primeste():
    data=""

    while 1:
        try:
            data+=sock.recv(1024)
            data_end=data.find('\n')
            if data_end != -1:
                rec = data[:data_end]
                #print(map(bin,bytearray(data)))
                #print([ bin(ord(ch))[2:].zfill(8) for ch in data ])
                #f = open("date.txt", "a")
                #f.write(data)
		#f.close()
                frameBinar = [ bin(ord(ch))[2:].zfill(8) for ch in rec ]
		d.decodif(frameBinar)
                data = data[data_end+1:]
        except KeyboardInterrupt:
            meniu()
            break
    sock.close()


def trimite():
    while 1:
        tosend = raw_input("Your message: ")
        if tosend !='q':
            sock.send(tosend)
        else:
            meniu()
            break
        
    sock.close()
    
    
def meniu():
    x = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

    while x != 0:
        if x == 1:
            primeste()
        elif x == 2:
            trimite()
        else:
            x = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

meniu()
