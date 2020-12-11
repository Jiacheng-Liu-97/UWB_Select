# UWB_Select
## ECE M202A Project Proposal: UWB Indoor Positioning - Select & Control

Contribute: Jiacheng Liu, Yibo Wang\
UCLA M202A Project Implementing UWB wireless indoor position: select &amp; control IOT Devices
<img src="General Pics/UWB.jpg" class="img-responsive" alt="">

### Link:
  [link to test.md](md_files/test.md)

### Background:
  At present, with the development of technology, indoor positioning scenes are becoming larger and more complex, and the demand for positioning and navigation in large supermarkets, general hospitals, airports, parking lots and other places is gradually increasing. There are many wireless positioning technologies and solutions. Commonly used positioning technologies include infrared, ultrasonic, and radio frequency signals, but they are not suitable for indoor positioning.
  There are currently different indoor positioning technologies, such as WiFi positioning technology, Bluetooth, RFID (Radio-frequency identification) and UWB (Ultra Wide-band). 

### Motivation of Using UWB Indoor Positioning Technology
  WiFi, RFID and Bluetooth indoor positioning technologies have their own advantages, but at the same time they also have some limitations and disadvantages. 
  As for the WiFi, it is easily interfered by other signals. This affects the positioning accuracy, the accuracy is not high, and the energy consumption of the positioner is high.  RFID does not have communication capabilities and has poor anti-interference capabilities, which is not easy to integrate into other systems, and the user's security and privacy protection and international standardization are not perfect.Under complex space environments, the stability of the Bluetooth system is slightly worse than other technologies, and it is greatly interfered by noise signals. Also, the price of Bluetooth devices and equipment is relatively expensive.
  Ultra-wideband indoor positioning uses UWB pulse signals, and multiple sensors use TDOA and AOA positioning algorithms to analyze the tag position. The multi-path resolution capability is high, the accuracy is high, and the positioning accuracy can reach sub-meter level.
  UWB does not need to use the carrier wave in the traditional communication system, but transmits and receives extremely narrow pulses with nanoseconds or less to transmit data, so it has a bandwidth of GHz order. Because the ultra-wideband positioning technology has the advantages of strong penetration, good anti-multipath effect, high security, low system complexity, and ability to provide precise positioning accuracy.
  Technically, UWB indoor positioning is undoubtedly one of the most ideal industrial positioning technologies, whether it is analyzed from the perspective of positioning accuracy, safety, anti-interference, and power consumption.

### Project Introduction
  At present, the accuracy of indoor positioning is insufficient in many technologies. However, UWB has great advantages in positioning accuracy. So we chose UWB as the positioning technology for our project. We want to use UWB to locate and then realize some control commands through location recognition. Now most of the control commands indoors are realized through voice recognition or image recognition. 
  Our project does not require voice or image recognition, UWB can perform positioning to recognize the direction we are pointing. Then the device in that direction will be controlled such as turning on and off. If the project goes well, we can add some features such as gesture control based on direction recognition.
  
### Prior works

### Implementation of project
  Our project basically has two phases. The first phase is to achieve our basic goals. We will use Decawave MDEK1001 Development Kit as our main development tool. The kit includes 12 RTLS units base on DWM1001 Development board, embedded location stack (binary) and gateway firmware.
  
<img src="General Pics/MDEK1001_600x430.jpg" class="img-responsive" alt="">
  
  We can use some of the RTLS units to be anchors and use 1 RTLS unit to be a tag. By using the tag twice to obtain the location of the two points, the two points will form a vector, which will be recognized by uwb and then find the corresponding device to perform the control command. For the first phase, we only want to turn on/turn off of the devices in different position.
  If we successfully complete the first phase, we will start the second phase, which is to use the sensor in the MDEK1001 kit or use the sensor of Arduino Nano to implement gesture control. For example,raising your hand in that direction turns on the device in that direction, and lowering your hand in that direction turns off the device in that direction.

### Timeline:
- From the fifth week to the eighth week, we hope to be able to program the uwb device and complete the first phase when everything goes well.
- Starting from the eighth week, we will continue to improve the first phase, and at the same time we will start the second phase of development.

### Strengths and weakness, and future directions

### Contributions of each team member

### Final Report, PPT, Demo

### References
