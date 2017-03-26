//BMS_SLAVE CODE
//init vars
byte OV_thresh = 11110111;
byte UV_thresh = 10010100;
byte CV_thresh = 11110100;
byte LV_thresh = 10011111;
byte
int led = ;
int vPin = ;
int tPin1 = ;
int tPin2 = ;
int RELAY = ;
//setup code
void setup() 
{
  boolean normVol = false;
  boolean normTemp = false;
  //initialize port direction DDRB DDRA
  DDRA = ;
  DDRB = 00001111;
//  pinMode(led, OUTPUT);
//  pinMode(alarm0, OUTPUT);
//  pinMode(alarm1, OUTPUT);
//  pinMode(alarm3, OUTPUT);
//  pinMode(alarm4, OUTPUT);
//  pinMode(vPin, INPUT);
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
  int16_t voltageTotal
  int16_t voltageAvg
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
