import decodif as Decodifica
def primesteDateDeLaArduino():
    dataPrimitaBT=""

    while 1:
        try:
            dataPrimitaBT+=sock.recv(1024)
            dataPrimitaBTend=dataPrimitaBT.find('\n')
            if dataPrimitaBTend != -1:
                rec = dataPrimitaBT[:dataPrimitaBTend]
                f = open("date.txt", "a")
                f.write(dataPrimitaBT)
                f.close()
		Decodifica.decodificaFrame()
                dataPrimitaBT = dataPrimitaBT[dataPrimitaBTend+1:]
        except KeyboardInterrupt:
            meniu()
            break
    sock.close()
