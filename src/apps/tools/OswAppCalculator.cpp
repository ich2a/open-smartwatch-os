/*
    a calculator for addition, subtraction, multiplication, division, square roots, powers, num1 * 10 ^ num2
    with postitive and negativ numebers + generating random numbers
    press btn2 + btn3 to set the cursor a position back
*/

#include "./apps/tools/OswAppCalculator.h"

#include "config_defaults.h"  // Include the config here again to access the language definitions of it
#include "gfx_util.h"
#include "osw_app.h"
#include "osw_hal.h"
#include "osw_ui.h"

#include <osw_config_keys.h>

char signOfNum1 = '+';
int num1[] = {0, 0, 0, 0, 0, 0};
double Num1;
String mathOperation = "+";
char signOfNum2 = '+';
int num2[] = {0, 0, 0, 0, 0, 0};
double Num2;
int8_t position = 0;
uint8_t iNum = 0; //cursor position
double result;
String resultToString;

void OswAppCalculator::setup() {}

void OswAppCalculator::loop() {
    OswHal* hal = OswHal::getInstance();

    if(hal->btnHasGoneDown(BUTTON_2) && hal->btnHasGoneDown(BUTTON_3)) {
        iNum--; //sets the cursor a position back, if you made a mistake
        delay(200); //prevents input while releasing buttons
        position = 0; //sets the current number to 0, else it would be the number you came from
    }

    if(iNum == 0) {
        setSignOfNum1();
    } else if (iNum < 7) {
        setNum1(num1);
    } else if(iNum == 7) {
        setOerator();
    } else if(iNum == 8) {
        setSignOfNum2();
    } else if (iNum > 8 && iNum < 15) {
        setNum2(num2);
    } else if (iNum == 15) {
        calculate();
    } else if (iNum > 15) {
        clear();
    }
    draw();

    hal->requestFlush();
}

void OswAppCalculator::draw() {
    OswHal* hal = OswHal::getInstance();

    hal->gfx()->setTextSize(4);
    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(19, 70);

    if(iNum == 0) {
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(signOfNum1);
        hal->gfx()->setTextSize(4);

    } else {
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(signOfNum1);
        hal->gfx()->setTextSize(4);

    }

    if(iNum == 1) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[0]);

    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[0]);
    }

    if(iNum == 2) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[1]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[1]);
    }

    if(iNum == 3) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[2]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[2]);
    }

    if(iNum == 4) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[3]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[3]);
    }

    if(iNum == 5) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num1[4]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num1[4]);
    }

    if(iNum == 6) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[5]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[5]);
    }

    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextCursor(125, 102);
    if(iNum == 7) {
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(mathOperation);
        hal->gfx()->setTextSize(4);
    } else {
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(mathOperation);
        hal->gfx()->setTextSize(4);
    }

    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(19, 140);

    if(iNum == 8) {
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(signOfNum2);
        hal->gfx()->setTextSize(4);
    } else {
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(signOfNum2);
        hal->gfx()->setTextSize(4);
    }

    if(iNum == 9) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[0]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[0]);
    }

    if(iNum == 10) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[1]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[1]);
    }

    if(iNum == 11) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[2]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[2]);
    }

    if(iNum == 12) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[3]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[3]);
    }

    if(iNum == 13) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num2[4]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num2[4]);
    }

    if(iNum == 14) {
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[5]);
    } else {
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[5]);
    }

    hal->gfx()->fillFrame(0, 160, 240, 10, ui->getSuccessColor());

    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextSize(3);
    hal->gfx()->setTextCursor(120, 210);
    hal->gfx()->setTextColor(ui->getSuccessColor());
    hal->gfx()->print(resultToString);

    hal->gfx()->setTextMiddleAligned();
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->setTextCursor(214, 57);
    hal->gfx()->print("+");
    hal->gfx()->setTextCursor(214, 184);
    hal->gfx()->print("-");
    hal->gfx()->setTextCursor(31, 184);
    hal->gfx()->print(">");
}


void OswAppCalculator::setSignOfNum1() {
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)) {
        position++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)) {
        position--;
    }
    if (position < 0) {
        position = 1;
    }
    if (position > 1) {
        position = 0;
    }

    if (position == 0) {
        signOfNum1 = '+';
    } else if (position == 1) {
        signOfNum1 = '-';
    }

    if (hal->btnHasGoneUp(BUTTON_1)) {
        iNum++;
        position = 0;
    }
}

void OswAppCalculator::setNum1(int num1[]) {
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)) {
        position++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)) {
        position--;
    }
    if (position < 0) {
        position = 9;
    }
    if (position > 9) {
        position = 0;
    }

    num1[iNum-1] = position;

    if (hal->btnHasGoneUp(BUTTON_1)) {
        iNum++;
        position = 0;
    }
}

void OswAppCalculator::setOerator() {
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)) {
        position++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)) {
        position--;
    }
    if (position < 0) {
        position = 7;
    }
    if (position > 7) {
        position = 0;
    }

    switch(position) {
    case 0:
        mathOperation = "+";
        break;
    case 1:
        mathOperation = "-";
        break;
    case 2:
        mathOperation = "*";
        break;
    case 3:
        mathOperation = "/";
        break;
    case 4:
        mathOperation = "square root";
        break;
    case 5:
        mathOperation = "^";
        break;
    case 6:
        mathOperation = "x10^";
        break;
    case 7:
        mathOperation = "random";
        break;
    }

    if (hal->btnHasGoneUp(BUTTON_1)) {
        iNum++;
        position = 0;
    }
}

void OswAppCalculator::setSignOfNum2() {
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)) {
        position++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)) {
        position--;
    }
    if (position < 0) {
        position = 1;
    }
    if (position > 1) {
        position = 0;
    }

    if (position == 0) {
        signOfNum2 = '+';
    } else if (position == 1) {
        signOfNum2 = '-';
    }

    if (hal->btnHasGoneUp(BUTTON_1)) {
        iNum++;
        position = 0;
    }

}

void OswAppCalculator::setNum2(int num2[]) {
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)) {
        position++;
        position++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)) {
        position--;
    }
    if (position < 0) {
        position = 9;
    }
    if (position > 9) {
        position = 0;
    }

    num2[iNum-9] = position;

    if (hal->btnHasGoneUp(BUTTON_1)) {
        iNum++;
        position = 0;
    }
}

void OswAppCalculator::calculate() {
    OswHal* hal = OswHal::getInstance();

    Num1 = num1[0];
    for (uint8_t i=1; i<6; i++) {
        Num1 = Num1 *10 + num1[i];
    }

    Num1 = Num1 / 100;

    Num2 = num2[0];
    for (uint8_t i=1; i<6; i++) {
        Num2 = Num2 *10 + num2[i];
    }

    Num2 = Num2 / 100;

    if (signOfNum1 == '-') {
        Num1 = 0 - Num1;
    }

    if (signOfNum2 == '-') {
        Num2 = 0 - Num2;
    }

    if (mathOperation == "+") {
        result = Num1 + Num2;
    } else if (mathOperation == "-") {
        result = Num1 - Num2;
    } else if (mathOperation == "*") {
        result = Num1 * Num2;
    } else if (mathOperation == "/") {
        result = Num1 / Num2;
    } else if (mathOperation == "square root") {
        result = sqrt(Num2);
    } else if (mathOperation == "^") {
        result = pow(Num1, Num2);
    } else if (mathOperation == "x10^") {
        result = pow(10, Num2) * Num1;
    } else if (mathOperation == "random" && iNum == 15) {
        result = random(-100000, 100001);
        result = result / 100;
        iNum++;
    }

    resultToString = result;

    if (hal->btnHasGoneUp(BUTTON_1)) {
        iNum++;
        position = 0;
    }
}


void OswAppCalculator::clear() {
    position = 0;
    iNum = 0;
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    mathOperation = "+";
    signOfNum1 = '+';
    signOfNum2 = '+';
}

void OswAppCalculator::stop() {}