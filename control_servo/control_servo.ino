#include <Servo.h>   

Servo myservo;
int pos = 0;
String dataFromPython;

void setup()
{ 
    myservo.attach(9);
    Serial.begin(9600);
    myservo.write(0);
}

void servo_move(String data)
{
    if(data == "1")
    {
        for(pos = 0; pos < 180; pos += 1)
        { 
            myservo.write(pos);
            delay(5);
        }
    
        for(pos = 180; pos>=1; pos-=1) 
        {                           
            myservo.write(pos);
            delay(5);
        }
    }
}

void loop() 
{  
    while(Serial.available())
    {
        dataFromPython = Serial.readStringUtil('\n');
        Serial.write("Successful data transmission \n");
        servo_move(dataFromPython);
    }
}
