// moritz.kemper@zhdk.ch
// ZHdK, 03/04/2012
// Released under Creative Commons Licence
    
void MMA_7455()
{ 
  Wire.begin();
}

void initSensitivity(int sensitivity)
{
  //delay(100);
  Wire.beginTransmission(MMA_7455_ADDRESS);
  Wire.write(MMA_7455_MODE_CONTROLL);
  if(sensitivity == 2) Wire.write(MMA_7455_2G_MODE);  //Set Sensitivity to 2g Detection
  if(sensitivity == 4) Wire.write(MMA_7455_4G_MODE);  //Set Sensitivity to 4g Detection
  if(sensitivity == 8) Wire.write(MMA_7455_8G_MODE);  //Set Sensitivity to 8g Detection
  Wire.endTransmission();
  //delay(100);
}

unsigned char readAxis(char axis)
{
  unsigned char _buffer;
  Wire.beginTransmission(MMA_7455_ADDRESS);
  if(axis == 'x' || axis == 'X') Wire.write(X_OUT);
  if(axis == 'y' || axis == 'Y') Wire.write(Y_OUT);
  if(axis == 'z' || axis == 'Z') Wire.write(Z_OUT);
  Wire.endTransmission();
  Wire.beginTransmission(MMA_7455_ADDRESS);
  Wire.requestFrom(MMA_7455_ADDRESS, 1);
  if(Wire.available()) _buffer = Wire.read();
  return _buffer;
}


//==========================================================================
