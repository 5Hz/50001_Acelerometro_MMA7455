

#include <Wire.h> //Include the Wire library
#include <MMA_7455.h> //Include the MMA_7455 library
extern "C" { 
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}

MMA_7455 mySensor = MMA_7455(); //Make an instance of MMA_7455

char x, y, z; //Variables for the values from the sensor
long longX, longY, longZ;
int barras;
int opcion = 0;
int entrada;

void setup()
{
  Serial.begin(9600);
  // Set the sensitivity you want to use
  // 2 = 2g, 4 = 4g, 8 = 8g
  mySensor.initSensitivity(2);
  // Calibrate the Offset, that values corespond in 
  // flat position to: xVal = -30, yVal = -20, zVal = +20
  // !!!Activate this after having the first values read out!!!
  //mySensor.calibrateOffset(0.23, -43.2, 12.43);
  
}

void loop()
{
 if (opcion == 1)  // indica que se seleccionó una opción válida
    leer_sensor_x();
    if (opcion == 2)  // indica que se seleccionó una opción válida
    leer_sensor_y();
    if (opcion == 3)  // indica que se seleccionó una opción válida
    leer_sensor_z();

   if ((opcion == 4) || (opcion == 0))
    menu();
  if (Serial.available()){
    entrada=Serial.read();
    if(entrada=='*'){
      menu();
    }
    
  }
}

void menu(){
  int entradaMenu;
  Serial.println("-------------------5HZ ELECTRONICA---------------------------");
  Serial.println("");
  Serial.println("                     PRESENTA");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("      BIEVENIDO AL PROGRAMA DE PRUEBAS DEL MMA7455");
  Serial.println("");
  Serial.println("                 YA TIENES TODO?");
Serial.println("");
    Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("MENU PRINCIPAL");
  Serial.println("1- X");
  Serial.println("2- Y");
  Serial.println("3- Z");
  Serial.println("4- SCANNER");
 
 
  do{
  }while(Serial.available()==0);
      entradaMenu=Serial.read();
    switch(entradaMenu){
   
    case '4':
      
       Serial.println("");
      Serial.println("SCANNER I2C");
      StartScan();
      delay(1000);
      opcion = 4;
      break;
      
      
        case '1':
      Serial.println("");
      Serial.println("X");
      Serial.println(".............");
      delay(1000);
      opcion = 1;
      break;
      
      
        case '2':
 
      Serial.println("");
      Serial.println("Y");
      Serial.println(".............");
      delay(1000);
      opcion = 2;
      break;
      
      
        case '3':
     Serial.println("");
      Serial.println("Z");
      Serial.println(".............");
      delay(1000);
      opcion = 3;
      break;
      
      
    default:
      Serial.println("Solo hay cuatro opciones... 1 2,3 y 4...  =) ");
      opcion = 0;
      break;
    }
    
    if ((opcion == 1) || (opcion == 2) || (opcion == 3))
    Serial.println("Hola soy la TERMINAL DE 5Hz (teclea * para ir al menu) cuando termines ");
    delay(1000);

}

void leer_sensor_x(){
    x = mySensor.readAxis('x'); //Read out the 'x' Axis
  longX=x;
  
    longX=map(longX,-90,90,0,255);
  barras=longX/3;
  for (int i=0; i <= barras; i++)
  Serial.print("x");
  Serial.print(" ");
//  Serial.print("sensor = " );                       
  Serial.println(longX,DEC);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   
    delay(10); 
}

void leer_sensor_y() {
    y = mySensor.readAxis('y'); //Read out the 'y' Axis
      longY=y;
    longY=map(longY,-90,90,0,255);
  barras=longY/3;
  for (int i=0; i <= barras; i++)
  Serial.print("y");
  Serial.print(" ");                    
  Serial.println(longY,DEC);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10); 
}

void leer_sensor_z() {
    z = mySensor.readAxis('z'); //Read out the 'z' Axis


  longZ=z;


  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  
  

  
    longZ=map(longZ,-90,90,0,255);
  barras=longZ/3;
  for (int i=0; i <= barras; i++)
  Serial.print("z");
  Serial.print(" ");                    
  Serial.println(longZ,DEC);      
//  Serial.print("output = ");      
//  Serial.println(outputValue);   

  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10); 
  
}







