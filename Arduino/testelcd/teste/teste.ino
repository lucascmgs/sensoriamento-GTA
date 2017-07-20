#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int MPU=0x68;

class Sensor {
    private:
    int x, y, z;
    
    public:
    Sensor(int givenX, int givenY, int givenZ){
      this->x = givenX;
      this->y = givenY;
      this->z = givenZ;
    }

    void setDimensions(int givenX, int givenY, int givenZ){
      this->x = givenX;
      this->y = givenY;
      this->z = givenZ;
    }

    int getX(){ return this->x;}
    int getY(){ return this->y;}
    int getZ(){ return this->z;}
};

Sensor acelerometro(0, 0, 0);
Sensor giroscopio(0, 0, 0);
int temperatura;
 
void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 

  //Inicializa o MPU-6050
  Wire.write(0); 
  Wire.endTransmission(true);

 
}
 
void loop()
{
  readSensorData();
  printSensorData();
  delay(200);
}

void readSensorData(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); 
  Wire.endTransmission(false);

  Wire.requestFrom(MPU,14,true);  
  acelerometro.setDimensions(Wire.read()<<8|Wire.read(), Wire.read()<<8|Wire.read(), Wire.read()<<8|Wire.read());
  temperatura = Wire.read()<<8|Wire.read();
  giroscopio.setDimensions(Wire.read()<<8|Wire.read(), Wire.read()<<8|Wire.read(), Wire.read()<<8|Wire.read());
  
}

void printSensorData(){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Acel.");
  lcd.setCursor(1, 1);
  lcd.print(acelerometro.getX());
  lcd.setCursor(1, 2);
  lcd.print(acelerometro.getY());
  lcd.setCursor(1, 3);
  lcd.print(acelerometro.getZ());
  lcd.setCursor(8, 0);
  lcd.print("Gir.");
  lcd.setCursor(8, 1);
  lcd.print(giroscopio.getX());
  lcd.setCursor(8, 2);
  lcd.print(giroscopio.getY());
  lcd.setCursor(8, 3);
  lcd.print(giroscopio.getZ());

}
