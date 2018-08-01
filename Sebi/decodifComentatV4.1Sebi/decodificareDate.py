import os
import sys

def decodificareDate():
    fisierCitireDate = open("date.txt", "r")
    frameBinar = []

    locatieFifo = "./myfifo"
    fifoGUI = open(locatieFifo, "r")
    linieDateFifo = fifoGUI.read()
    fifoGUI.close()
    if fisierCitireDate.mode == 'r':
        listaFrameuri = fisierCitireDate.readlines()
        for frame in listaFrameuri:
            if len(frame) > 7: #eliminare date incomplete
                lungimiSenzoriInDecimal = []
                print("IN")
                frameBinar = [ bin(ord(byte))[2:].zfill(8) for byte in frame ] #convertire frame in baza 2
                print(frameBinar) #afisez tot frameul
                detectieErori = frameBinar[6] #pregatesc parcurgerea unui frame bit cu bit
                for pozitie in range (1,6):
                    print(frameBinar[pozitie]) #afisez lungimile
                    print(frameBinar[6]) #afisez octetul de corectie
                    print(detectieErori[pozitie+1]) #parcurg octetul de corectie bit cu bit
                    print("S["+str(pozitie)+"]"+" are "+str(frameBinar[pozitie].count('1'))+" biti de 1")

                    if (frameBinar[pozitie].count('1')+int(detectieErori[pozitie + 2])) % 2 == 0:
                        print("Datele sunt corecte!")
                        lungimiSenzoriInDecimal.append(str(int(str(frameBinar[pozitie]), 2)))
                    else:
                        print("Datele sunt incorecte! Verificati bitii de paritate!")
                if len(lungimiSenzoriInDecimal) == 5: #verificare daca avem 5 lungimi in lista (daca primim o data gresita nu se adauga la linia 27)
                    lungimiSenzoriInDecimal.append(detectieErori[0])
                    print(len(lungimiSenzoriInDecimal))

                    #fisierCitireDate = open("verif.txt", "a")
                    #fisierCitireDate.write(" ".join(dist))
                    #fisierCitireDate.write("\n")
                    #fisierCitireDate.close()
        if linieDateFifo=="Send data!\0":
            print ("Data request was send!")
            fifoGUI = open(locatieFifo, "w")
            fifoGUI.write(" ".join(lungimiSenzoriInDecimal) + "\0")
            fifoGUI.close()




    #print("Distante trimise")
    #fifoGUI.flush()
        else:
            print ("Data request was not send!")
#fifoGUI.close()
#os.unlink(locatieFifo)
