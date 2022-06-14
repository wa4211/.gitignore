#include <EEPROM.h> 
#define readMode 3 
#define writeMode 4 
int addrR = 9; 
int addrW = 9; 
byte data;
void setup(){ 
pinMode(readMode, INPUT); 
pinMode(writeMode, INPUT); 
Serial.begin(9600); 
} 
void loop(){ 
if(digitalRead(readMode) == 0){
delay(500); 
data = EEPROM.read(addrR); 
Serial.print("Read Address "); 
Serial.print(addrR, HEX); 
Serial.print(" : "); 
Serial.println(data); 
} 
if(digitalRead(writeMode) == 0){ 
delay(150); 
data = EEPROM.read(addrW); 
data++; 
 
if(data<256) EEPROM.write(addrW, data); 
else data = 0;
Serial.print("Write Address "); 
Serial.print(addrW, HEX); 
Serial.print(" : "); 
Serial.println(data); 
addrR = addrW; 
 
if(addrW<255) addrW++; 
else addrW = 0; 
delay(500); 
} 
}
