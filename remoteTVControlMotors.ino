#include <AFMotor.h>
// Version 3.9.0
#include <IRremote.h>

#define IR_RECEIVE_PIN A0

// PANASONIC TV
#define up  0
#define down  0
#define left  0
#define const 0
#define stop  0

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);


int Speed = 235;
int received_command = 0;


void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  Serial.println("Lets testing...");
   IrReceiver.begin(IR_RECEIVE_PIN);

}

void loop() {
  if(IrReceiver.decode()) { 
    
    received_command = IrReceiver.decodedIRData.command;
    Serial.println(received_command); //Integer
    IrReceiver.resume();
  } 

  delay(100);
 
  // motor2.run(BACKWARD);
  // motor1.run(BACKWARD);

  if( received_command == up ) {
     Serial.println("Go FORWARD");
     motor1.run(FORWARD);
     motor2.run(FORWARD);
  }

  // if( result.value == up ) {
  //   motor1.run(FORWARD);
  //   motor2.run(FORWARD);
  // } else if(result.value == down) {
  //   motor1.run(BACKWARD);
  //   motor2.run(BACKWARD);
  // } else if(result.value == stop) {
  //   motor1.run(RELEASE);
  //   motor2.run(RELEASE);
  // } else if(result.value == left) {
  //   motor1.run(FORWARD);
  //   motor2.run(BACKWARD);
  // } else if(result.value == right) {
  //   motor1.run(BACKWARD);
  //   motor2.run(FORWARD);
  // }
}
