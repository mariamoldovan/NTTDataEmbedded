import bluetooth
import dec as AccesScripDecodificare
adresaBluetoothMAC = "20:16:10:20:52:66" #adresa mac bluetooth arduino
portDeConectareRFCOMM = 1
socket = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
socket.connect((adresaBluetoothMAC,portDeConectareRFCOMM))

def primesteDeLaArduinoBT():
    datePrimiteBT=""
    ct = 0
    while 1:
        try:
            datePrimiteBT+=socket.recv(8)
            datePrimiteBTend=datePrimiteBT.find('\n') #find returneaza -1 daca nu gaseste
            if datePrimiteBTend != -1:  #daca gaseste \n continua programul 
                #fisierScriereDate = open("date.txt", "a")
                #fisierScriereDate.write(datePrimiteBT)
		#fisierScriereDate.close()
                date = datePrimiteBT[:datePrimiteBTend]
                #print(datePrimiteBT)
                frameBinar = [ bin(ord(byte))[2:].zfill(8) for byte in date ]
                #print(frameBinar)
		AccesScripDecodificare.decodificareDate(frameBinar)
		ct+=1
		print(ct)
                datePrimiteBT = datePrimiteBT[datePrimiteBTend+1:]
        except KeyboardInterrupt:
            #meniuControl()
            break
    socket.close()

primesteDeLaArduinoBT()