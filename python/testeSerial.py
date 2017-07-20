import serial
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
arduino.isOpen()

while True:
    normal = arduino.read(4)

    if not normal:
        continue
    valor = int(normal)
    print(valor)
