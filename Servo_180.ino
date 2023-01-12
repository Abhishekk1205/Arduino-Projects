#include <Servo.h>
Servo riy;
void setup()
{
  riy.attach(9);
  riy.write(180);
}
void loop()
{
  for(int i=0;i<180;i++){riy.write(i); delay(10);}
  for(int i=180;i>0;i--){riy.write(i); delay(10);}
}
