import bluetooth
bd_addr = "20:16:10:20:52:66"
port = 1
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))


while 1:
    msg=raw_input("scrie: ")
    if msg != 'q':	    
    	sock.send(msg)
    else:
	break

sock.close()

