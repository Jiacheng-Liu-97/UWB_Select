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


[< Back to main page](../README.md)