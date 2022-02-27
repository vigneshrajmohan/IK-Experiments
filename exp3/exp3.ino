#include <Servo.h>

Servo l1;
Servo l2;

int input;
void setup()
{
  l1.attach(6);
  l2.attach(7);
  Serial.begin(9600);
}

void loop() {
  double l1_len = 15.5;
  double l2_len = 13;
  double x = 0;
  double y = 9;
  if (Serial.available() > 0) {
    input = Serial.parseInt();
    if (input != 0){
      x = (double)input;
      double theta2 = acos((x*x+y*y - l2_len*l2_len - (l1_len*l1_len))/(2*l2_len*l1_len));
      double theta1 = atan2(y,x)-atan2(l2_len*sin(theta2),l1_len+l2_len*cos(theta2));
      theta2 = theta2*(180/3.14)-90;
      theta2 = -1* theta2;
      theta1 = theta1*(180/3.141592658979323);
      l1.write(theta1);
      l2.write(theta2);

      Serial.println(theta1);
      Serial.println(theta2);
      Serial.println(input);
      Serial.println("----");
    }
    delay (1000);
  }
}
