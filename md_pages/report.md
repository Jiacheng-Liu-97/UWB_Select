[< Back to main page](../README.md)

# Fianl Report
#### ECE M202A Project: UWB Indoor Positioning - Select & Control
Contribute: Jiacheng Liu, Yibo Wang

--------------------------------------------------------------------------------------------

### System components: 
 1. **Decawave DWM 1001 units:** We use the Decawave MDEK1001 Development Kit as our positioning tool. The Kit includes 12 RTLS units (DWM1001)  and we use several of the DWM1001 to be anchors and use 1 RTLS unit to be a tag. This system will measure the distance of all anchors to this specific tag.
 2. **J-Link driver & Terminal in Mac OS/Android App:** The J-Link is a driver to make DWM1001 can be configured on the computer. Terminal/Android App is the interface to configure the basic information of tag and anchors. The basic information includes the initial position of anchors, UWB states, and update rate.
 3. **Arduino Nano 33 BLE sense:** We use Arduino to communicate with DWM1001 through the serial port to obtain the real-time position information of the anchors. Then we use Arduino to perform calculations to determine our choice in order to turn on or off the corresponding LEDs.
 4. **Breadboard & LEDs:** the function of the breadboard and LED is to visualize the results of our data analysis and calculations.

   <p align="center">
    <img src="pics/system_overview.png" alt="System_Overview" width="100%" height="100%" />
  </p>
  
  Our project is mainly divided into two parts. The first part is the implementation of  UART communication between Tag and Arudino. And the second part is using a built-in IMU sensor of Arduino to do the gesture control.

--------------------------------------------------------------------------------------------
### Part I: UART Communication between Tag and Arduino
   **Implementation procedures:**
   1. Doing the configuration of Tag and Anchors using Terminal/Andriod app.
   2. Using terminal with specific commands to observe the data format.
   3. Coding on Arduino to obtain and process data, and then use the processed data to do some calculations to achieve our selection function.
   4. Using a breadboard to build a simple circuit to visualize the results.
   **Schematic diagram:**
   <p align="center">
      <img src="pics/serial_communication.png" alt="Serial Communication" width="100%" height="100%" />
   </p>

  #### Technical Approach:
  1. Configure the Anchors and Tag in terminal
  
  Find the name of the serial port and then use the screen to connect to the serial

  ```
  ls /dev/cu.*
  screen /dev/tty.usbmodem14331 115200
  ```

  Then using the Decawave API firmware API Guide to find the commands to configure the Anchors and Tag

--------------------------------------------------------------------------------------------




[< Back to main page](../README.md)