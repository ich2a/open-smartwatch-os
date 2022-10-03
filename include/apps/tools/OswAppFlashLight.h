#pragma once

#include <osw_hal.h>
#include <osw_ui.h>
#include "osw_app.h"


class OswAppFlashLight : public OswApp {
  public:
    OswAppFlashLight(void) {
        ui = OswUI::getInstance();
    };
    ~OswAppFlashLight() {};
  private:
    OswUI* ui;
    virtual void setup() override;
    virtual void loop() override; //checks for button presses and turns the flashlight on/off
    virtual void stop() override;
<<<<<<< HEAD
    void draw(short flashlightBrightness, bool on); 
=======
    <<<<<<< HEAD
    void draw(short flashlightBrightness, bool on);
    =======
        void draw(bool on);
    >>>>>>> 505875b0ef8b4acc39692e585ba10b923335750c
>>>>>>> c1b661af2e8babedaf67d81168c4e4df68e630fd

};