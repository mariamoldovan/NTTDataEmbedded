def decodif():
	f = open("date.txt","r")
	s=[]


	if f.mode == 'r':
		f1 = f.readlines()
		for x in f1:
			print("IN")
			#print([ bin(ord(ch))[2:].zfill(8) for ch in x ])
			s=[ bin(ord(ch))[2:].zfill(8) for ch in x ]
			#print(s)
			detec=s[6]
			for k in range (1,6):
				ok = 0
				#print(s[k])
				#print(s[6])
				#print(detec[k+1])
				#print("S["+str(k)+"]"+" are "+str(s[k].count('1'))+" biti de 1")
				if (s[k].count('1')+int(detec[k+1]))%2==0:
					#print("Datele sunt corecte!")
					ok = 1
				#else:
					#print("Datele sunt incorecte! Verificati bitii de paritate!")
		if ok:
			f = open("out.txt", "a")			
			f.write(x)			
			f.close()
