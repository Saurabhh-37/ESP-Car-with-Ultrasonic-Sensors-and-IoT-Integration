
# DIY Car with Ultrasonic Sensors and IoT Integration

This repository contains the code and documentation for a DIY Car project that incorporates ultrasonic sensors on all four sides. The car is connected to an ESP32 microcontroller, which drives a L298N motor driver to control the movement of the four wheels. Additionally, the ESP32 is connected to the Blynk IoT platform, providing real-time distance readings of objects detected by the sensors and allowing for remote monitoring and control.



## Features

- Ultrasonic sensors on all four sides for object detection
- Real-time distance measurements displayed on the Blynk IoT platform
- Warnings and automatic vehicle stop when objects are detected within a certain range
- Real-time control of the car's motion through the Blynk application
- Integration with the ESP32 microcontroller and L298N motor driver for precise motor control
- Easily customizable and expandable for future enhancements



## Components Used
- DIY car chassis with four wheels
- Ultrasonic sensors (HC-SR04 or similar) - 4x
- ESP32 microcontroller
- L298N motor driver
- Blynk IoT platform (mobile application)
- Jumper wires
- Power supply (battery or DC adapter)
- Breadboard (optional, for circuit prototyping)

## Block Diagram

![Block Diagram](https://github.com/Saurabhh-37/ESP-Car-with-Ultrasonic-Sensors-and-IoT-Integration/blob/main/Images/blockdiagram.jpg)
## Installation and Usage
1. Set up the Arduino IDE and ESP32 board support.
2. Install the required libraries for ultrasonic sensor and Blynk integration.
3. Connect the components as per the circuit diagram provided in the repository.
4. Upload the code to the ESP32 microcontroller using the Arduino IDE.
5. Open the Blynk application on your mobile device and configure the Blynk project.
6. Power on the DIY car and connect it to the Blynk project.
7. Monitor the real-time distance readings, control the car's motion, and observe warnings through the Blynk application.

## Flow Chart

![Flow Chart](https://github.com/Saurabhh-37/ESP-Car-with-Ultrasonic-Sensors-and-IoT-Integration/blob/main/Images/Flowchart.jpg)
## Testing and Calibration
- Power on the DIY car and ensure all components are connected properly.
- Verify the readings from the ultrasonic sensors by monitoring the Blynk application.
- Gradually move objects closer to the sensors and observe if the warnings and vehicle stop functionality work as intended.
- Test the real-time motion control of the car using the Blynk application and ensure the vehicle responds correctly to commands.

## Screenshots

- DIY Car
  ![CAR](https://github.com/Saurabhh-37/ESP-Car-with-Ultrasonic-Sensors-and-IoT-Integration/blob/main/Images/DIY%20Car.jpg)

- BlynkIOT Interface

  ![BlynkIOT Interface](https://github.com/Saurabhh-37/ESP-Car-with-Ultrasonic-Sensors-and-IoT-Integration/blob/main/Images/blynkiotinterface.png)


## Acknowledgements

Special thanks to the contributors and open-source projects that have inspired and provided valuable resources for this DIY Car project.

## Feedback

If you have any feedback, please reach out to us at :

- saurabhhagawane718@gmail.com
- mayureshvsapkal9@gmail.com


## Contributors

-[ Saurabh Hagawane]()

 -[ Mayuresh Sapkal](https://github.com/MayurSapkal9)
