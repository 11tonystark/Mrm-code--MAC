import serial
ser=serial.Serial('/dev/tty.SLAB_USBtoUART',38400)

while(1):
		print(ser.readline())
