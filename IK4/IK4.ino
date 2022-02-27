#include <Servo.h>

Servo l1;
Servo l2;
// Servo top;

// Arduino pin numbers
const int SW_pin = 11; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
double x = 0;
double y = 3;
double spin = 0;
//double beak = 90;

double theta2 = 0;
double theta1 = 0;

double px = 0;
double py = 5;
double ptheta1 = 0;
double ptheta2 = 0;
double step_size = 0.08;

void setup() {
  l1.attach(6);
  l2.attach(7);
//  top.attach(9);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
//  top.write(beak);
}

void loop() {
  double l1_len = 6;
  double l2_len = 5;
//  double x = -1;
//  double y = 6;

  px = x;
  py = y;
  ptheta1 = theta1;
  ptheta2 = theta2;

  if (analogRead(X_pin) > 700) {
    x -= step_size;
  } else if (analogRead(X_pin) < 300) {
    x += step_size;
  }
  if (analogRead(Y_pin) > 700) {
    y += step_size;
  } else if (analogRead(Y_pin) < 300) {
    y -= step_size;
  }

  theta2 = acos((x * x + y * y - l2_len * l2_len - (l1_len * l1_len)) / (2 * l2_len * l1_len));

  theta1 = atan2(y, x) - atan2(l2_len * sin(theta2), l1_len + l2_len * cos(theta2));
  theta2 = 180 - theta2 * (180 / 3.141592658979323);
  
  theta1 = theta1 * (180 / 3.141592658979323);

  if (isnan(theta1) || isnan(theta2) || theta1 < 0 || theta2 < 0 || theta1 > 180 || theta2 > 180) {
    x = px;
    y = py;
    theta1 = ptheta1;
    theta2 = ptheta2;
  }

  l1.write(theta1);
  l2.write(theta2);


  delay (5);
  
  Serial.println(x);
  Serial.println(y);
  Serial.println("---------");


}
