#pragma once

#include <osw_hal.h>
#include <osw_ui.h>
#include "osw_app.h"


class OswAppGet : public OswApp {
  public:
    OswAppGet(void) {
        ui = OswUI::getInstance();
    };
    virtual void setup() override;
    virtual void loop() override;
    virtual void stop() override;
    void drawUi();
    void drawLocation(String location);
    void drawInfo(String info);
    String changeInfo();
    String changeLocation();
    void drawData(float data, String info);
    float fetchData(String location, String info);
    ~OswAppGet() {};

  private:
    OswUI* ui;

};