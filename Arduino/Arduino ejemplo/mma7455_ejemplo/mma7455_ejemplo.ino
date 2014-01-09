/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por:                                                          **
** Basado en el código de: autorcillo original                   **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el acelerómetro MMA7455                          **
**                                                               **
*******************************************************************
Conexiones:
UNO   MMA7455

3.3V  VCC
GND   GND
A4    SDA
A5    SCL
*/

#include <Wire.h>

//definiciones/////////////////////////
#define MMA_7455_ADDRESS 0x1D //Dirección I2C para el sensor 
#define MMA_7455_MODE_CONTROLL 0x16 // Llama a los sensores Modo de Control 

#define MMA_7455_2G_MODE 0x05 //Ajusta sensibilidad a 2g 
#define MMA_7455_4G_MODE 0x09 //Ajusta sensibilidad a 4g 
#define MMA_7455_8G_MODE 0x01 //Ajusta sensibilidad a 8g

#define X_OUT 0x06 //Registro para leer el Eje X 
#define Y_OUT 0x07 //Registro para leer el Eje Y
#define Z_OUT 0x08 //Registro para leer el Eje Z

//prototipos de funciones
void MMA_7455();
void initSensitivity(int sensitivity);
void calibrateOffset(float x_axis_offset, float y_axis_offset, float z_axis_offset);
unsigned char readAxis(char axis);

//variables globales
int opcion = 0;
int entrada;
float _x_axis_offset;
float _y_axis_offset;
float _z_axis_offset;


//configuracion/////////////////////////
void setup()
{
  Serial.begin(9600);
  MMA_7455();
  // Set the sensitivity you want to use
  // 2 = 2g, 4 = 4g, 8 = 8g
  initSensitivity(2);
  Serial.println("Acelerometro MMA7455");
  Serial.println("eje valor   eje valor  eje valor");
}

//ciclo principal///////////////////////
void loop()
{
  int xAcc = readAxis('x');
  int yAcc = readAxis('y');
  int zAcc = readAxis('z');
  Serial.print("x = ");
  Serial.print(xAcc);
  
  Serial.print("   y = ");
  Serial.print(yAcc);
  
  Serial.print("  z = ");
  Serial.println(zAcc);
  
  delay(500);
}
