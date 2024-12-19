# Arduino CLI-specific setup
ARDUINO_CLI = ./bin/arduino-cli
BOARD = arduino:avr:uno  # Replace with your board
PORT = /dev/ttyACM0  # Replace with your port

SKETCH = src

# Targets
all: compile upload

compile:
	$(ARDUINO_CLI) compile --fqbn $(BOARD) $(SKETCH)

upload:
	$(ARDUINO_CLI) upload -p $(PORT) --fqbn $(BOARD) $(SKETCH)

clean:
	rm -rf build

.PHONY: all compile upload clean

