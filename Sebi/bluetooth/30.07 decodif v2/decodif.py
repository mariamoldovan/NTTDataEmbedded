def decodif():
    f = open("date.txt","r")
    s = []


    while f.mode == 'r':
        f1 = f.readlines()
        for x in f1:
            if len(x) > 7:
                dist = []
                print("IN")
                #print([ bin(ord(ch))[2:].zfill(8) for ch in x ])
                s = [ bin(ord(ch))[2:].zfill(8) for ch in x ]
                print(s)
                detec=s[6]
                for k in range (1,6):
                    print(s[k])
                    print(s[6])
                    print(detec[k+1])
                    print("S["+str(k)+"]"+" are "+str(s[k].count('1'))+" biti de 1")
                    
                    if (s[k].count('1')+int(detec[k+2]))%2==0:
                        print("Datele sunt corecte!")
                        dist.append(str(int(str(s[k]), 2)))
                    else:
                        print("Datele sunt incorecte! Verificati bitii de paritate!")
                #if len(dist) == 5:
                print(len(dist))
                f = open("verif.txt", "a")
                f.write(" ".join(dist))
                f.write("\n")
                f.close()
                    
                    
            


