#ifndef HANDLE_PIN_RESPONSE_H
#define HANDLE_PIN_RESPONSE_H

int handlePinState(uint8_t state)
{
    if (state == LOW)
    {
        return 0;
    }
    else if (state == HIGH)
    {
        return 1;
    }

    return 0;
}

void handlePinStateAndResponse(int pin, uint8_t state, AsyncWebServerRequest *request, String channelName)
{
    StaticJsonDocument<200> infoDocument;
    infoDocument["channelName"] = channelName;
    infoDocument["channelId"] = pin;
    infoDocument["channelState"] = handlePinState(state);
    String jsonString;
    serializeJson(infoDocument, jsonString);
    digitalWrite(pin, state);
    request->send(200, "application/json", jsonString);
}

#endif