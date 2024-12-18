#ifndef GPIO_ROUTES_H
#define GPIO_ROUTES_H

void gpioRoutes()
{
  server.on("/pin/2/0", HTTP_GET, [](AsyncWebServerRequest *request)
            { handlePinStateAndResponse(2, LOW, request, "kuchnia"); });

  server.on("/pin/2/1", HTTP_GET, [](AsyncWebServerRequest *request)
            { handlePinStateAndResponse(2, HIGH, request, "kuchnia"); });

  server.on("/pin/4/0", HTTP_GET, [](AsyncWebServerRequest *request)
            { handlePinStateAndResponse(4, LOW, request, "jadalnia"); });

  server.on("/pin/4/1", HTTP_GET, [](AsyncWebServerRequest *request)
            { handlePinStateAndResponse(4, HIGH, request, "jadalnia"); });
}

#endif