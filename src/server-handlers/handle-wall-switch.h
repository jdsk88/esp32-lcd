#ifndef HANDLE_WALL_SWITCH_H
#define HANDLE_WALL_SWITCH_H

void handleWallSwitch(int buttonPin, int relayPin)
{
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW)
    {
        relay1State = !relay1State;
        digitalWrite(relayPin, relay1State);
        delay(250);
    }
}

#endif