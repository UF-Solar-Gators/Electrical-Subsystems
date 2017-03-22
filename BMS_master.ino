//code for bms_master
//init vars

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
