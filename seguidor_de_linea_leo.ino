#include <DCMotor.h>
#include <Servo.h>

const int seg_der = 11; //poner pin
const int seg_izq = 13; //poner pin
 
DCMotor motor_izq (4,17,16);//rellenar con los pines
DCMotor motor_der (5,30,41);//rellenar con los pines

const int blanco = 400;

void seguidor() {
  if (analogRead(seg_der)>blanco &&analogRead(seg_izq)>blanco){
    motor_izq.setSpeed(100);
    motor_der.setSpeed(100);
    
  }
  else if (analogRead (seg_der)>blanco && analogRead(seg_izq)<blanco){
    motor_izq.setSpeed(50);
    motor_der.setSpeed(100);
   }
  else if (analogRead (seg_der)<blanco && analogRead(seg_izq)>blanco){
    motor_izq.setSpeed(100);
    motor_der.setSpeed(50);
   }
}

void setup() {

}

void loop() {
  

seguidor ();  

}
