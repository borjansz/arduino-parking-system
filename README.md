# Parking Slot Availability System

The Parking Slot Availability System is a project that utilizes Arduino MKR 1000, ultrasonic sensors, Firebase Realtime Database, and a web-based interface to monitor the availability of parking slots in real-time. This system provides a convenient solution for users to check the occupancy status of parking spaces and make informed decisions.

## Table of Contents
- [Hardware Setup](#hardware-setup)
- [Used Components](#used-components)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Hardware Setup
To set up the system, follow these steps:
1. Connect the ultrasonic sensors to the Arduino MKR 1000 board using wires and a breadboard. Ensure the proper wiring connections between the sensors and the Arduino pins.
2. Connect the Arduino MKR 1000 to your computer using a USB cable and open the Arduino IDE.
3. Install the necessary libraries for the Arduino MKR 1000 and Firebase integration.
4. Upload the Arduino code provided in the project repository to the Arduino MKR 1000 board.
5. Set up the Firebase Realtime Database and obtain the necessary authentication credentials.
6. Update the Arduino code with your Firebase authentication details.
7. Create a web-based interface using HTML, CSS, and JavaScript to display the parking slot availability.
8. Host the web-based interface on a web server or use a local development environment.

## Used Components
The Parking Slot Availability System utilizes the following components:
- **Arduino MKR 1000**: The Arduino MKR 1000 board is a powerful microcontroller board based on the Atmel SAMD21 Cortex-M0+ 32-bit low power ARM microcontroller. It provides built-in Wi-Fi connectivity, making it ideal for IoT applications such as the parking slot availability system.
- **Ultrasonic Sensors (HC-SR04)**: The HC-SR04 ultrasonic sensors are commonly used for distance measurement. They work by emitting ultrasonic waves and measuring the time it takes for the waves to bounce back after hitting an object.
- **Wires and Breadboard**: Wires and a breadboard are used to establish the necessary electrical connections between the Arduino MKR 1000 board and the ultrasonic sensors.
- **Firebase Realtime Database**: Firebase Realtime Database is a cloud-hosted NoSQL database that allows for real-time data synchronization. It is used in this system to store and retrieve the occupancy status of parking slots.
- **Web-based Interface**: The web-based interface is developed using HTML, CSS, and JavaScript. It provides a user-friendly visual representation of the parking slot availability, which is continuously updated based on the data received from the Arduino MKR 1000 and Firebase.

## Features
- Real-time monitoring of parking slot availability.
- Web-based interface for easy access and visualization of data.
- Dynamic updates of parking slot status based on sensor readings.
- Integration with Firebase Realtime Database for reliable data storage and synchronization.
- User-friendly interface design for a seamless user experience.

## Installation
To install the Parking Slot Availability System, follow these steps:
1. Clone the project repository to your local machine.
2. Set up the Arduino IDE and install the necessary libraries for the Arduino MKR 1000 and Firebase integration.
3. Configure the Arduino MKR 1000 board and update the code with your Firebase authentication details.
4. Host the web-based interface on a web server or use a local development environment.
5. Connect the ultrasonic sensors to the Arduino MKR 1000 board as per the hardware setup instructions.
6. Upload the modified Arduino code to the Arduino MKR 1000 board.
7. Ensure that the Arduino MKR 1000 board and the web-based interface are connected to the same Wi-Fi network.
8. Open the web-based interface in a browser and start monitoring the parking slot availability. <br> <br>

**NOTE**: Ensure that the latest firmware for WiFiNINA and WiFi101 is installed. Also make sure to upload google.com and firebase.com certificates. For more info about firmware update and certificate upload visit: https://docs.arduino.cc/tutorials/mkr-1000-wifi/wifi-101-library-examples

## Usage
To use the Parking Slot Availability System, follow these steps:
1. Access the web-based interface by opening the provided URL in a browser.
2. The interface will display the status of each parking slot, indicating whether it is available or occupied.
3. Monitor the real-time updates on the interface as the ultrasonic sensors detect changes in the parking slot occupancy.
4. Make informed decisions based on the availability status displayed and choose an available parking slot accordingly.

## Contributing
Contributions to the Parking Slot Availability System are welcome! If you have any ideas, suggestions, or improvements, please feel free to submit a pull request or open an issue in the project repository. Together, we can enhance the system and make it even more useful for the community.

## License
The Parking Slot Availability System is released under the [MIT License](LICENSE). You are free to use, modify, and distribute the system for personal and commercial purposes. Please see the [LICENSE](LICENSE) file for more details.

## Acknowledgements
We would like to acknowledge the following individuals and resources for their contributions and support:
- [Arduino](https://www.arduino.cc/) for their powerful and versatile MKR 1000 board.
- [Firebase](https://firebase.google.com/) for their reliable Realtime Database service.
- The open-source community for providing useful libraries and resources for Arduino development.

We appreciate the support and contributions from everyone involved in making the Parking Slot Availability System a reality.
