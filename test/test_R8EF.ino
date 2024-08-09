// A program for reading pulse sent from R8TB transfer to R8EF receiver

unsigned long durationCH1;
unsigned long durationCH2;
unsigned long durationCH3;
unsigned long durationCH4;
unsigned long durationCH5;
unsigned long durationCH6;
unsigned long durationCH7;
unsigned long durationCH8;

#define TIME 1000000

void setup() {
  // put your setup code here, to run once:
  // CH1 - CH4 and CH6, CH8
  for(int i = 14; i < 20; ++i) {
    pinMode(i, INPUT);
  }

  pinMode(4, INPUT);  // CH5(SWB)
  pinMode(7, INPUT);  // CH7(SWA)

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Works on pulses from 10 microseconds to 3 minutes in length.
  // Returns the length of the pulse in microseconds or gives up and returns 0 if no complete pulse was received within the timeout.
  // pulseIn(pin, value, timeout)
  // pin: the number of the Arduino pin on which you want to read the pulse. Allowed data types: int.
  // value: type of pulse to read: either HIGH or LOW. Allowed data types: int.
  // timeout (optional): the number of microseconds to wait for the pulse to start; default is one second. Allowed data types: unsigned long.
  // Returns - The length of the pulse (in microseconds) or 0 if no pulse started before the timeout. Data type: unsigned long.

  // timeout - 100 microsecond
  durationCH1 = pulseIn(14, HIGH, TIME);
  durationCH2 = pulseIn(15, HIGH, TIME);
  durationCH3 = pulseIn(16, HIGH, TIME);
  durationCH4 = pulseIn(17, HIGH, TIME);
  durationCH6 = pulseIn(18, HIGH, TIME);
  durationCH8 = pulseIn(19, HIGH, TIME);
  durationCH5 = pulseIn(4, HIGH, TIME);
  durationCH7 = pulseIn(7, HIGH, TIME);

  Serial.print("CH1 = ");
  Serial.println(durationCH1);

  Serial.print("CH2 = ");
  Serial.println(durationCH2);

  Serial.print("CH3 = ");
  Serial.println(durationCH3);

  Serial.print("CH4 = ");
  Serial.println(durationCH4);

  Serial.print("CH6 = ");
  Serial.println(durationCH6);

  Serial.print("CH8 = ");
  Serial.println(durationCH8);

  
  Serial.print("CH5 = ");
  Serial.println(durationCH5);

  Serial.print("CH7 = ");
  Serial.println(durationCH7);
}
