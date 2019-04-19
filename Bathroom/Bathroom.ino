int relay1 = 2;                   // Initialize pin no.
int relay2 = 3;
int pir1 = 11;
int pir2 = 12;
int i;
void setup()
{
 pinMode(relay1,OUTPUT);         // Define pin mode
 pinMode(relay2,OUTPUT);
 pinMode(pir1,INPUT_PULLUP);
 pinMode(pir2,INPUT_PULLUP);
 Serial.begin(9600);
}

void loop() 
{
  digitalWrite(relay1,LOW);        // Initially turn off relay
  digitalWrite(relay2,LOW);
 if(digitalRead(pir1)==HIGH)       // If pir1 detects motion
 {
  digitalWrite(relay1,HIGH);       // Turn On Relay 1
  Timer();  
 }
 if(digitalRead(pir2)==HIGH)        // If pir2 detects motion
 {
  digitalWrite(relay2,HIGH);        // Turn On Relay 2
  Timer();  
 }
 else
 {
  digitalWrite(relay1,LOW);       // No motion detected turnn off both relays
  digitalWrite(relay2,LOW);
 }
}
void Timer()
{
  for(i=0;i<=500;i++)
  {
    if(digitalRead(pir1)==HIGH)
    {
      digitalWrite(relay1,HIGH);
      i = 0;
    }
    if(digitalRead(pir2)==HIGH)
    {
      digitalWrite(relay2,HIGH);
      i = 0;
    }
    Serial.println(i);
    Serial.print(digitalRead(pir1));
    Serial.print(" ");
    Serial.print(digitalRead(pir2));
    delay(100);
  }
}

