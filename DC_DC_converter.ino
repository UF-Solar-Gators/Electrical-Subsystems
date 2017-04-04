//DC-DC converter code
//init vars

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif 


//setup code
void setup() 
{
  //initialize ports
}

//body code
void loop()
{

}

//interrupts


//functions
void function()
{

}
