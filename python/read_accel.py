import serial as serial

serial_port = '/dev/ttyACM0'
baud_rate = 115200; #In arduino, Serial.begin(baud_rate)
write_to_file_path = raw_input("Nome do arquivo onde salvar: ")
if not write_to_file_path:
    write_to_file_path = "default"

write_to_file_path += ".txt"

output_file = open(write_to_file_path, "w+")
ser = serial.Serial(serial_port, baud_rate)
while True:
    line = ser.readline()
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    print(line)
    output_file.write(line)