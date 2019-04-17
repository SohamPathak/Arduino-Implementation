# include <IRremote.h>

const int RECV_PIN = 3;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  
}

void loop()
{
  if(irrecv.decode(&results))
  {
    Serial.println(results.value,DEC);
    Serial.println(results.value,HEX);//ALTHOUGH NOT HEX
    irrecv.resume();
  }
}

