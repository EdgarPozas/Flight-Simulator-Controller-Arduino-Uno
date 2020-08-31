//Importación de la libreria para su uso
#include "UnoJoy.h"

//Definiendo las entradas analogicas para cada componente
#define engineRight A0
#define engineLeft A1
#define verticalMovement A2
#define horizontalMovement A3

//Definiendo las variables que contendrán los valores
int engineRight_value = 0;
int engineLeft_value = 0;
int verticalMovement_value = 0;
int horizontalMovement_value = 0;

void setup()
{
  //Definiendo el comportamiento de los pines del Arduino y de la libreria UnoJoy
  pinMode(engineRight, INPUT); 
  pinMode(engineLeft, INPUT); 
  pinMode(verticalMovement, INPUT); 
  pinMode(horizontalMovement, INPUT); 
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  setupUnoJoy();
}

void loop()
{
  //Sensado de los valores de las entradas analógicas y sus correcciones
  engineRight_value=analogRead(engineRight);
  engineLeft_value=1024-analogRead(engineLeft);
  verticalMovement_value=1024-analogRead(verticalMovement);
  horizontalMovement_value=analogRead(horizontalMovement);

  //En caso de necesitarlo descomentar las lineas
  /*Serial.print(engineLeft_value);
  Serial.print(" ");
  Serial.print(engineRight_value);
  Serial.print(" ");
  Serial.print(verticalMovement_value);
  Serial.print(" ");
  Serial.print(horizontalMovement_value);
  Serial.println("");*/

  //Asignación de los elementos a el controlador
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

dataForController_t getControllerData()
{
  //Obtención del controlador
  dataForController_t controllerData = getBlankDataForController();

  //En caso de necesitarlo se pueden configurar otros botones
  controllerData.triangleOn = !digitalRead(2);
  controllerData.circleOn = !digitalRead(3);
  controllerData.squareOn = !digitalRead(4);
  controllerData.crossOn = !digitalRead(5);
  controllerData.dpadUpOn = !digitalRead(6);
  controllerData.dpadDownOn = !digitalRead(7);
  controllerData.dpadLeftOn = !digitalRead(8);
  controllerData.dpadRightOn = !digitalRead(9);
  controllerData.l1On = !digitalRead(10);
  controllerData.r1On = !digitalRead(11);
  controllerData.selectOn = !digitalRead(12);
  controllerData.startOn = !digitalRead(A4);
  controllerData.homeOn = !digitalRead(A5);

  //Las entradas analógicas corresponden a un eje del Joystick
  controllerData.leftStickX = engineRight_value >> 2;
  controllerData.leftStickY = engineLeft_value >> 2;
  controllerData.rightStickX = horizontalMovement_value >> 2;
  controllerData.rightStickY = verticalMovement_value >> 2;
  
  return controllerData;
}
