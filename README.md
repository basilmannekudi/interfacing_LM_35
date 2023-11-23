LM 35 is a temperature sensor which varies it's output as 10mv/C, Connecting the PIN1 (Vcc 4-30V) to 5V, PIN2 (Analog Output) to A0 of arduino, 
  PIN3 to GROUND, we can measure the temp change as voltage and later convert it into celsius by using ADC of arduino and by formula, temp in celsius
  = ADC_value*.488(conversion factor).
  Delay is provided by using a iterative function which calls no operation in the assembly language, for a delay of 50ms, 800000 cycles of iteration 
  is required, for 250ms 4000000 cycles and for 500ms 8000000 cycles is required for a 16MHZ clocked microcontroller
