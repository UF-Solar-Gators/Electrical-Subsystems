//BMS_MASTER CODE
//BMS Slave checks the current of the battery pack as well as the status of
//    all connected parallel groups. This also controls the contactors and
//    communicates will all other devices using a CAN interface. The CAN
//    code can be found in the CAN bus folder or at
//    https://github.com/sparkfun/SparkFun_CAN-Bus_Arduino_Library
//
///////////////////////////////////////////////////////////////////////////
//
//                            ___________
//                           |           |
//                    -  PC6 | 1      28 | PC5  -
//                RX  -> PD0 | 2      27 | PC4  -  
//                TX <-  PD1 | 3      26 | PC3  -   
//                    -  PD2 | 4      25 | PC2  -  
//                    -  PD3 | 5      24 | PC1  -  
//                    -  PD4 | 6      23 | PC0 <-  Current
//                       VCC | 7      22 | GND
//                       GND | 8      21 | AREF
//                    -  PB6 | 9      20 | AVCC          _
//                    -  PB7 | 10     19 | PB5  -  SCK    |
//           Alarm 0  -  PD5 | 11     18 | PB4  -  MISO   |  CAN Bus SPI Communication
//           Alarm 1  -  PD6 | 12     17 | PB3  -  MOSI   | 
//           Alarm 2  -  PD7 | 13     16 | PB2  -  SS    _|
//           Alarm 3  -  PB0 | 14     15 | PB1  -        
//                           |___________|
//
//  To use PC6 as an output, RSTDISBL = 0; (disables reset pin)



//init vars
//Thresholds

//setup
//void setup()
{
  //initialize port directions DDRA DDRB DDRC DDRD
  //startup bms
  //  send power on signal to slave devices
  //  start timer (~2s timer)
  //  check current (should be 0 at startup)
  //  when timer reaches 0
  //    send starting communication signal
  //    check response
  //    check alarms
  //  if response alarms and current all good
  //    engage contractors
}

void loop()
{
  //check alarms
  //check current
  //if not good
  //  turn off contractor
  //  turn on strobe
  //  turn on bps indicator
  //  communicate over CAN bus shutdown
  //else
  //  chill? Communicate status?
}

//interrupts
//  if rx goes to 0
//    recieve data
//    check data
//    if data good
//      send next communication
//    else
//      check alarms
//      if bad or badcomm = 1, shutdown // if alarms and communication bad or 2 bad communications in a row, shutdown
//      else if good and badcomm = 0
//        badcomm=1
//        send data again
