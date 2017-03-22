# Electrical-Subsystems
Repository for the development of Arduino code. This covered the BMS, MPPT, Motor Controller, DC-DC converters, and potentially AC Charger.

#### NEEDED PROGRAMS<br />
  ### -Battery Management Slave: <br />
      Reads: Voltage, Temperature 
      Receives: Voltage, Temperature (From Previous Arduino in Comm. loop) 
      Sends: Voltage, Temperature, and 4 Bit alarm signal signaling the state of the battery module 
  ### -Battery Management Master: <br />
      Receives: Data from battery pack  
      Reads: Current through battery pack 
      Sends: Strobe signal if tripped, LED control to cockpit, Data to other devices, Battery charging status  
 ###  -MPPT Board (Max Power Point Tracking):  <br />
      Read: Temperature, Current, Voltage  
      Send/Receive Data 
      Controls duty cycle 
 ### -DC-DC Converter  <br />
      Read Voltage  
      Output Voltage/duty cycle
 ### -Motor Controller  <br />
      Read: Throttle, Brake, Regenerative Braking, "Go Faster" Command, Quadratic Position (encoder?)
      output: 6 transistor driving signals

Author: Eric Brown
