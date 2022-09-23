#pragma once

#include <osw_hal.h>
#include <osw_ui.h>
#include "osw_app.h"


class OswAppFlashLight : public OswApp {
  public:
    OswAppFlashLight(void) {
        ui = OswUI::getInstance();
    };
    virtual void setup() override; //calls storeBrighntess();
    virtual void loop() override; //checks for button presses and turns the flashlight on/off
    virtual void stop() override; //sets the brightness to the initial value 
    void drawBG(bool on); //draws the app name when the flashlight is turned off and a circle 
    void brightness(bool on); // shows the brighntess when the flashlight is turned on
    
    void storeBrightness(); //stores the brightness to set it to the initial value it was when the app started (usefull in the dark)
    
    ~OswAppFlashLight() {};

  private:
    OswUI* ui;

};