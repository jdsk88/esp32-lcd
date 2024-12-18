#ifndef HANLE_PASSWORD_RESET_H
#define HANLE_PASSWORD_RESET_H

void handlePasswordReset(AsyncWebServerRequest *request)
{
    if (request->hasParam("ssid"))
    {
        Serial.println("ssid reviced");
        AsyncWebParameter *param1 = request->getParam("ssid");
        AsyncWebParameter *param2 = request->getParam("passwd");
        String value1 = param1->value();
        String value2 = param2->value();

        File file1 = LittleFS.open("/ssid.txt", "w");
        File file2 = LittleFS.open("/passwd.txt", "w");

        file1.print(value1);
        file1.close();
        file2.print(value2);
        file2.close();
        request->send(200, "text/plain", "Value written to file.");
        delay(1000);
        ESP.restart();
    }
    else
    {
        request->send(400, "text/plain", "Missing value parameter.");
    }
}

#endif