#include "./apps/tools/OswAppFlashLight.h"

#include "config_defaults.h"  // Include the config here again to access the language definitions of it
#include "gfx_util.h"
#include "osw_app.h"
#include "osw_hal.h"
#include "osw_ui.h"

#include <osw_config_keys.h>

bool on = false;
uint8_t startBrightness;


void OswAppFlashLight::setup() {
    OswHal* hal = OswHal::getInstance();
    hal->setBrightness(OswConfigAllKeys::settingDisplayBrightness.get());
    storeBrightness();
    Serial.println("setup");
    Serial.println(OswConfigAllKeys::settingDisplayBrightness.get());
    
}

void OswAppFlashLight::loop() {
    OswHal* hal = OswHal::getInstance();

    if(hal->btnHasGoneUp(BUTTON_1)){
        if (on == true){
            on = false;
        }else {
            on = true;
        }
    }
    drawBG(on);
    brightness(on);

    hal->requestFlush();
    
}

void OswAppFlashLight::storeBrightness(){ //when the app stops, the brigthness gets set to the value it was when the app started 
    startBrightness = OswConfigAllKeys::settingDisplayBrightness.get();
    Serial.println("store: ");
    Serial.println(OswConfigAllKeys::settingDisplayBrightness.get());

}

void OswAppFlashLight::drawBG(bool on){
    OswHal* hal = OswHal::getInstance();

    hal->gfx()->fillCircle(120, 120, 120, ui->getSuccessColor());
    if (on == true){
        hal->gfx()->fillCircle(120, 120, 115, ui->getForegroundColor());
    }else{
        hal->gfx()->fillCircle(120, 120, 115, ui->getBackgroundColor());
        hal->gfx()->setTextSize(3.5);
        hal->gfx()->setTextCenterAligned();
        hal->gfx()->setTextCursor(120, 125);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print("Flashlight");
    }

    
}

void OswAppFlashLight::brightness(bool on){
    OswHal* hal = OswHal::getInstance();
    if (hal->btnHasGoneDown(BUTTON_3)) {
        hal->increaseBrightness(50);
    }
    if (hal->btnHasGoneDown(BUTTON_2)) {
        hal->decreaseBrightness(50);
    }
    hal->gfx()->setTextSize(3);
    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextCursor(120, 125);
    hal->gfx()->setTextColor(ui->getBackgroundColor());
    if (on == true){
        hal->gfx()->print(hal->screenBrightness());
    }
}



void OswAppFlashLight::stop() {
    OswHal* hal = OswHal::getInstance();
    hal->setBrightness(startBrightness);
}