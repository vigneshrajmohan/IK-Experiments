
#include <Servo.h>  // servo library

Servo servo1;  // servo control object
Servo servo2;  // servo control object
Servo servo3;  // servo control object
Servo servo4;  // servo control object


void setup()
{
  // We'll now "attach" the servo1 object to digital pin 9.
  // If you want to control more than one servo, attach more
  // servo objects to the desired pins (must be digital).

  // Attach tells the Arduino to begin sending control signals
  // to the servo. Servos require a continuous stream of control
  // signals, even if you're not currently moving them.
  // While the servo is being controlled, it will hold its 
  // current position with some force. If you ever want to
  // release the servo (allowing it to be turned by hand),
  // you can call servo1.detach().
  servo1.attach(6);
  servo2.attach(7);
  servo3.attach(8);
  servo4.attach(9);

  servo1.write(90);
  servo2.write(180);
  servo3.write(90);
  servo4.write(90);
}


void loop()
{
  int position;

  // To control a servo, you give it the angle you'd like it
  // to turn to. Servos cannot turn a full 360 degrees, but you
  // can tell it to move anywhere between 0 and 180 degrees.

  // Change position at full speed:


  // Change position at a slower speed:

  // To slow down the servo's motion, we'll use a for() loop
  // to give it a bunch of intermediate positions, with 20ms
  // delays between them. You can change the step size to make 
  // the servo slow down or speed up. Note that the servo can't
  // move faster than its full speed, and you won't be able
  // to update it any faster than every 20ms.

  // Tell servo to go to 180 degrees, stepping by two degrees



//  for(position = 0; position < 90; position += 2)
//  {
//    servo2.write(position);  // Move to next position
//    servo3.write(position*2);  // Move to next position
//    delay(20);               // Short pause to allow it to move
//  }
//
//  // Tell servo to go to 0 degrees, stepping by one degree
//
//  for(position = 90; position >= 0; position -= 1)
//  {                                
//    servo2.write(position);  // Move to next position
//    servo3.write(position*2);  // Move to next position
//    delay(20);               // Short pause to allow it to move
//  }


//  for(position = 180; position >= 0; position -= 1)
//  {                                
//    servo2.write(position);  // Move to next position
//    servo3.write(180-position);  // Move to next position
//    servo4.write(180-position);  // Move to next position
//    delay(20);               // Short pause to allow it to move
//  }
//  for(position = 180; position >= 0; position -= 1)
//  {                                
//    servo2.write(180-position);  // Move to next position
//    servo3.write(position);  // Move to next position
//    servo4.write(position);  // Move to next position
//    delay(20);               // Short pause to allow it to move
//  }
  servo1.write(120);  // Move to next position
  servo2.write(10);  // Move to next position

}
