# Igniter Test Stand Project

[![CircleCI Build status](https://circleci.com/gh/elara-aerospace/elara-igniter_test_stand.svg?style=shield)](https://circleci.com/gh/elara-aerospace/elara-igniter_test_stand)
[![AppVeyor Build status](https://ci.appveyor.com/api/projects/status/nvklaq95vwa7hkda?svg=true)](https://ci.appveyor.com/project/suriyaa/elara-igniter_test_stand)
[![CodeFactor](https://www.codefactor.io/repository/github/elara-aerospace/elara-igniter_test_stand/badge)](https://www.codefactor.io/repository/github/elara-aerospace/elara-igniter_test_stand)
![GitHub repo size](https://img.shields.io/github/repo-size/elara-aerospace/elara-igniter_test_stand)

This project includes a MATLAB script and an Arduino sketch to facilitate communication between MATLAB and an Arduino board for controlling and monitoring the Igniter Test Stand of Elara Aerospace. The project demonstrates hardware control via serial communication.

## File Structure

```
├── src/
│   ├── Data visualisation Ignitor test stand 1.m # MATLAB script for visualization
│   ├── src.ino                                   # Arduino sketch
├── bin/
│   └── arduino-cli                               # Arduino CLI command-line tool (if installed locally)
├── Makefile                                      # Makefile for building and uploading Arduino sketch
├── .github/
│   └── workflows/
│       └── c-cpp.yml                             # GitHub Actions workflow for building and uploading
└── README.md                                     # Project documentation
```

## Requirements

- **MATLAB** (Tested with R2020a or later)
- **Arduino CLI** for building and uploading Arduino sketches.
- **Arduino Board** (e.g., Arduino Uno).
- **USB Cable** to connect the Arduino board to your computer.

## Setup Instructions

### 1. Clone the Repository

```bash
git clone https://github.com/elara-aerospace/elara-igniter_test_stand.git
cd elara-igniter_test_stand
```

### 2. Install Arduino CLI

Follow the [official Arduino CLI installation guide](https://arduino.github.io/arduino-cli/0.32/installation/) if the command-line tool in `./bin/` folder is outdated.

Alternatively, if using this repository:
```bash
mkdir -p bin
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh -s -- --dest bin
```

### 3. Install Arduino Core

Install the necessary platform for your Arduino board:
```bash
./bin/arduino-cli core update-index
./bin/arduino-cli core install arduino:avr
```

## How to Run the Code

### MATLAB Script

1. Open `Data visualisation Ignitor test stand 1.m` in MATLAB.
2. Ensure the correct serial port is specified in the script.
3. Run the script to visualize data sent by the Arduino.

### Arduino Sketch

1. Connect your Arduino board to your computer via USB.
2. Build and upload the Arduino sketch using the `Makefile`:
   ```bash
   make compile
   make upload
   ```

   Alternatively, use Arduino IDE:
   - Open `src.ino`.
   - Select the appropriate board and port.
   - Upload the sketch.

### Combined Workflow

1. Start the Arduino sketch to send data over the serial port.
2. Run the MATLAB script to read and visualize the data.

## Notes

- Update the `PORT` variable in the Makefile to match your Arduino's serial port.
- If using a GitHub Actions workflow, ensure the `Makefile` is configured correctly.


## Troubleshooting

1. **MATLAB Serial Port Issues**:
   - Ensure no other application is using the same serial port.
   - Update the port name in the MATLAB script.

2. **Arduino Upload Fails**:
   - Verify the correct board and port settings.
   - Ensure `arduino-cli` is installed and in the `PATH`.

## License

Copyright (C) 2024-present Elara Aerospace. All rights reserved.

