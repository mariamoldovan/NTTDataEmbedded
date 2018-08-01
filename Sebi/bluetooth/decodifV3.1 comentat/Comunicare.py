import bluetooth
import decodif as AccesScripDecodif
adresaBluetoothMAC = "20:16:10:20:52:66" #adresa mac bluetooth arduino
portDeConectareRFCOMM = 1
socket = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
socket.connect((adresaBluetoothMAC,portDeConectareRFCOMM))

def primesteDeLaArduinoBT():
    datePrimiteBT=""

    while 1:
        try:
            datePrimiteBT+=socket.recv(1024)
            datePrimiteBTend=datePrimiteBT.find('\n')
            if datePrimiteBTend != -1:  #
                fisierScriereDate = open("date.txt", "a")
                fisierScriereDate.write(datePrimiteBT)
		fisierScriereDate.close()
		AccesScripDecodif.decodif()
                datePrimiteBT = datePrimiteBT[datePrimiteBTend+1:]
        except KeyboardInterrupt:
            meniuControl()
            break
    socket.close()


def trimiteCatreArduinoBT():
    while 1:
        dateDeTrimisCatreArduino = raw_input("Your message: ")
        if dateDeTrimisCatreArduino !='q':
            socket.send(dateDeTrimisCatreArduino)
        else:
            meniuControl()
            break

    BluetoothSocket.close()


def meniuControl():
    optiuneMeniu = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

    while optiuneMeniu != 0:
        if optiuneMeniu == 1:
            primesteDeLaArduinoBT()
        elif optiuneMeniu == 2:
            trimiteCatreArduinoBT()
        else:
            optiuneMeniu = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

meniuControl()
