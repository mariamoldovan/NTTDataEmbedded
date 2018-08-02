import bluetooth
import os
import sys
adresaBluetoothMAC = "20:16:10:20:52:66" #adresa mac bluetooth arduino
portDeConectareRFCOMM = 1
socket = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
socket.connect((adresaBluetoothMAC, portDeConectareRFCOMM))

def decodificareDate(frameBinar, frameASCII):
    
    print("in")
    
    
  
    
    lungimiASCII = []

    if len(frameBinar) > 7:
        lungimiSenzoriInDecimal = []
	detectieErori = frameBinar[6]
        for pozitie in range (1,6):
            if (frameBinar[pozitie].count('1')+int(detectieErori[pozitie + 2])) % 2 == 0:
                lungimiSenzoriInDecimal.append(str(int(str(frameBinar[pozitie]), 2)))
            else:
                print("Datele sunt incorecte! Verificati bitii de paritate!")
        if len(lungimiSenzoriInDecimal) == 5: #verificare daca avem 5 lungimi in lista (daca primim o data gresita nu se adauga la linia 27)
            lungimiSenzoriInDecimal.append(detectieErori[0])
	    #print(frameASCII[1:5])
	    print(" ".join(lungimiSenzoriInDecimal))
	    lungimiASCII = frameASCII[1:6]
	    distanteCuFrana = str(lungimiASCII + detectieErori[0])
	    print(distanteCuFrana)
	    return distanteCuFrana 

def primesteDeLaArduinoBT():
    
    datePrimiteBT=""
    distante = []

    while 1:
        try:
	    locatieFifoGUI = "/home/sanda/SS/Senzor/FIFO/fifoForDistances"
    	    fifoGUI = open(locatieFifoGUI, "r")
    	    linieDateFifo = fifoGUI.read()
    	    fifoGUI.close()
            datePrimiteBT+=socket.recv(1024)
            datePrimiteBTend=datePrimiteBT.find('\n') #find returneaza -1 daca nu gaseste
            if datePrimiteBTend != -1:  #daca gaseste \n continua programul 
                date = datePrimiteBT[:datePrimiteBTend]
                frameBinar = [ bin(ord(byte))[2:].zfill(8) for byte in date ] #convertire frame in baza 2
		#print(date)
		#print(frameBinar)
		if decodificareDate(frameBinar, date):
			distante = decodificareDate(frameBinar, date)
                datePrimiteBT = datePrimiteBT[datePrimiteBTend+1:]
	    if linieDateFifo == "Send data!\0":
        	print ("Data request was send!")
		fifoGUI = open(locatieFifoGUI, "w")
		print(str(distante))
		fifoGUI.write(str(distante) + "\0")
		fifoGUI.close()        
	    else:
		print ("Data request was not send!")
	    locatieFifoVolum = "/home/sanda/SS/Senzor/FIFO/fifoForVolume"
	    fifoVolum = open(locatieFifoVolum, "r")
	    volume = fifoVolum.read()
	    print(volume)
	    fifoVolum.close()
	    trimiteCatreArduinoBT(volume)
        except KeyboardInterrupt:
            break
    
    socket.close()

def trimiteCatreArduinoBT(volum):
    socket.send(volum)
    

primesteDeLaArduinoBT()
