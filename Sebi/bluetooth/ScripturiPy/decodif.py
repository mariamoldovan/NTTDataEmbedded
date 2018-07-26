f = open("test.txt","r")
s=[]


if f.mode == 'r':
	f1 = f.readlines()
	for x in f1:
		#print([ bin(ord(ch))[2:].zfill(8) for ch in x ]) #afisaj informatii in binar
		s=[ bin(ord(ch))[2:].zfill(8) for ch in x ]
		detec=s[6]  #bitul de detectie
		#print(s[6])
		for k in range (1,6):
			print(s[k]) #afisez lungimile (1-5)
			#print(detec[k+1])
			#print("S["+str(k)+"]"+" are "+str(s[k].count('1'))+" biti de 1")
			if (s[k].count('1')+int(detec[k+1]))%2==0: #verificare daca nr de biti 1 este par
													  #se aduna nr de biti de 1 dintr-o lungime cu bitul de 1 de pe pozitiil 2-7 din bitul de corectie
				print("Datele sunt corecte!")
			else:
				print("Datele sunt incorecte! Verificati bitii de paritate!")
