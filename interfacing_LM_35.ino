/*LM 35 is a temperature sensor which varies it's output as 10mv/C, Connecting the PIN1 (Vcc 4-30V) to 5V, PIN2 (Analog Output) to A0 of arduino, 
  PIN3 to GROUND, we can measure the temp change as voltage and later convert it into celsius by using ADC of arduino and by formula, temp in celsius
  = ADC_value*.488(conversion factor).
  Delay is provided by using a iterative function which calls no operation in the assembly language, for a delay of 50ms, 800000 cycles of iteration 
  is required, for 250ms 4000000 cycles and for 500ms 8000000 cycles is required for a 16MHZ clocked microcontroller

  //// BASIL BENNY mail:basilbenny404@gmail.com ////
 */

const int sensorPin = A0;
//Function to blink the LED 
void blinkLED()
{
   digitalWrite(LED_BUILTIN,HIGH);
   for (unsigned long i = 0; i < 800000; i++) {
    //delay of 50 ms
   asm volatile("nop");
  }
    digitalWrite(LED_BUILTIN,LOW);
  }
//Function to provide 250ms and 500ms delay
void callDelay(unsigned long d)
{
  //desired delay using nop
  for (unsigned long i = 0; i < d; i++) {
  asm volatile("nop");
  }
  }
void setup() {
  // put your setup code here, to run once:
   pinMode(LED_BUILTIN, OUTPUT); 
   pinMode(sensorPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempValue; //ADC value from LM35
  float temp;  //Temperature value from LM35
  tempValue = analogRead(sensorPin);
  temp = tempValue * 0.488; //0.488 is a typical conversion factor for LM35
  blinkLED();
  if(temp<30) //Checking if temperature is less than 30 deg C
  {
    callDelay(4000000);
    }
    else //if temperature is greater than 30 deg C
    {
    callDelay(8000000);
      }

}
