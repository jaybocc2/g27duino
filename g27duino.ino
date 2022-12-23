// USB 5 AXIS Controller
// Use with Arduino Leonardo or ProMicro.
// Install Joystick library

// AMSTUDIO 2018
// YT https://www.youtube.com/channel/UCQS1ZB3BVSrBo3tCs7PyfxQ
// Wiring + Setup https://youtu.be/iKIrbF6GnZ0
// Copyright _ Non Commerical_ Not for Resale https://creativecommons.org/licenses/by-nc-nd/4.0/

#include <Joystick.h>

const int buttonCount = 0;
const int hatSwitchCount = 0;
const bool XAxis = false;
const bool YAxis = false;
const bool ZAxis = false;
const bool RxAxis = false;
const bool RyAxis = true; // clutch
const bool RzAxis = false;
const bool rudder = false;
const bool throttle = true;
const bool accelerator = false;
const bool brake = true;
const bool steering = false;

Joystick_ Joystick(
    JOYSTICK_DEFAULT_REPORT_ID,
    JOYSTICK_TYPE_MULTI_AXIS,
    buttonCount, hatSwitchCount,
    XAxis, YAxis, ZAxis,
    RxAxis, RyAxis, RzAxis,
    rudder, throttle,
    accelerator, brake, steering);

int RyAxis_ = 0;
int RzAxis_ = 0;
int Throttle_ = 0;
int RyAxis_a = 0;
int RzAxis_a = 0;
int Throttle_a = 0;
int RyAxis_b = 0;
int RzAxis_b = 0;
int Throttle_b = 0;

const bool initAutoSendState = true;

void setup()
{
    Serial.begin(9600);
    Joystick.begin();
}

void loop()
{
    RyAxis_a = analogRead(A2); // clutch
    RyAxis_b = map(RyAxis_a, 0, 1023, 0, 255);
    Joystick.setRyAxis(RyAxis_b);

    RzAxis_a = analogRead(A1); // brake
    RzAxis_b = map(RzAxis_a, 1023, 0, 0, 1023);
    Joystick.setBrake(RzAxis_b);

    Throttle_a = analogRead(A0); // gas
    Throttle_b = map(Throttle_a, 1023, 0, 0, 1023);
    Joystick.setThrottle(Throttle_b);

    if (Throttle_b == 0)
    {
        Serial.print("ya ");
        Serial.println(RyAxis_a);
        Serial.print("za ");
        Serial.println(RzAxis_a);
        Serial.print("ta ");
        Serial.println(Throttle_a);

        Serial.print("za ");
        Serial.println(RyAxis_b);
        Serial.print("zb ");
        Serial.println(RzAxis_b);
        Serial.print("tb ");
        Serial.println(Throttle_b);
    }

    delay(1);
}