#pragma once

#include <osw_hal.h>
#include <osw_ui.h>
#include "osw_app.h"


class OswAppFlashLight : public OswApp {
  public:
    OswAppFlashLight(void) {
        ui = OswUI::getInstance();
    };
    virtual void setup() override;
    virtual void loop() override;
    virtual void stop() override;
    void drawBG(bool on);
    void brightness(bool on);
    
    void storeBrightness();
    
    ~OswAppFlashLight() {};

  private:
    OswUI* ui;

};