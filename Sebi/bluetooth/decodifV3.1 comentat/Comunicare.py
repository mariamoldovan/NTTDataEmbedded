import bluetooth
import decodif as d
bd_addr = "20:16:10:20:52:66" #adresa mac bluetooth arduino
port = 1
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))

def primesteDeLaArduinoBT():
    datePrimiteBT=""

    while 1:
        try:
            datePrimiteBT+=sock.recv(1024)
            datePrimiteBTend=datePrimiteBT.find('\n')
            if datePrimiteBTend != -1:
                rec = datePrimiteBT[:datePrimiteBTend]
                f = open("date.txt", "a")
                f.write(datePrimiteBT)
		f.close()
		d.decodif()
                datePrimiteBT = datePrimiteBT[datePrimiteBTend+1:]
        except KeyboardInterrupt:
            meniu()
            break
    sock.close()


def trimiteCatreArduinoBT():
    while 1:
        dateDeTrimisCatreArduino = raw_input("Your message: ")
        if dateDeTrimisCatreArduino !='q':
            sock.send(dateDeTrimisCatreArduino)
        else:
            meniu()
            break

    sock.close()


def meniu():
    optiuneMeniu = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

    while optiuneMeniu != 0:
        if optiuneMeniu == 1:
            primesteDeLaArduinoBT()
        elif optiuneMeniu == 2:
            trimiteCatreArduinoBT()
        else:
            optiuneMeniu = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

meniu()
