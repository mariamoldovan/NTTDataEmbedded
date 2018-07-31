import bluetooth
import decodificareFrame as Decodifica
import trimiteDateCatreArduino as Trimite
import primesteDateDeLaArduino as Primeste

bd_addr = "20:16:10:20:52:66" #mac adress bluetooth arduino
port = 1
sock = bluetooth.BluetoothSocket (bluetooth.RFCOMM)
sock.connect((bd_addr,port))
def meniu():
    x = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

    while x != 0:
        if x == 1:
            Primeste.primesteDateDeLaArduino()
        elif x == 2:
            Trimite.trimiteCatreArduino()
        else:
            x = int(raw_input("1 - primeste \n2 - trimite \n0 - iesire \n"))

meniu()
