#define light_reader 2
#define l0 4
#define l1 3
#define l2 7
#define l3 17
#define buzzer 11
#define btn 13
#define btn2 10

#include<math.h>
#include <vector>
std:: vector<int> numbers;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(l0, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(light_reader,INPUT);
  pinMode(btn, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  
}

int scaler(int value) {
  return round(15*value/4096);
}
int reverse_scaler(int value) {
  return (4096/15*value);
}

int max_potency(int value) {
  int n=0;
  while (pow(2,n)<=value) {
    n ++;
  }
  return n-1;
}

std:: vector<int> binary(int value) {
  std:: vector<int> values = {0,0,0,0};
  while (!value ==0) {
    values[max_potency(value)] = 1;
    value -= pow(2,max_potency(value));
  }
  return values;
}

void led_buzzer_control(int intensity,std::vector<int> p) 
  {
    if (p[0]==1) {
    digitalWrite(l0, HIGH);
  }
  if (p[0]==0) {
    digitalWrite(l0, LOW);
  }
  if (p[1]==1) {
    digitalWrite(l1, HIGH);
  }
  if (p[1]==0) {
    digitalWrite(l1, LOW);
  }
  if (p[2]==1) {
    digitalWrite(l2, HIGH);
  }
  if (p[2]==0) {
    digitalWrite(l2, LOW);
  }
  if (p[3]==1) {
    digitalWrite(l3, HIGH);
  }
  if (p[3]==0) {
    digitalWrite(l3, LOW);
  }

  tone(buzzer,1000*scaler(intensity));

}

void loop() {
  int intensity = scaler(analogRead(light_reader));
  std::vector p =binary(intensity);
  led_buzzer_control(intensity,p);if(digitalRead(btn2)) {
    for (int k=0;k<numbers.size();k++) {

      led_buzzer_control(reverse_scaler(numbers[k]),binary(numbers[k]));
      
      delay(500);
      tone(buzzer,0*scaler(intensity));

      digitalWrite(l3, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(l1, LOW);
      digitalWrite(l0, LOW);
    }
    numbers.clear();
  }
}
