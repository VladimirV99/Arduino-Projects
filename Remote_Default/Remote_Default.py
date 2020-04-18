import platform
import serial
import keyboard

os = platform.system()

ser = serial.Serial('/dev/ttyACM3')
ser.flushInput()

# Scanning Key Codes
# 125 - left windows
# 126 - right windows
# def on_key_release(key):
# 	print(key.scan_code)
# keyboard.on_release(on_key_release)
# keyboard.wait()

while True:
	ser_bytes = ser.readline()
	x = int(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
	if x == 16753245:  # COMMAND_CH_PREV
		keyboard.press_and_release('down')
	elif x == 16736925:  # COMMAND_CH
		keyboard.press_and_release('enter')
	elif x == 16769565:  # COMMAND_CH_NEXT
		keyboard.press_and_release('up')
	elif x == 16720605:  # COMMAND_PREV
		keyboard.press_and_release('left')
	elif x == 16712445:  # COMMAND_NEXT
		keyboard.press_and_release('right')
	elif x == 16761405:  # COMMAND_PLAY
		keyboard.press_and_release('space')
	elif x == 16769055:  # COMMAND_VOL_DOWN
		keyboard.press_and_release('fn+f6')
	elif x == 16754775:  # COMMAND_VOL_UP
		keyboard.press_and_release('fn+f7')
	elif x == 16748655:  # COMMAND_EQ
		keyboard.press_and_release('m')
	elif x == 16738455:  # COMMAND_CH_0
		keyboard.press_and_release('0')
	elif x == 16750695:  # COMMAND_CH_100_UP
		# Previous Desktop
		if os == 'Windows':
			keyboard.press_and_release('ctrl+windows+left')
		elif os == 'Linux':
			keyboard.press(125)
			keyboard.press_and_release('page up')
			keyboard.release(125)
	elif x == 16756815:  # COMMAND_CH_200_UP
		# Next Desktop
		if os == 'Windows':
			keyboard.press_and_release('ctrl+windows+right')
		elif os == 'Linux':
			keyboard.press(125)
			keyboard.press_and_release('page down')
			keyboard.release(125)
	elif x == 16724175:  # COMMAND_CH_1
		keyboard.press_and_release('1')
	elif x == 16718055:  # COMMAND_CH_2
		keyboard.press_and_release('2')
	elif x == 16743045:  # COMMAND_CH_3
		keyboard.press_and_release('3')
	elif x == 16716015:  # COMMAND_CH_4
		keyboard.press_and_release('4')
	elif x == 16726215:  # COMMAND_CH_5
		keyboard.press_and_release('5')
	elif x == 16734885:  # COMMAND_CH_6
		keyboard.press_and_release('6')
	elif x == 16728765:  # COMMAND_CH_7
		keyboard.press_and_release('7')
	elif x == 16730805:  # COMMAND_CH_8
		keyboard.press_and_release('8')
	elif x == 16732845:  # COMMAND_CH_9
		keyboard.press_and_release('9')
