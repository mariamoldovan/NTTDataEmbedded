import os
import sys

def decodificaFrame():
    f = open("date.txt", "r")
    s = []

    path = "./myfifo"
    fifo = open(path, "r")
    line = fifo.read()
    fifo.close()

    if f.mode == 'r':
        frameComplet = f.readlines()
        for octet in frameComplet:
            if len(octet) > 7:
                lungimiSenzoriInDecimal = []
                print("IN")
                bitOctet = [ bin(ord(ch))[2:].zfill(8) for ch in octet ]
                print(bitOctet) #afisez tot frameul
                detectieErori=bitOctet[6] #pregatesc parcurgerea unui octet bit cu bit
                for pozitie in range (1,6):
                    print(bitOctet[pozitie]) #afisez lungimile
                    print(s[6]) #afisez octetul de corectie
                    print(detectieErori[k+1])#parcug octetul de corectie bit cu bit
                    print("S["+str(pozitie)+"]"+" are "+str(s[pozitie].count('1'))+" biti de 1")
                    if (s[pozitie].count('1')+int(detectieErori[pozitie+2]))%2==0:
                        print("Datele sunt corecte!")
                        dist.append(str(int(str(s[pozitie]), 2)))
                    else:
                        print("Datele sunt incorecte! Verificati bitii de paritate!")
                if len(lungimiSenzoriInDecimal) == 5: #verific sa am 5 lungimi in fisier
                    dist.append(detectieErori[0])  #pun si frana de mana
                    print(len(lungimiSenzoriInDecimal))
        if line=="Send data!\0":
            print ("Data request was send!")
            fifo = open(path, "w")
            fifo.write(" ".join(lungimiSenzoriInDecimal) + "\0")
            fifo.close()




    #print("Distante trimise")
    #fifo.flush()
        else:
            print ("Data request was not send!")
#fifo.close()
#os.unlink(path)
