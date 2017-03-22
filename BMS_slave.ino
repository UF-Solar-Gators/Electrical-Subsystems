//BMS_SLAVE CODE
//init vars

//setup code
void setup() 
{
  //initialize port direction DDRB DDRA
  //check avgVoltage (needs to be fast)
  //check maxTemp (needs to be fast) both less than .1s?
  //if normal operation
  //  relay on
  //  turn on led 2s
  //  continue to loop
  //else
  //  blink led until power down
}

//body code
void loop()
{
  //check avgVoltage
  //check avgTemp, maxTemp
  //compare to thresholds (function that returns alarm array? bool array?)
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
    voltageTotal = voltageTotal + analogRead(nMeas);
  }
  voltageAvg = voltageTotal/nMeas;
  return voltageAvg;
}

void getTemp(tPin1,tPin2, temperature[])
{
  //get temperature sensor data
  //convert to array of each temp (?)
  //find maxTemp and avgTemp
  //temperature[0] = maxTemp
  //temperature[1] = avgTemp
}
