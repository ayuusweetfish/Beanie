build:
	arduino-cli compile . --fqbn arduino:avr:uno

flash:
	arduino-cli compile . --fqbn arduino:avr:uno --upload -p /dev/ttyUSB0

.PHONY: build flash
