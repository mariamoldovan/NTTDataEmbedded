import SendRec as sr

while True:
    try:
        #sr.receive()
        sr.send()
    except KeyboardInterrupt:
        break

sr.close_connection()
