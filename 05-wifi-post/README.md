# 05-Wifi-Post

## Lesson Objectives
1. Making a POST request to the server via a button press
2. Able to receive a POST request using a Go program

### Running the server app

Make sure to compile and upload the server binary before this step.

```bash
sudo ./server
Server started

Received a POST request from: <ESP32 30:AE:A4:47:9D:48 value 1234>

Received a POST request from: <ESP32 30:AE:A4:47:9D:48 value 1235>

Received a POST request from: <ESP32 30:AE:A4:47:9D:48 value 1236>

```

## Program behaviour

1. Connect to Wifi 
2. On button press
3. Send a POST request in this format `ESP32 30:AE:A4:47:9D:48 value 1234`. The Mac address of the chip and an incrementing number is sent.


## Compiling and running the Arduino program

Before compiling, adjust the constants to suit your test environment.

```C
#define WIFI_SSID "XXX"
#define WIFI_PASS "XXX"
#define HOST "http://X.X.X.X:80/"
```

Press the button to start sending POST requests.

```
00:03:37.122 -> Connecting to XXX
00:03:37.268 -> .
00:03:42.283 -> WiFi connected. IP address is: 192.168.1.163, with Mac Address: 30:AE:A4:47:9D:48
00:03:42.358 -> Setup complete
00:03:45.295 -> Button pressed, sending: ESP32 30:AE:A4:47:9D:48 value 1234
00:03:45.332 -> 200
00:03:45.332 -> 
00:03:46.733 -> Button pressed, sending: ESP32 30:AE:A4:47:9D:48 value 1235
00:03:47.206 -> 200
00:03:47.206 -> 
00:04:01.882 -> Button pressed, sending: ESP32 30:AE:A4:47:9D:48 value 1236
00:04:01.952 -> 200
00:04:01.952 -> 

```