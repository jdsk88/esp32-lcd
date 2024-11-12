#ifndef WIFI_SUCCESS_STATUS_H
#define WIFI_SUCCESS_STATUS_H

void wifiConnectionSuccessStatus()
{

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Successfully connected to ");
    Serial.println(ssid);
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  }
  else
  {
    Serial.println("Driver could not connect into the network... :(");
  }
}

#endif