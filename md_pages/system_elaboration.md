[< Back to main page](../README.md)

# System Elaboration
#### ECE M202A Project: UWB Indoor Positioning - Select & Control
Contribute: Jiacheng Liu, Yibo Wang

--------------------------------------------------------------------------------------------

 This System elaboration part is created due to the hardware limitation and time constraints. During the development period of this project, we went through some prior works and researches. And as we became more familiar with the topic, we had come up with some thoughts about other configurations of the system to achieve device pointing/selection and control. So we would like to also elaborate on these ideas even though we are not able to accomplish them due to hardware and time constraints.  

--------------------------------------------------------------------------------------------
### System Elaboration 1: UWB pointing algorithm with pointing action detection
When using the IMU sensor, the gesture information can be captured and detected using the algorithm. In the project, we only implement a simple version that takes in the IMU reading and performance control by rotating the wrist. However, the same reading can be implemented to recognized more detailed gestures. This can also be found in the research work: <a target="_blank" rel="noopener noreferrer" href="https://ieeexplore.ieee.org/abstract/document/8794399?casa_token=mkVaeL30YWMAAAAA:s9q46eLkfBQ_P8N6tYBvj55Rd_mhBdiHOPmi6DS4oKErZPmEMDnnfxCzdTz5HrS7ltcLuyWrfQ" >Proximity Human-Robot Interaction Using Pointing Gestures and a Wrist-mounted IMU</a>. In this work, the interaction between human and robot is triggered when the system detect pointing action from the IMU sensor data. Also, in many other works, the IMU sensor is proved to be capable to decting complexed action such as pointing (which we can expressed as lifting arm and and straighten arm, etc.). Many of them require machine learning to perform the dection. 

So we can potentially apply a similar concept to our project. Use an algorithm to detect if a pointing action is performed and triggers the device selection. Adding more detailed gesture command to the system to achieve more robust performance.

Also, including the voice recognition command could also increase the usability of the system. The more feature/device vision we add the better the device can understand human's intention. But the difficulty of grouping all those data and make use of them could be high. 

--------------------------------------------------------------------------------------------
### System Elaboration 2: Improve UWB pointing with depth camera embedded
We also think about adding cameras to our system, which will serve as both uses. 

One is detecting the pointing action more accurately, maybe using a machine learning algorithm, we will be able to detect if the user is making a pointing action or not, this will act as a double confirmation of the action detection and making sure the user is pointing. An idea of action detection using a depth camera can be found: <a target="_blank" rel="noopener noreferrer" href="https://patents.google.com/patent/US20130077820A1/en" >Machine learning gesture detection</a>.

Second, the depth camera can also serve as a measurement tool, since it also able to measure some spatial information, so we are thinking maybe the camera can serve as supportive data for the UWB's positioning ability and increase the accuracy of the indoor positioning function. Also, one more thing is that we can use the depth to measure the relative length of the arm and the body, so we can plot a vector in the 3D space to make the pointing action more real and visualabe. 

--------------------------------------------------------------------------------------------
### System Elaboration 3: Pointing system with trace tracking for motion radius calculation

Tracing the position of the UWB tag can be useful, the system can store the data up to a certain period of time in history, which can be analyzed if a pointing action is performed. The system can go back to a certain limit of time and figure out the direction that the user trying to point at without any help from other sensors. Base on this we can train a neural network so that the "server/controller" can estimate the action and the rotation of the arm, shoulder, and body. Then we can recognize if the pointing is a whole arm lift or a forearm pointing. And based on the daily use, we can improve the system's accuracy/robustness by learning the body behavior of the particular user. 

--------------------------------------------------------------------------------------------
### System Elaboration 4: UWB robustness improvement with IMU sensor fusion
In this project, we already implement the idea of fusion into the handling of the IMU sensor. The next question is maybe based on all the different types of fusion methods we covered in lectures, there may be better performance methods out there. So, the next step, if time is permissible,  can spend some time improving the fusion algorithm and to achieve better robustness of the overall performance.

--------------------------------------------------------------------------------------------
### System Elaboration 5: UWB poinitng assist wireless data transmission (Application)
Another area that UWB technology that is powerful is data transmission. Ultra-Wide Band tends to operate at very low energy and support many users at high data rates <a target="_blank" rel="noopener noreferrer" href="https://dspace.mit.edu/bitstream/handle/1721.1/66898/Win-2009-History%20and%20applications%20of%20UWB.pdf?sequence=1&isAllowed=y" >History and Applications
of UWB</a>. Also since the wide bandwidth and low power feature, the UWB's communication tends to be harder to detect <a target="_blank" rel="noopener noreferrer" href="https://www.itu.int/dms_pubrec/itu-r/rec/sm/R-REC-SM.1755-0-200605-I!!PDF-E.pdf" >Characteristics of ultra-wideband technology </a>. 

These features open another area of our project's application. Based on our current system, we can design another data transfer system based on the pointing system. In this is achieved, we can point to two or even multiple devices to select them and start data transfer through UWB network without going through the manual pair up process in Wifi/Bluetooth devices. Removing the manual pair up process that could be a little different base on devices, we just point to the devices and say "transfer the files", the system will recognize what are the devices I'm pointing.  Then set up and perform the data transmission with all the benefits mentioned above. Also, the voice command can serve as the authentication based on the voice recognition technology to make the system more secure. 

--------------------------------------------------------------------------------------------
[< Back to main page](../README.md)