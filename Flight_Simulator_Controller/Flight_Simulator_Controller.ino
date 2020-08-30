#include "UnoJoy.h"

int avance_potenciometro = 0;

void setup()
{
  pinMode(A0, INPUT);
  
  setupUnoJoy();
}

void loop()
{
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
  avance_potenciometro = analogRead(2); 
}

dataForController_t getControllerData(){

  dataForController_t controllerData = getBlankDataForController();
  
  // si se quiere trabajar con Joystick´s analogos, que no solo lean HIGH y LOW se usa el siguiente codigo
     //controllerData.leftStickX = analogRead(A0) >> 2;
     controllerData.leftStickY = analogRead(A0) >> 2;
  //   controllerData.rightStickX = analogRead(A2) >> 2;
  //   controllerData.rightStickY = analogRead(A3) >> 2;

  // para este ejemplo no se usan ya que al no tener ningun Joystick conectado, mantendria
  // valores de estarse moviendo, lo cual no queremos a la hora de configurarlo en un juego
  
  return controllerData;
}
