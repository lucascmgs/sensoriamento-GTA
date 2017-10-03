import serial as serial
import time

start_time = time.time()
serial_port = '/dev/ttyACM0'
baud_rate = 115200; #In arduino, Serial.begin(baud_rate)

ser = serial.Serial(serial_port, baud_rate)

output_file = open("teste_de_frequencia.txt", "w+")
cont = 0
while True:
    line = ser.readline()
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    #print(line)
    output_file.write(line)
    if time.time() - start_time >= 40:
        cont += 1
    if time.time() - start_time >= 41:
        break  
print(cont)