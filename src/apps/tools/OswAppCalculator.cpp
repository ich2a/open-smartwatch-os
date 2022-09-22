/*
    a calculator for addition, subtraction, multiplication, division, square roots, powers, num1 * 10 ^ num2
    with postitive and negativ numebers + generating random numbers
    press btn2 + btn3 to set the cursor to the first position 
*/


#include "./apps/tools/OswAppCalculator.h"

#include "config_defaults.h"  // Include the config here again to access the language definitions of it
#include "gfx_util.h"
#include "osw_app.h"
#include "osw_hal.h"
#include "osw_ui.h"

#include <osw_config_keys.h>

char pNum1 = '+';
int num1[] = {0, 0, 0, 0, 0, 0};
double Num1;
String op = "+";
char pNum2 = '+';
int num2[] = {0, 0, 0, 0, 0, 0};
double Num2;
int i = 0;
int iNum = 0;
double result;
String resultS;

void OswAppCalculator::setup() {}

void OswAppCalculator::loop() {
    OswHal* hal = OswHal::getInstance();
    
    if(hal->btnHasGoneDown(BUTTON_2) && hal->btnHasGoneDown(BUTTON_3)){
        iNum = 16;
    }

    if(iNum == 0){
        setPNum1();
    }else if (iNum < 7){
        setNum1(num1);
    }else if(iNum == 7){
        setOP();
    }else if(iNum == 8){
        setPNum2();
    }else if (iNum > 8 && iNum < 15){
        setNum2(num2);
    }else if (iNum == 15){
        equal();
    }else if (iNum > 15){
        clear();
    }
    draw();
    //Serial.println(iNum);

    hal->requestFlush();
    
}

void OswAppCalculator::draw(){
    OswHal* hal = OswHal::getInstance();

    hal->gfx()->setTextSize(4);
    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(19, 70);


    if(iNum == 0){
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(pNum1);
        hal->gfx()->setTextSize(4);
        
    }else{
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(pNum1);
        hal->gfx()->setTextSize(4);

    }

    if(iNum == 1){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[0]);
        
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[0]);
    }

    if(iNum == 2){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[1]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[1]);
    }

    if(iNum == 3){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[2]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[2]);
    }

    if(iNum == 4){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[3]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[3]);
    }

    if(iNum == 5){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num1[4]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num1[4]);
    }

    if(iNum == 6){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num1[5]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num1[5]);
    }




    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextCursor(125, 102);
    if(iNum == 7){
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(op);
        hal->gfx()->setTextSize(4);
    }else{
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(op);
        hal->gfx()->setTextSize(4);
    }




    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(19, 140);


     if(iNum == 8){
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(pNum2);
        hal->gfx()->setTextSize(4);
    }else{
        hal->gfx()->setTextSize(3);
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(pNum2);
        hal->gfx()->setTextSize(4);
    }

    if(iNum == 9){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[0]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[0]);
    }

    if(iNum == 10){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[1]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[1]);
    }

    if(iNum == 11){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[2]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[2]);
    }

    if(iNum == 12){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[3]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[3]);
    }

    if(iNum == 13){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num2[4]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(".");
        hal->gfx()->print(num2[4]);
    }

    if(iNum == 14){
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->print(num2[5]);
    }else{
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->print(num2[5]);
    }

    hal->gfx()->fillFrame(0, 160, 240, 10, ui->getSuccessColor());

    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextSize(3);
    hal->gfx()->setTextCursor(120, 210);
    hal->gfx()->setTextColor(ui->getSuccessColor());
    hal->gfx()->print(resultS);


    hal->gfx()->setTextMiddleAligned();
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->setTextCursor(214, 57);
    hal->gfx()->print("+"); 
    hal->gfx()->setTextCursor(214, 184);
    hal->gfx()->print("-");
    hal->gfx()->setTextCursor(31, 184);
    hal->gfx()->print(">"); 
}


void OswAppCalculator::setPNum1(){
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)){
        i++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)){
        i--;
    }
    if (i < 0){
        i = 1;
    }
    if (i > 1){
        i = 0;
    }

    if (i == 0){
        pNum1 = '+';
    }else if (i == 1){
        pNum1 = '-';
    }

    if (hal->btnHasGoneUp(BUTTON_1)){
        iNum++;
        i = 0;
    }

}

void OswAppCalculator::setNum1(int num1[]){
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)){
        i++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)){
        i--;
    }
    if (i < 0){
        i = 9;
    }
    if (i > 9){
        i = 0;
    }

    num1[iNum-1] = i;

    if (hal->btnHasGoneUp(BUTTON_1)){
        iNum++;
        i = 0;
    }

}

void OswAppCalculator::setOP(){
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)){
        i++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)){
        i--;
    }
    if (i < 0){
        i = 7;
    }
    if (i > 7){
        i = 0;
    }

    switch(i){
        case 0:
            op = "+";
            break;
        case 1:
            op = "-";
            break;
        case 2:
            op = "*";
            break;
        case 3:
            op = "/";
            break;
        case 4:
            op = "square root";
            break;
        case 5:
            op = "^";
            break;
        case 6:
            op = "x10^";
            break;
        case 7:
            op = "random";
            break;
    }

    if (hal->btnHasGoneUp(BUTTON_1)){
        iNum++;
        i = 0;
    }


}

void OswAppCalculator::setPNum2(){
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)){
        i++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)){
        i--;
    }
    if (i < 0){
        i = 1;
    }
    if (i > 1){
        i = 0;
    }

    if (i == 0){
        pNum2 = '+';
    }else if (i == 1){
        pNum2 = '-';
    }

    if (hal->btnHasGoneUp(BUTTON_1)){
        iNum++;
        i = 0;
    }

}

void OswAppCalculator::setNum2(int num2[]){
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneUp(BUTTON_3)){
        i++;
    }
    if (hal->btnHasGoneUp(BUTTON_2)){
        i--;
    }
    if (i < 0){
        i = 9;
    }
    if (i > 9){
        i = 0;
    }

    num2[iNum-9] = i;

    if (hal->btnHasGoneUp(BUTTON_1)){
        iNum++;
        i = 0;
    }

}

void OswAppCalculator::equal(){
    OswHal* hal = OswHal::getInstance();


    Num1 = num1[0];
    for (byte i=1;i<6;i++){
        Num1 = Num1 *10 + num1[i];
    }

    Num1 = Num1 / 100;

    Num2 = num2[0];
    for (byte i=1;i<6;i++){
        Num2 = Num2 *10 + num2[i];
    }

    Num2 = Num2 / 100;

    if (pNum1 == '-'){
        Num1 = 0 - Num1;
    }

    if (pNum2 == '-'){
        Num2 = 0 - Num2;
    }

    if (op == "+"){
        result = Num1 + Num2;
    }else if (op == "-"){
        result = Num1 - Num2;
    }else if (op == "*"){
        result = Num1 * Num2;
    }else if (op == "/"){
        result = Num1 / Num2;
    }else if (op == "root"){
        result = sqrt(Num2);
    }else if (op == "^"){
        result = pow(Num1, Num2);
    }else if (op == "x10^"){
        result = pow(10, Num2) * Num1;
    }else if (op == "random" && iNum == 15){
        result = random(-100000, 100001);
        result = result / 100;
        resultS = String(result, 2);
        iNum++;
    }

    resultS = String(result, 2);

    if (hal->btnHasGoneUp(BUTTON_1)){
        iNum++;
        i = 0;
    }
} 


void OswAppCalculator::clear(){
    i = 0;
    iNum = 0;
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    op = "+";
    pNum1 = '+';
    pNum2 = '+';
}



void OswAppCalculator::stop() {}