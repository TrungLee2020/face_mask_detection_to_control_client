#include <Servo.h>   

Servo myservo;
int pos = 0;
String dataFromPython;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    myservo.attach(9);
    Serial.begin(9600);
   // myservo.write(0);
}

void servo_move(String data)
{
    if(data == "1")
    {

        for(pos = 0; pos < 180; pos += 1)
        {
            myservo.write(pos);
            delay(10);
        }
        for(pos = 180; pos>=1; pos-=1)
        {
            myservo.write(pos);
            delay(10);
        }
    }
    else
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        delay(1000);
    }

}

void loop()
{
    while(Serial.available() > 0)
    {
        dataFromPython = Serial.readString().toInt();
        Serial.write("Successful data transmission \n");
        servo_move(dataFromPython);
    }
}
