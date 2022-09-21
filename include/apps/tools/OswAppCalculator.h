#pragma once

#include <osw_hal.h>
#include <osw_ui.h>
#include "osw_app.h"


class OswAppCalculator : public OswApp {
  public:
    OswAppCalculator(void) {
        ui = OswUI::getInstance();
    };
    virtual void setup() override;
    virtual void loop() override;
    virtual void stop() override;
    void draw();
    void setPNum1();
    void setNum1(int num1[]);
    void setOP();
    void setPNum2();
    void setNum2(int num2[]);
    void equal();
    void clear();


    ~OswAppCalculator() {};

  private:
    OswUI* ui;

};