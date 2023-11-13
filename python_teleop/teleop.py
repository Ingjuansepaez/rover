import keyboard
import serial
import time

arduino = serial.Serial("/dev/ttyACM0",9600)



# Bucle infinito para leer la entrada del teclado continuamente
while True:
    # Leemos la tecla presionada sin tener que presionar Enter
    tecla = keyboard.read_event(suppress=True).name
    time.sleep(0.1)
    # Manipulamos la variable según la tecla presionada
    if tecla == 'w':
        print("adelante \n")
        command = "[-0.5,0.0]"
        arduino.write(command.encode())
    elif tecla == 'a':
        print("izquierda \n")
        command = "[0.0,0.5]"
        arduino.write(command.encode())
    elif tecla == 'x':
        mi_variable = 0
        print("atras \n")
        command = "[0.5,0.0]"
        arduino.write(command.encode())
    elif tecla == 'd':
        mi_variable = 0
        print("derecha \n")
        command = "[0.0,-0.5]"
        arduino.write(command.encode())
    elif tecla == 's':
        mi_variable = 0
        print("stop \n")
        command = "[0.0,0.0]"
        arduino.write(command.encode())
    elif tecla == 'q':
        print("Saliendo del programa.")
        break
    else:
        print("Tecla no válida. Intenta de nuevo.")

arduino.close()