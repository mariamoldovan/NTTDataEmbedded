def trimiteCatreArduino():
    while 1:
        dataDeTrimis = raw_input("Your message: ")
        if dataDeTrimis !='q':
            sock.send(dateDeTrimis)
        else:
            meniu()
            break

    sock.close()

