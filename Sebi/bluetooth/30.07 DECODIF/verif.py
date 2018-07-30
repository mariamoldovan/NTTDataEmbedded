f = open("date.txt","r")
s=[]


if f.mode == 'r':
	f1 = f.readlines()
	for x in f1:
		print([ bin(ord(ch))[2:].zfill(8) for ch in x ])
		s=[ bin(ord(ch))[2:].zfill(8) for ch in x ]
		for k in range (1,6):
			print(s[k])
			f = open("verif.txt", "a")
			f.write(str(int(str(s[k]),2)))
			f.write("\n")
		f.write("\n")
	f.close()
