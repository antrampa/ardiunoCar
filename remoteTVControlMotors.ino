#include <AFMotor.h>
#include <IRremote.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

IRrecv IR(A0);
decode_results result;

int Speed = 235;

const int up = 0;
const int down = 0;
const int left = 0;
const int right = 0;
const int stop = 0;

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  Serial.println("Lets testing...");
  IR.enableIRIn();

}

void loop() {
  delay(500);
  // if(IR.decode(&result)){
  //   Serial.println(result.value);
  //   IR.resume();
  // }

  // delay(100);
  // //TEST MOTOR
  motor2.run(BACKWARD);
  motor1.run(BACKWARD);

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
