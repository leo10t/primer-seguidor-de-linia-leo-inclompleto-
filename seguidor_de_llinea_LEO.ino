#include <DCMotor.h>
#include <Servo.h>
#include "Infrarrojo.h"

bool inter = 0;//variable para la interseccion 

Infrarrojo infraInterIzq (13,350);
Infrarrojo infraInterDer (11,350);
Infrarrojo infraExterIzq (14,350);
Infrarrojo infraExterDer (15,350);

DCMotor motor_izq (4, 17, 16); //rellenar con los pines
DCMotor motor_der (5, 30, 41); //rellenar con los pines

void mover_izquierda()
{
  motor_izq.setSpeed(-35);
  motor_der.setSpeed(50);
}
void mover_derecha()
{
  motor_der.setSpeed(-55);
  motor_izq.setSpeed(60);
}
void mover_frente()
{
 motor_izq.setSpeed(38);
 motor_der.setSpeed(38);
}


/*void interseccion () {
  if (inter == 0) {//va a doblar a la izq   
    while(analogRead (seguidor_izq)<blanco)
      motor_izq.setSpeed(0);
      motor_der.setSpeed(50);
      inter = 1;
    } 
}*/


void seguidor() {
  if (infraInterDer.lee_blanco() && infraInterIzq.lee_blanco()) {
    mover_frente();
  }
  else if (infraInterDer.lee_blanco() && infraInterIzq.lee_negro()) {
    mover_izquierda();
  }
  else if (infraInterDer.lee_negro() && infraInterIzq.lee_blanco()) {
    mover_derecha();
  }
  //else if(infraExterDer.lee_negro() && infraExterIzq.lee_negro())
    //interseccion();
  
}

 



void setup() {


}

void loop() {

  seguidor();

}


