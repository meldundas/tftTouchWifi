# tftTouchWifi

![image](docs/pics/tftTouchWifiBoard.png)
NucleoF446RE with ILI9341 and TouchGFX
Uses the AT software on an ESP32C3 connected to UART1 on PA9 and PA10.
WIFI_nRST on PA8.
Temperature is sent to Thingspeak and a public MQTT broker.

![image](docs/pics/pinout.png)

A secrets.h file is needed with the following defined:
```
#define SSID "MYSSID"
#define PASSWD "MYPASSWORD"
#define WRITEAPIKEY "THINGSPEAK CHANNEL WRITE API KEY"
```
More details of the steps that were required to use the ESP32C3 for the WiFi
connection is in the docs folder.
[docs/README.md](docs/README.md)
