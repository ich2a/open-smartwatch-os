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
    void draw(); //draws the ui
    void setPNum1(); //gets the input that tells if num1 is positive or negative
    void setNum1(int num1[]); //is used to fill the array that will become num1
    void setOP(); //gets the input to set the operator
    void setPNum2(); //gets the input that tells if num2 is positive or negative
    void setNum2(int num2[]); //is used to fill the array that will become num2
    void equal(); //calculates the output 
    void clear(); //clears num1, num2, and the operator, only the result stays 
    ~OswAppCalculator() {};
  private:
    OswUI* ui;
};