#include <MadgwickAHRS.h>  //Include Data Fusion Library
#include <Arduino_LSM9DS1.h> //Include the library for 9-axis IMU
#include <string.h>


String rndm; // random string used to get rid of the first communication
int Tout; // needed to use millis()

Madgwick filter; //Instantiate a filter and do the data fusion

//define pin
#define LED_AN0 3  
#define LED_AN1 5  
 
//Define string length
#define MAX_STR_LEN 100 

char DataBuffer[MAX_STR_LEN];  //define char array
char delim[] = ","; // Delimiter
String DataStr = "";
String Header, ID1, Addr1, ID2, Addr2;
short Num;
float x1, y, z1, Dis1, x2, y2, z2, Dis2,old_Dis1; 
char AN0_Flag = 1, AN1_Flag = 1;
bool IMU_print_flag = 0;

//define varibles for IMU
float accel_x, accel_y, accel_z;
float gyro_x, gyro_y, gyro_z;
float roll, pitch, yaw;


void setup() {
  
  pinMode(LED_AN0,OUTPUT);
  pinMode(LED_AN1,OUTPUT);
  pinMode(LED3,OUTPUT);

  analogWrite(LED_AN0, 0);
  analogWrite(LED_AN1, 0);
  analogWrite(LED3, 0);

  Serial.begin(115200); // it could be different according to your arduino serial baud setup
  Serial1.begin(115200); // dwm1001 require 115200 baud as specified in Decawave guides
  Serial.println("Serial communication started");

  if (!IMU.begin()) //Initialize IMU sensor 
  { Serial.println("Failed to initialize IMU!"); while (1);}

  // Now we are going to send a reset command so that we know the initial state of the module
  Serial.println("Now a reset command is sent");
  Serial1.print("reset\r");
  // Wait for 2 seconds so that the reset has enough time to be actuated
  Tout = millis()+2000;
  while(Tout>millis());

  // Enter the SHELL mode pressing enter twice
  Serial.println("Sending SHELL mode commands");
  Serial1.write(0x0D); // send the first "Enter" to get into SHELL Mode
  Serial1.write(0x0D); // send the second "Enter" to get into SHELL Mode

  // Wait for some time to let the module enter into SHELL mode
  Tout = millis() +1500;
  while(millis()<Tout)
    rndm = Serial1.readString(); // Do nothing with what you just read
  
  // Pass the command you want according to the API guide
  //Serial.println("Passing the command lec");
  delay(200);
  Serial1.write(0x6C); //send "l"
  delay(200);
  Serial1.write(0x65); //send "e"
  delay(200);
  Serial1.write(0x63); //send "c"
  delay(200);
  Serial1.write(0x0D); //send "Enter"
  delay(200);
  Serial.println("Command successfully passed");
  delay(200);
}

void loop() 
{
  Receive_Data();  
  read_IMU();
  LED_Display();
}

void Receive_Data(void)
{
  if (Serial1.available())
  {
     DataStr = Serial1.readStringUntil(0x0D);
     if(DataStr.length() > 5)
     {
        Serial.println(DataStr);

        //String to character array, (string array, array length)
        DataStr.toCharArray(DataBuffer, MAX_STR_LEN);  
        Data_Decode(DataBuffer,delim,&Header,&Num,&ID1,&Addr1,&x1,&y,&z1,&Dis1,
                                                  &ID2,&Addr2,&x2,&y2,&z2,&Dis2);
        //print out the distance
        Serial.println(Dis1);  
        Serial.println(Dis2);
        //flag for IMU print, 
        IMU_print_flag = 1;
     }
  }

}

void Data_Decode(char *DataStr, char *delim, String *a, short *b, String *c, String *d, 
                                             float *e, float *f, float *g, float *h, 
                                             String *i, String *j, float *k, float *l, 
                                             float *m, float *n )
{
   char TmpStr[MAX_STR_LEN]; // request memory
   strcpy(TmpStr, DataStr);  //Copy the original string first, otherwise it will affect the original value
   //Extract string
   String aStr = String(strtok(TmpStr, delim)); 
   String bStr = String(strtok(NULL, delim)); 
   String cStr = String(strtok(NULL, delim)); 
   String dStr = String(strtok(NULL, delim)); 
   String eStr = String(strtok(NULL, delim)); 
   String fStr = String(strtok(NULL, delim)); 
   String gStr = String(strtok(NULL, delim)); 
   String hStr = String(strtok(NULL, delim)); 
   String iStr = String(strtok(NULL, delim)); 
   String jStr = String(strtok(NULL, delim)); 
   String kStr = String(strtok(NULL, delim)); 
   String lStr = String(strtok(NULL, delim)); 
   String mStr = String(strtok(NULL, delim)); 
   String nStr = String(strtok(NULL, delim)); 

   // Convert String to numeric value. If the conversion fails, it will be 0 or 0.0 and no error will be reported
   *h = hStr.toFloat();
   *n = nStr.toFloat();
}

void read_IMU()
{
  // Accelerometer values 
  if (IMU.accelerationAvailable()) 
  {
    IMU.readAcceleration(accel_x, accel_y, accel_z);
  }
  //Gyroscope values 
  if (IMU.gyroscopeAvailable()) 
  {
    IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
  }
  //data fusion
  filter.updateIMU(gyro_x, gyro_y, gyro_z, accel_x,  accel_y, accel_z);
  //Get the values of roll, pitch and yaw
  roll = filter.getRoll(); 
  pitch = filter.getPitch();  
  yaw = filter.getYaw();
  //print out the values
    if( IMU_print_flag == 1 )
    {
    Serial.println("Accelerometer = "+String(accel_x)+", "+String(accel_y)+", "+String(accel_z));
    Serial.println("Gyroscope =  "+String(gyro_x)+", "+String(gyro_y)+", "+String(gyro_z));
    Serial.println("roll = "+String(roll)+", "+"pitch = "+String(pitch)+", "+"yaw = "+String(yaw));
    IMU_print_flag = 0;
  }
}

void LED_Display(void)
{
  if (Dis1 - old_Dis1 > 0.2)  //Move from Anchor0 to Anchor1
  {
      analogWrite(LED_AN0, 0);
      analogWrite(LED_AN1, 30);
      AN0_Flag = 0;
      AN1_Flag = 1;
      old_Dis1 = Dis1;
  }
  else if (old_Dis1 - Dis1 > 0.2)  //Move from Anchor1 to Anchor0
  {
      analogWrite(LED_AN0, 30);
      analogWrite(LED_AN1, 0);
      AN0_Flag = 1;
      AN1_Flag = 0;
      old_Dis1 = Dis1;
  }
  if( roll>-90 && roll<90) 
  {
    if(AN1_Flag == 1)  
    {
      analogWrite(LED_AN0, 0);
      analogWrite(LED_AN1, 30+roll/2);   
    }
    if(AN0_Flag == 1)  
    {
      analogWrite(LED_AN1, 0);
      analogWrite(LED_AN0, 30+roll/2);   
    }
  }
}
