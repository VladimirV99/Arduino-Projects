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
	if x == 3225354495:  # COMMAND_POWER
		keyboard.press_and_release('esc')
	elif x == 3225417735:  # COMMAND_TELETEXT
		# VLC Subtitle Toggle
		keyboard.press_and_release('v')
	elif x == 3225355005:  # COMMAND_SLEEP
		# Lock
		if os == 'Windows':
			keyboard.press_and_release('windows+l')
		elif os == 'Linux':
			keyboard.press(125)
			keyboard.press_and_release('l')
			keyboard.release(125)
	elif x == 3225364695:  # COMMAND_MUTE
		keyboard.press_and_release('m')
	elif x == 3225366735:  # COMMAND_CHANNEL_UP
		keyboard.press_and_release('up')
	elif x == 3225356535:  # COMMAND_CHANNEL_DOWN
		keyboard.press_and_release('down')
	elif x == 3225362655:  # COMMAND_VOLUME_UP
		keyboard.press_and_release('right')
	elif x == 3225358575:  # COMMAND_VOLUME_DOWN
		keyboard.press_and_release('left')
	elif x == 3225405495:  # COMMAND_ENTER
		keyboard.press_and_release('enter')
	elif x == 3225403455:  # COMMAND_FULLSCREEN
		keyboard.press_and_release('f')
	elif x == 3225416205:  # COMMAND_MENU
		keyboard.press_and_release(125)
	elif x == 3225403965:  # COMMAND_PLAY
		keyboard.press_and_release('space')
	elif x == 3225379485:  # COMMAND_STOP
		keyboard.press_and_release('s')
	elif x == 3225363165:  # COMMAND_SKIP_FORWARD
		# Next Desktop
		if os == 'Windows':
			keyboard.press_and_release('ctrl+windows+right')
		elif os == 'Linux':
			keyboard.press(125)
			keyboard.press_and_release('page down')
			keyboard.release(125)
	elif x == 3225371325:  # COMMAND_SKIP_BACKWARD
		# Previous Desktop
		if os == 'Windows':
			keyboard.press_and_release('ctrl+windows+left')
		elif os == 'Linux':
			keyboard.press(125)
			keyboard.press_and_release('page up')
			keyboard.release(125)
	elif x == 3225397845:  # COMMAND_SEEK_FORWARD
		keyboard.press_and_release('right')
	elif x == 3225365205:  # COMMAND_SEEK_BACKWARD
		keyboard.press_and_release('left')
	elif x == 3225395295:  # COMMAND_CH_1
		keyboard.press_and_release('1')
	elif x == 3225378975:  # COMMAND_CH_2
		keyboard.press_and_release('2')
	elif x == 3225411615:  # COMMAND_CH_3
		keyboard.press_and_release('3')
	elif x == 3225391215:  # COMMAND_CH_4
		keyboard.press_and_release('4')
	elif x == 3225374895:  # COMMAND_CH_5
		keyboard.press_and_release('5')
	elif x == 3225407535:  # COMMAND_CH_6
		keyboard.press_and_release('6')
	elif x == 3225399375:  # COMMAND_CH_7
		keyboard.press_and_release('7')
	elif x == 3225383055:  # COMMAND_CH_8
		keyboard.press_and_release('8')
	elif x == 3225415695:  # COMMAND_CH_9
		keyboard.press_and_release('9')
	elif x == 3225372855:  # COMMAND_CH_0
		keyboard.press_and_release('0')
	elif x == 3225375405:  # COMMAND_PIP
		# Youtube mini player
		keyboard.press_and_release('i')
	elif x == 3225412125:  # COMMAND_REC
		keyboard.press_and_release('f9')
