
#include <stdint.h>
#include <Arduino.h>

#include "Sixteen.h"


#define INC_EVERY 60000
#define LCD_EVERY 500

Sixteen sixteen(0x3F);

elapsedMillis lcd_timer;
elapsedMillis inc_timer;

uint32_t counter = 0;


void show_counter() {
    snprintf(sixteen.line0, 17, "counter: %d", counter);
    snprintf(sixteen.line1, 17, "  (light box)");
    sixteen.update();
}

void update_everything() {
    if (inc_timer > INC_EVERY) {
        ++counter;
        inc_timer = 0;
    }
    if (lcd_timer > LCD_EVERY) {
        // show_clock();
        show_counter();
        lcd_timer = 0;
    }
}

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("started");
}

void loop() {
    update_everything();
}
