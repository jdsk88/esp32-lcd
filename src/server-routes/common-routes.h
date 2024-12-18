#include "server-response/handle-info-response.h"
#include "server-response/handle-pin-response.h"
extern AsyncWebServer server; // Declare the server instance

#ifndef COMMON_ROUTES_H
#define COMMON_ROUTES_H

void commonRoutes()
{
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/index.html", String(), false); });

  server.on("/info", HTTP_GET, [](AsyncWebServerRequest *request)
            { handleInfoResponse(request); });

  server.on("/favicon.gif", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/favicon.gif", String(), false); });

  server.on("/assets/index-5bcc364a.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/assets/index-5bcc364a.css", String(), false); });

  server.on("/assets/index-5778820d.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/assets/index-5778820d.js", String(), false); });

  server.on("/ssid.txt", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(LittleFS, "/ssid.txt", String(), false); });

  server.on("/wifiSettings", HTTP_GET, handlePasswordReset);

  server.on("/wifi-search", HTTP_GET, [](AsyncWebServerRequest *request)
            { WiFi.scanNetworksAsync([request](int numOfNetworks)
                                     {
      if (numOfNetworks == WIFI_SCAN_FAILED)
      {
        request->send(500, "text/plain", "Failed to scan networks");
        return;
      }
      
      DynamicJsonDocument jsonDoc(numOfNetworks * 200);
      JsonArray jsonArray = jsonDoc.to<JsonArray>();

      for (int i = 0; i < numOfNetworks; i++)
      {
        JsonObject networkJson = jsonArray.createNestedObject();
        networkJson["ssid"] = WiFi.SSID(i);
        networkJson["rssi"] = WiFi.RSSI(i);
        networkJson["encryption"] = WiFi.encryptionType(i);
      }

      String jsonString;
      serializeJson(jsonArray, jsonString);

      request->send(200, "application/json", jsonString); }); });
}

#endif