# UWB_Select
## ECE M202A Project Proposal: UWB Indoor Positioning - Select & Control

Contribute: Jiacheng Liu, Yibo Wang\
UCLA M202A Project Implementing UWB wireless indoor position: select &amp; control IOT Devices
<img src="General Pics/UWB.jpg" class="img-responsive" alt="">

<!---
### Link:
  [link to test.md](md_pages/test.md)
  <img src="General Pics/MDEK1001_600x430.jpg" class="center" alt="UWB: Decaewave MDEK1001 Evaluation Kit" width="50%" height="50%">
--->

### Background:
  At present, with the development of technology, indoor positioning scenes are becoming larger and more complex, and the demand for positioning and navigation in large supermarkets, general hospitals, airports, parking lots and other places is gradually increasing. There are many wireless positioning technologies and solutions. Commonly used positioning technologies include infrared, ultrasonic, and radio frequency signals, but they are not suitable for indoor positioning.
  There are currently different indoor positioning technologies, such as WiFi positioning technology, Bluetooth, RFID (Radio-frequency identification) and UWB (Ultra Wide-band). 

--------------------------------------------------------------------------------------------
### Motivation of Using UWB Indoor Positioning Technology
  WiFi, RFID, and Bluetooth indoor positioning technologies have their own advantages, but at the same time they also have some limitations and disadvantages. 
  
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
  2. <a target="_blank" rel="noopener noreferrer" href="http://www.guoanhong.com/papers/SUI19-Minuet.pdf" >Minuet: Multimodal Interaction with an Internet of Things</a>
  
### References
  1. <a target="_blank" rel="noopener noreferrer" href="https://decaforum.decawave.com/t/can-i-use-only-2-dwm1001-dev-and-see-their-relative-distance/7788" >Decaewave Q&A (1)</a>
  2. <a target="_blank" rel="noopener noreferrer" href="https://decaforum.decawave.com/t/uart-communication-with-arduino/5664" >Decaewave Q&A (2)</a>
  3. <a target="_blank" rel="noopener noreferrer" href="https://www.decawave.com/product/mdek1001-deployment-kit/" >MDEK1001 Configuration</a>
  4. <a target="_blank" rel="noopener noreferrer" href="https://nitinjsanket.github.io/tutorials/attitudeest/madgwick" >Mathematical Model of an IMU</a>
  5. <a target="_blank" rel="noopener noreferrer" href="https://axodyne.com/2020/06/arduino-nano-33-ble-ahrs/" >Arduino Nano 33 BLE – AHRS</a>
  6. <a target="_blank" rel="noopener noreferrer" href="https://www.researchgate.net/figure/Average-roll-pitch-and-yaw-angles_fig2_262055313" >Identifying Active Travel Behaviors in Challenging Environments Using GPS, Accelerometers, and Machine Learning Algorithms</a>
  7. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/5307895" >Recent trends and advances in UWB positioning</a>
  8. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/5288724?casa_token=NWJVDTZtLEYAAAAA:u0bZ2adB4zLXbtTXZWLx7NVZWMv8oI2souPsLrFrAH5uT4O-Qa4OzrW8iNKWowLi33HD9fi_AA" >Tightly coupled UWB/IMU pose estimation</a>
  9. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/8704208" >Hand Pointing Gestures Based Digital Menu Board Implementation Using IR-UWB Transceivers</a>
  10. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/8115911?casa_token=JJNFts0cGBsAAAAA:Wt09R6HAsEaV3kjVUAhvm-8qDWjbJTaBcqoz7b9e3nJdBDOl-CySC6k9LJKyChOVPp184LXrcQ" >An integrated IMU and UWB sensor based indoor positioning system</a>
  11. <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/4653423?casa_token=PNeCFB14aPUAAAAA:BhmnRVjNvpyNLEirOgUv8XrWC5PPzRbsBRE3S9wXVQ-uF6edXcL7Z24edvbWMPKsv41gAYBS4w" >Hybrid localization using UWB and inertial sensors</a>

--------------------------------------------------------------------------------------------
### Implementation of project
  Our project basically has two phases. The first phase is to achieve our basic goals. We will use Decawave MDEK1001 Development Kit as our main development tool. The kit includes 12 RTLS units base on DWM1001 Development board, embedded location stack (binary) and gateway firmware.
  
  <p align="center">
    <img src="General Pics/MDEK1001_600x430.jpg" alt="UWB: Decaewave MDEK1001 Evaluation Kit" width="50%" height="50%" />
  </p>

  We can use some of the RTLS units to be anchors and use 1 RTLS unit to be a tag. By using the tag twice to obtain the location of the two points, the two points will form a vector, which will be recognized by uwb and then find the corresponding device to perform the control command. For the first phase, we only want to turn on/turn off the devices in a different position.

  Due to the project's time constraint, we implement the positioning system by using its default firmware and to accomplish the communication using serial output. 
  
  The controlling unit (Arduino Nano BLE 33 Sense) serves as the central controller and read in the positioning data from the UWB tag and process it to determine the needed spatial information.
  
  Also, in the later part of the project, the IMU sensor from the Arduino was introduced. Combining the IMU's data, the system is able to recognize the gesture and perform "pointing + control". 

  Details of implementation will be on the report page.

--------------------------------------------------------------------------------------------
### Timeline:
- From the fifth week to the eighth week, we hope to be able to program the uwb device and complete the first phase when everything goes well.
  - Completed: Due to the hardware limitation we are unable to accomplish a perfect positioning system. The issue is caused by the insufficient guide of the evaluation kit and limited resources for communication with the kit to Arduino modules. However, thanks for the helps from professor and Julian, we are able to communicate to the UWB tag and received positioning data.

- Starting from the eighth week, we will continue to improve the first phase, and at the same time we will start the second phase of development.
  - Completed: Due to the time constraints and unknown error(s), we switched our focus from getting a perfect positioning system to embedded IMU data into the system. The data was successfully captured and evaluated. And We also successfully combined with the positioning data. We can say, in general, the overall goal is accomplished. As time writing this checkpoint message, we are still working on ways to improve the system's robustness. 
  - At this point, there is a lot more we can improve, and doing this project allows us to come up with many new ideas, which will be elaborate in the "System elaboration" and "Strengths and weakness, and future directions" sections.

--------------------------------------------------------------------------------------------
### Strengths and weakness, and future directions
**Strength:**
  1. **Accuracy:** The accuracy of UWB can reach the centimeter level, which is required for indoor positioning.
  2. **Low Power:** UWB is not only a positioning system, it also has the characteristics of low power and low latency. This is an excellent feature for embedded systems.
  3. **Multifunctional:** While realizing indoor positioning, we also added the function of gesture control based on the IMU sensor. This will make this device more robust and useful when we are indoors.

**Weakness:**
  1. We can only use two anchors at present due to potential serial communication problems between Tag and Arduino. This will make us temporarily not using the z-axis for calculations.
  2. The firmware of the UWB module itself has not been modified. After the modification, there will be more possibilities.

--------------------------------------------------------------------------------------------
### System elaboration
  Please click and view:
  [System elaboration](md_pages/system_elaboration.md)

--------------------------------------------------------------------------------------------
### Contributions of each team member
  - Jiacheng Liu:
     - Github repo and everything related the Github page.
     - Figure out how to set up and configure the UWB system. 
     - UWB-Arduino Communication
     - System and Algorithm Elabration
     - Report and Demo

  - Yibo Wang: 
     - Exploring the uwb data acquiring method
     - Coding the Arduino to integrate the overall system
     - Figure out how to acquire the built-in IMU sensor's data for gesture control
     - Implement the IMU sensor fusion function
     - Report and Demo

--------------------------------------------------------------------------------------------
### Final Report, PPT, Demo
  1. [Final_Report](md_pages/report.md)
