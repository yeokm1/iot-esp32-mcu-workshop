# 06-Wifi-Get

## Lesson Objectives
1. Making a Get Request to a server to get instruction
2. Serve a GET request using a Go program

## Setting up and running server
Use the same setup steps as Lesson 5.

### Running the server app

```bash
yeokm1@YKM-testing:~$ sudo ./server
Server started
off
on
```

## Program behaviour

1. Connect to Wifi 
2. Issue a Get request to server at regular intervals
3. If the text `on` is received, the LED is turned On and vice-versa for `off`.


## Compiling and running the Arduino program

Before compiling, adjust the constants to suit your test environment.

```C
#define WIFI_SSID "XXX"
#define WIFI_PASS "XXX"
#define HOST "http://X.X.X.X:80/"
```

Press the button to start sending POST requests.

```
00:37:15.663 -> Connecting to XXX
00:37:15.766 -> .
00:37:20.790 -> WiFi connected. IP address is: 192.168.1.163, with Mac Address: 30:AE:A4:47:9D:48
00:37:20.898 -> Setup complete
00:37:32.909 -> Got On so turn LED on
00:43:45.063 -> Got Off so turn LED off
00:43:48.028 -> Got On so turn LED on

```