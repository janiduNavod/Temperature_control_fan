Automatic Fan Control Based on Temperature
Project Overview:
This project aims to build a simple system that automatically turns on a fan when the ambient temperature exceeds 40°C. The core components of the project include a temperature sensor, a microcontroller, and a 12v DC fan.

Steps to Build:

Set Up the Temperature Sensor: Connect the temperature sensor(DHT 11) to the microcontroller according to the sensor's specifications (typically connecting VCC, GND, and the data pin).
Connect the Mosfect Module: Connect the mosfect module to the microcontroller. The input pin of the mosfect module will be connected to one of the digital output pins of the microcontroller.
Connect the Fan: Wire the fan to the mosfect module, ensuring that the power source for the fan is appropriate for the mosfect's rating.
Programming the Microcontroller: Write a simple program for the microcontroller that reads the temperature from the sensor and controls the mosfect module accordingly.
