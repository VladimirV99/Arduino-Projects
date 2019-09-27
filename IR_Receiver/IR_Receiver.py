import serial

ser = serial.Serial('/dev/ttyACM3')
ser.flushInput()

while True:
    ser_bytes = ser.readline()
    x = ser_bytes[0:len(ser_bytes) - 2].decode("utf-8")
    print(x)
