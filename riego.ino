// include the library code:
#include <LiquidCrystal.h>
const int sensorPin= A0;
const int sensorventi = 10;
const int sensorlluvi = A1;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(sensorventi, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
 // lcd.print("LCD...");
 //Serial.begin(9600);   //iniciar puerto serie para sensor de lluvia
  pinMode(9, INPUT);  //definir pin como entrada para sensor de lluvia
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
 // lcd.print(millis() / 1000);
 int value = analogRead(sensorPin);
 int valueLlu = 0; //Para el sensor de lluvia;
 valueLlu = digitalRead(9);  //lectura digital de pin
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  lcd.print(celsius);
   lcd.print(" C");
   lcd.begin(16, 2);
   int humedad = analogRead(sensorPin);
   lcd.print(humedad);
   if(valueLlu == LOW) 
   {
      digitalWrite(sensorventi, HIGH);
      lcd.print("Lluvia detectada, el sistema se apagara...");
   }
   else
   {
    if(humedad <= 500)
     {
          digitalWrite(sensorventi, HIGH);
         lcd.print( sensorventi +"   Apagado");  
        //hacer las acciones necesarias
     }
     if(humedad > 500 and humedad <= 700)
     {
        digitalWrite(sensorventi, HIGH);
         lcd.print("Riego Durante 5 Seg");  
         delay(5000);
        //hacer las acciones necesarias
     }
      if(humedad > 700 and humedad <= 800)
      {
        digitalWrite(sensorventi, LOW);
        delay(8000); 
        
         lcd.print(sensorventi + "  Encendido por 8 seg");  
        //hacer las acciones necesarias
      }
      if(humedad > 800 and humedad <= 900)
      {
        digitalWrite(sensorventi, LOW);
        delay(10000); 
        
         lcd.print( sensorventi + "   Encendido por 10 seg");  
        
      }
      if(humedad > 900)
      {
        digitalWrite(sensorventi, LOW);
        delay(12000); 
        
        lcd.print(sensorventi + "  Encendido por 12 seg");  
    
      }
   }
     
    delay(1000);
}
