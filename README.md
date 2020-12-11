# UWB_Select
## ECE M202A Project Proposal: UWB Indoor Positioning - Select & Control

Contribute: Jiacheng Liu, Yibo Wang\
UCLA M202A Project Implementing UWB wireless indoor position: select &amp; control IOT Devices
<img src="General Pics/UWB.jpg" class="img-responsive" alt="">

<!---
### Link:
  [link to test.md](md_files/test.md)
  <img src="General Pics/MDEK1001_600x430.jpg" class="center" alt="UWB: Decaewave MDEK1001 Evaluation Kit" width="50%" height="50%">
--->

### Background:
  At present, with the development of technology, indoor positioning scenes are becoming larger and more complex, and the demand for positioning and navigation in large supermarkets, general hospitals, airports, parking lots and other places is gradually increasing. There are many wireless positioning technologies and solutions. Commonly used positioning technologies include infrared, ultrasonic, and radio frequency signals, but they are not suitable for indoor positioning.
  There are currently different indoor positioning technologies, such as WiFi positioning technology, Bluetooth, RFID (Radio-frequency identification) and UWB (Ultra Wide-band). 

--------------------------------------------------------------------------------------------
### Motivation of Using UWB Indoor Positioning Technology
  WiFi, RFID and Bluetooth indoor positioning technologies have their own advantages, but at the same time they also have some limitations and disadvantages. 
  As for the WiFi, it is easily interfered by other signals. This affects the positioning accuracy, the accuracy is not high, and the energy consumption of the positioner is high.  RFID does not have communication capabilities and has poor anti-interference capabilities, which is not easy to integrate into other systems, and the user's security and privacy protection and international standardization are not perfect.Under complex space environments, the stability of the Bluetooth system is slightly worse than other technologies, and it is greatly interfered by noise signals. Also, the price of Bluetooth devices and equipment is relatively expensive.
  Ultra-wideband indoor positioning uses UWB pulse signals, and multiple sensors use TDOA and AOA positioning algorithms to analyze the tag position. The multi-path resolution capability is high, the accuracy is high, and the positioning accuracy can reach sub-meter level.
  UWB does not need to use the carrier wave in the traditional communication system, but transmits and receives extremely narrow pulses with nanoseconds or less to transmit data, so it has a bandwidth of GHz order. Because the ultra-wideband positioning technology has the advantages of strong penetration, good anti-multipath effect, high security, low system complexity, and ability to provide precise positioning accuracy.
  Technically, UWB indoor positioning is undoubtedly one of the most ideal industrial positioning technologies, whether it is analyzed from the perspective of positioning accuracy, safety, anti-interference, and power consumption.

--------------------------------------------------------------------------------------------
### Project Introduction
  At present, the accuracy of indoor positioning is insufficient in many technologies. However, UWB has great advantages in positioning accuracy. So we chose UWB as the positioning technology for our project. We want to use UWB to locate and then realize some control commands through location recognition. Now most of the control commands indoors are realized through voice recognition or image recognition. 
  
  At the same time, there's a problem when controlling IoT stuff: if we can recognize the pointing action, then that will sufficiently increase the robustness of controls. Also, we can combine it with voice or gesture commands to make things smarter and easier. 
  
  This project will implement the spatial information from the UWB system and combine them with the IMU sensors on Arduino BLE Sense 33, to achieve pointing action detection, gesture commands. This will enable the device selection & controls.

-----------------------------------------------------------------------------------------------
### Prior works
  Direct works: 
  1. <a target="_blank" rel="noopener noreferrer" href="https://amir-omidfar.github.io/m202Fall19/index.html" >DirectMe</a>
  
  Relavant works:
  1. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/5307895" >Recent trends and advances in UWB positioning</a>
  2. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/5288724?casa_token=NWJVDTZtLEYAAAAA:u0bZ2adB4zLXbtTXZWLx7NVZWMv8oI2souPsLrFrAH5uT4O-Qa4OzrW8iNKWowLi33HD9fi_AA" >Tightly coupled UWB/IMU pose estimation</a>
  3. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/8704208" >Hand Pointing Gestures Based Digital Menu Board Implementation Using IR-UWB Transceivers</a>
  4. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/8115911?casa_token=JJNFts0cGBsAAAAA:Wt09R6HAsEaV3kjVUAhvm-8qDWjbJTaBcqoz7b9e3nJdBDOl-CySC6k9LJKyChOVPp184LXrcQ" >An integrated IMU and UWB sensor based indoor positioning system</a>
  5. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/4653423?casa_token=PNeCFB14aPUAAAAA:BhmnRVjNvpyNLEirOgUv8XrWC5PPzRbsBRE3S9wXVQ-uF6edXcL7Z24edvbWMPKsv41gAYBS4w" >Hybrid localization using UWB and inertial sensors</a>

--------------------------------------------------------------------------------------------
### Implementation of project
  Our project basically has two phases. The first phase is to achieve our basic goals. We will use Decawave MDEK1001 Development Kit as our main development tool. The kit includes 12 RTLS units base on DWM1001 Development board, embedded location stack (binary) and gateway firmware.
  
  <div style="text-align:center">
    <figure>
      <img src="General Pics/MDEK1001_600x430.jpg" alt="" width="50%" height="50%" />
      <figcaption>UWB: Decaewave MDEK1001 Evaluation Kit</figcaption>
  </figure>
</div>

  We can use some of the RTLS units to be anchors and use 1 RTLS unit to be a tag. By using the tag twice to obtain the location of the two points, the two points will form a vector, which will be recognized by uwb and then find the corresponding device to perform the control command. For the first phase, we only want to turn on/turn off of the devices in different position.
  If we successfully complete the first phase, we will start the second phase, which is to use the sensor in the MDEK1001 kit or use the sensor of Arduino Nano to implement gesture control. For example,raising your hand in that direction turns on the device in that direction, and lowering your hand in that direction turns off the device in that direction.

--------------------------------------------------------------------------------------------
### Timeline:
- From the fifth week to the eighth week, we hope to be able to program the uwb device and complete the first phase when everything goes well.
- Starting from the eighth week, we will continue to improve the first phase, and at the same time we will start the second phase of development.

--------------------------------------------------------------------------------------------
### Strengths and weakness, and future directions

--------------------------------------------------------------------------------------------
### System elaboration

--------------------------------------------------------------------------------------------
### Contributions of each team member

--------------------------------------------------------------------------------------------
### Final Report, PPT, Demo

--------------------------------------------------------------------------------------------
### References
