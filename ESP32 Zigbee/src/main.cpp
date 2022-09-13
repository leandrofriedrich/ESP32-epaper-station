#include <Arduino.h>

#include "serial.h"
#include "soc/rtc_wdt.h"

void setup() {
    Serial.begin(115200);
    Serial.print(">\n");
    xTaskCreatePinnedToCore(zbsRxTask, "zbsRX Process", 10000, NULL, 5, NULL,1);
}

void loop() {
    vTaskDelay(30000 / portTICK_PERIOD_MS);
    // dump heap size
    Serial.println(ESP.getFreeHeap());
}