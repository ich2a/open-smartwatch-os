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
    virtual void loop() override; //checks the cursor position (iNum) and starts the appropriate function
    virtual void stop() override;
    ~OswAppCalculator() {};
  private:
    OswUI* ui;
    void draw(); //draws the ui
    void setSignOfNum1(); //gets the input that tells if num1 is positive or negative
    void setNum1(int num1[]); //is used to fill the array that will become num1
    void setOerator(); //gets the input to set the operator
    void setSignOfNum2(); //gets the input that tells if num2 is positive or negative
    void setNum2(int num2[]); //is used to fill the array that will become num2
    void calculate(); //calculates the output
    void clear(); //clears num1, num2, and the operator, only the result stays
};