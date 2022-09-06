clean:
	rm -f firmware.bin
	rm -f firmware.elf
	esphome clean ./Firmware/esphome/common.yaml
build:
	esphome compile ./Firmware/esphome/common.yaml
	# Copy the compiled firmware to the root directory
	cp ./Firmware/esphome/.esphome/build/usb-timer1/.pioenvs/usb-timer1/firmware.bin .
	cp ./Firmware/esphome/.esphome/build/usb-timer1/.pioenvs/usb-timer1/firmware.elf .
	