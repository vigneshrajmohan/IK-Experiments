#include <Servo.h>

Servo l1;
Servo l2;

int input;
void setup()
{
  l1.attach(7);
  l2.attach(8);
  Serial.begin(9600);
}

void loop() {
  double l1_len = 3;
  double l2_len = 3;
  double x = 0;
  double y = 3;

  double position;
  for(position = 5; position >= -5; position -= 0.1)
  { 
    x = (double)position;
    double theta2 = acos((x*x+y*y - l2_len*l2_len - (l1_len*l1_len))/(2*l2_len*l1_len));
    double theta1 = atan2(y,x)-atan2(l2_len*sin(theta2),l1_len+l2_len*cos(theta2));
    theta2 = theta2*(180/3.141592658979323)-90;
    theta2 = -1* theta2;
    theta1 = theta1*(180/3.141592658979323);
    l1.write(theta1);
    l2.write(theta2);
    delay (20);
  }
    for(position = -5; position <= 5; position += 0.1)
  { 
    x = (double)position;
    double theta2 = acos((x*x+y*y - l2_len*l2_len - (l1_len*l1_len))/(2*l2_len*l1_len));
    double theta1 = atan2(y,x)-atan2(l2_len*sin(theta2),l1_len+l2_len*cos(theta2));
    theta2 = theta2*(180/3.141592658979323)-90;
    theta2 = -1* theta2;
    theta1 = theta1*(180/3.141592658979323);
    l1.write(theta1);
    l2.write(theta2);
    delay (20);
  }
}
