/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC sample source code
*                          配套  M5StickC 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/m5stickc
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/m5stickc
*
* Describe:  MQTT.
* Date: 2021/11/5
*******************************************************************************
*/
#include <PubSubClient.h>
#include <WiFi.h>

#include "M5StickC.h"

WiFiClient espClient;
PubSubClient client(espClient);

// Configure the name and password of the connected wifi and your MQTT Serve
// host.  配置所连接wifi的名称、密码以及你MQTT服务器域名
const char* ssid        = "iotempire-KEP";
const char* password    = "iotempireKEP";
const char* mqtt_server = "192.168.12.1";

unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (128)
char msg[MSG_BUFFER_SIZE];
int value = 0;
float gyroX_f, gyroY_f, gyroZ_f;


void setupWifi();
void callback(char* topic, byte* payload, unsigned int length);
void reConnect();


void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.IMU.Init();

    setupWifi();
    client.setServer(mqtt_server,
                     1883);  // Sets the server details.  配置所连接的服务器
    client.setCallback(
        callback);  // Sets the message callback function.  设置消息回调函数
}

void loop() {
    if (!client.connected()) {
        reConnect();
    }
    client.loop();  // This function is called periodically to allow clients to
                    // process incoming messages and maintain connections to the
                    // server.
    //定期调用此函数，以允许主机处理传入消息并保持与服务器的连接

    unsigned long now =
        millis();  // Obtain the host startup duration.  获取主机开机时长
    if (now - lastMsg > 100) {
        lastMsg = now;
        ++value;
        if (value + 4 == 0) {
            M5.Lcd.fillScreen(BLACK);
            M5.Lcd.setCursor(0, 0);
        }
        M5.Lcd.setCursor(0, 0);

        M5.IMU.getGyroData(&gyroX_f, &gyroY_f,&gyroZ_f); // o/s
        float accX, accY, accZ;
         M5.IMU.getAccelData(&accX, &accY, &accZ);
          

        snprintf(msg, MSG_BUFFER_SIZE, "%7.2f",
                 accY);  // Format to the specified string and store it in MSG.
                          // 格式化成指定字符串并存入msg中
        M5.Lcd.println(msg);
        M5.Lcd.setCursor(0, 45);
        M5.Lcd.printf("X:%5.2f/nY:%5.2f/nZ:%5.2f ", accX, accY, accZ);
        client.publish("sensors/accel", msg);  // Publishes a message to the specified
                                         // topic.  发送一条消息至指定话题
      
    }
}

void setupWifi() {
    delay(10);
    M5.Lcd.printf("Connecting to %s", ssid);
    WiFi.mode(
        WIFI_STA);  // Set the mode to WiFi station mode.  设置模式为WIFI站模式
    WiFi.begin(ssid, password);  // Start Wifi connection.  开始wifi连接

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        M5.Lcd.print(".");
    }
    M5.Lcd.printf("\nSuccess\n");
    M5.Lcd.fillScreen(BLACK);

}

void callback(char* topic, byte* payload, unsigned int length) {
    M5.Lcd.print("Message arrived [");
    M5.Lcd.print(topic);
    M5.Lcd.print("] ");
    for (int i = 0; i < length; i++) {
        M5.Lcd.print((char)payload[i]);
    }
    M5.Lcd.println();
}

void reConnect() {
    while (!client.connected()) {
        M5.Lcd.print("Attempting MQTT connection...");
        // Create a random client ID.  创建一个随机的客户端ID
        String clientId = "M5Stack-";
        clientId += String(random(0xffff), HEX);
        // Attempt to connect.  尝试重新连接
        if (client.connect(clientId.c_str())) {
            M5.Lcd.printf("\nSuccess\n");
            M5.Lcd.fillScreen(BLACK);

            // Once connected, publish an announcement to the topic.
            // 一旦连接，发送一条消息至指定话题
            //client.publish("M5Stack", "hello world");
            // ... and resubscribe.  重新订阅话题
            //client.subscribe("M5Stack");
        } else {
            M5.Lcd.print("failed, rc=");
            M5.Lcd.print(client.state());
            M5.Lcd.println("try again in 5 seconds");
            delay(5000);
        }
    }
}
