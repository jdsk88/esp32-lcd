#ifndef HANDLE_INFO_RESPONSE_H
#define HANDLE_INFO_RESPONSE_H

void handleInfoResponse(AsyncWebServerRequest *request)
{
    StaticJsonDocument<200> infoDocument;
    infoDocument["deviceName"] = "iSW4";
    infoDocument["deviceType"] = "relaySwitch";
    infoDocument["deviceIp"] = WiFi.localIP();
    infoDocument["frendlyName"] = "Kuchnia";
    infoDocument["manufacturer"] = "iSter";
    String jsonString;
    serializeJson(infoDocument, jsonString);
    request->send(200, "application/json", jsonString);
}

#endif