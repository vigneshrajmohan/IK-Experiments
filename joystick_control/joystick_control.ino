#include <Servo.h>

Servo l1;
Servo l2;
Servo base;
Servo top;

// Arduino pin numbers
const int SW_pin = 11; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
double x = 0;
double y = 5;
double spin = 0;
double beak = 0;

void setup() {
  l1.attach(7);
  l2.attach(8);
  base.attach(6);
  top.attach(9);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  double l1_len = 3;
  double l2_len = 3;
//  double x = 0;
//  double y = 5;

  if (analogRead(X_pin) > 1000 && analogRead(Y_pin) > 1000 && spin < 180){
    spin += 2;
  } else if (analogRead(X_pin) > 1000 && analogRead(Y_pin) < 100 && spin > 0){
    spin -= 2;
  } else if (analogRead(X_pin) > 1000 && x < 5){
    x += 0.1;
  } else if (analogRead(X_pin) < 100 && x > -5){
    x -= 0.1;
  } else if (analogRead(Y_pin) > 1000 && beak < 180){
    beak += 2;
  } else if (analogRead(Y_pin) < 100 && beak > 0){
    beak -= 2;
  }
  //IK is wrong for this robot (have to account for 90 degree offset of third joint)
  double theta2 = acos((x*x+y*y - l2_len*l2_len - (l1_len*l1_len))/(2*l2_len*l1_len));
  theta2 = -1* theta2;
  double theta1 = atan2(y,x)-atan2(l2_len*sin(theta2),l1_len+l2_len*cos(theta2));
  theta2 = theta2*(180/3.141592658979323)-90;
  
  theta2 = -1* theta2;
  theta1 = theta1*(180/3.141592658979323);
  l1.write(theta1);
  l2.write(theta2);
  base.write(spin);
  top.write(beak);

  delay (20);
  Serial.println(theta1);
  Serial.println(theta2);
  Serial.println("---------");

  
}
