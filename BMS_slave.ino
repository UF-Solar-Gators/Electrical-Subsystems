//BMS_SLAVE CODE
//BMS Slave checks the voltage and temps of the connected parallel cells.
//    This communicates with the master device through a serial com loop
//    and an low true alarm bus. This will ensure operation for all faults.
//
///////////////////////////////////////////////////////////////////////////
//
//                            ___________
//                           |           |
//                       VCC | 1      14 | GND
//           Alarm 0 <-  PB0 | 2      13 | PA0 <-  Voltage
//           Alarm 1 <-  PB1 | 3      12 | PA1  -> Relay 
//           Alarm 3 <-  PB3 | 4      11 | PA2  -> TX
//           Alarm 2 <-  PB2 | 5      10 | PA3 <-  RX
//              LED  <-  PA7 | 6      9  | PA4 <-> SCL I2C
//           SDA I2C <-> PA6 | 7      8  | PA5  -  NC/GND
//                           |___________|
//
//  To use PB3 as an output, RSTDISBL = 0; (disables reset pin)



//init vars
//Thresholds
byte OV_thresh = 11110111;
byte UV_thresh = 10010100;
byte CV_thresh = 11110100;
byte LV_thresh = 10011111;
byte OT_thresh = 11111111;
byte SHUTDOWN  = 01110110;

//Pin Definitions
int pin_A0 = 2;
int pin_A1 = 3;
int pin_A2 = 5;
int pin_A3 = 4;
int pin_LED = 6;
int pin_SDA = 7;
int pin_SCL = 9;
int pin_RX = 10;
int pin_TX = 11;
int pin_Relay = 12;
int pin_V = 13;

//Pin Setup
pinMode(pin_A0, OUTPUT);
pinMode(pin_A1, OUTPUT);
pinMode(pin_A2, OUTPUT);
pinMode(pin_A3, OUTPUT);
pinMode(pin_LED, OUTPUT);
//SDA? - set up as I2C pin? or will be automatically when using I2C function
//SCL? - set up as I2C pin?
pinMode(pin_RX, INPUT);
pinMode(pin_TX, OUTPUT);
pinMode(pin_Relay, OUTPUT);
pinMode(pin_V, INPUT);

//setup code
void setup() 
{
  boolean normVol = false;
  boolean normTemp = false;

  
  //check avgVoltage (needs to be fast)
  //check maxTemp (needs to be fast) both less than .1s?
  byte alarm = checkStatus();
  //turn relay on
  if(alarm == 0){
    digitalWrite(RELAY, HIGH);
  //  turn on led 2s
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
  //  continue to loop
  //else
  //  blink led until power down
     else while(true){
        digitalWrite(led,HIGH);
        delay(500);
        digitalWrite(LOW);
        delay(500);
     }
     //Don't know how long you want it to blink
}

//body code
void loop()
{
  //check avgVoltage
  //check avgTemp, maxTemp
  //compare to thresholds (function that returns alarm array? bool array?)
  byte alarm checkStatus()
  //set alarm
  //flash led
}

//interrupts
//  if RX goes to 0
//    recieve data packets
//    take measurements
//    modify data packets
//    send data
//  if watchdogtimer reaches 0
//    reset

//functions
int16_t getVoltage(vPin,nMeas)
{
  int16_t voltageTotal = 0;
  int16_t voltageAvg = 0;
  for(i=0;i<nMeas;i++)
  {
    voltageTotal = voltageTotal + analogRead(vPin);
  }
  voltageAvg = voltageTotal/nMeas;
  return voltageAvg;
}
byte checkStatus(){
  byte alarm = 00000000;
  if(getVoltage < OV_thresh){
    alarm ^= (1<<3);
  }
  if(getVoltage > UV_thresh){
    alarm ^= (1<<2);
  }
  if(getVoltage > CV_thresh){
    alarm ^= (1<<1);
  }
  if(getVoltage < LV_thresh){
    alarm ^= (1<<0);
  }
  return alarm;
}

void getTemp(tPin1,tPin2, temperature[])
{
  //get temperature sensor data
  //convert to array of each temp (?)
  //find maxTemp and avgTemp
  //temperature[0] = maxTemp
  //temperature[1] = avgTemp
}
