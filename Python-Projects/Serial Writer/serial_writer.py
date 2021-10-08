import serial
while True:

    port_name = input("Enter the Serial port :")
    if port_name.lower() == "exit" or port_name.lower() == "quit":
        quit()
    else:
        baudrate = input("Enter the boudrate :")
        try:
            seri = serial.Serial(port_name, baudrate)
            print("\n_________Serial Port Conected !__________\n")
        except:
            print("invalied input !\n")
            continue

    while True:
        text = input(">>> ")

        if text.lower() == "back":
            break
        elif text.lower() == "exit" or text.lower() == "quit":
            quit()
        else:
            seri.write(text.encode())
