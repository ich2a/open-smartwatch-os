#include "./apps/tools/OswAppGet.h"

#include "config_defaults.h"  // Include the config here again to access the language definitions of it
#include "gfx_util.h"
#include "osw_app.h"
#include "osw_hal.h"
#include "osw_ui.h"
#include <services/OswServiceTasks.h>
#include <time.h>
#include <osw_config_keys.h>
#ifdef OSW_FEATURE_WIFI
#include <services/OswServiceTaskWiFi.h>
#endif
#include <HTTPClient.h>


bool enableDecoration = true; //set to false to hide the circle and the buttons  
String location;
String info;
int iLocation = 1;
int iInfo = 1;
float data = -100;

void OswAppGet::setup() {}

void OswAppGet::loop() {
    OswHal* hal = OswHal::getInstance();

    if(enableDecoration == true){
        drawUi();
    }
    
    info = changeInfo();
    location = changeLocation();
    drawLocation(location);
    drawInfo(info);

    fetchData(location, info);
    drawData(data, info);

    hal->requestFlush();
    
}

void OswAppGet::drawUi() {
    OswHal* hal = OswHal::getInstance();
    uint16_t color = ui->getSuccessColor();
    hal->gfx()->setTextSize(2);
    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextCursor(125, 50);
    hal->gfx()->print("Fetch Data");
    hal->gfx()->drawCircle(120, 120, 110, color);

    hal->gfx()->fillCircle(31, 58, 10, ui->getForegroundDimmedColor()); //btnReset
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->setTextSize(2);
    hal->gfx()->setTextMiddleAligned();
    hal->gfx()->setTextCursor(32, 58);
    hal->gfx()->print("R"); //reset
    hal->gfx()->fillCircle(32, 184, 10, ui->getForegroundDimmedColor()); //btn1
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->setTextCursor(33, 184);
    hal->gfx()->print("F"); // fetch data from server
    hal->gfx()->fillCircle(209, 57, 10, ui->getForegroundDimmedColor()); //btn2
    hal->gfx()->setTextCursor(210, 57);
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->print("L"); //change location
    hal->gfx()->fillCircle(208, 184, 10, ui->getForegroundDimmedColor()); //btn3
    hal->gfx()->setTextCursor(209, 184);
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->print("I"); //change information

}


String OswAppGet::changeLocation(){
    OswHal* hal = OswHal::getInstance();

    if (hal->btnHasGoneDown(BUTTON_3)){
        iLocation++;
        data = -100;
    }
    if (iLocation >= 4){
        iLocation = 1;
    }
    switch(iLocation){
        case 1:
            location = "Room";
            break;
        case 2:
            location = "Room2";
            break;
        case 3:
            location = "Out";
            break;
    }
    return location;
}

String OswAppGet::changeInfo(){
    OswHal* hal = OswHal::getInstance();
    
    if (hal->btnHasGoneDown(BUTTON_2)){
        iInfo++;
        data = -100;
        
    }
    if (iInfo >= 4){
        iInfo = 1;
    }

    switch(iInfo){
        case 1:
            info = "temp";
            break;
        case 2:
            info = "hum";
            break;
        case 3:
            info = "press";
            break;
    }
    return info;
}
 
void OswAppGet::drawLocation(String location){
    OswHal* hal = OswHal::getInstance();

    hal->gfx()->setTextSize(2);
    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(35, 90);
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->print("Location: ");
    hal->gfx()->setTextColor(ui->getSuccessColor());
    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextCursor(120, 110);
    hal->gfx()->print(location);
 
}

void OswAppGet::drawInfo(String info){
    OswHal* hal = OswHal::getInstance();

    hal->gfx()->setTextSize(2);
    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(35, 130);
    hal->gfx()->setTextColor(ui->getForegroundColor());
    hal->gfx()->print("Information: ");
    hal->gfx()->setTextColor(ui->getSuccessColor());
    hal->gfx()->setTextCenterAligned();
    hal->gfx()->setTextCursor(120, 150);
    hal->gfx()->print(info);

}

float OswAppGet::fetchData(String locataion, String info){
    OswHal* hal = OswHal::getInstance();
    
    if(hal->btnHasGoneUp(BUTTON_1)){  
        OswServiceAllTasks::wifi.enableWiFi();
        OswServiceAllTasks::wifi.connectWiFi();
    }
    if (OswServiceAllTasks::wifi.isConnected()) {
        HTTPClient http;

        http.begin("http://192.168.178.177/sendData.php?info=" + info + "&location=" + location); 
        int httpCode = http.GET();                                       
    
        if (httpCode > 0) { 
    
            String payload = http.getString();
            //Serial.println(httpCode);
            //Serial.println(payload);
            data = payload.toFloat();
            //Serial.println("payload: ");
            //Serial.println(data);
        }
    
        else {
        //Serial.println("Error on HTTP request");
        //Serial.println(httpCode);
        }
    
        http.end(); 

        OswServiceAllTasks::wifi.disconnectWiFi();
        OswServiceAllTasks::wifi.disableWiFi();

        return data;
    }
}



void OswAppGet::drawData(float data, String info){
    OswHal* hal = OswHal::getInstance();

    
    if (data == -100){
        hal->gfx()->setTextColor(ui->getForegroundColor());
        hal->gfx()->setTextCenterAligned();
        hal->gfx()->setTextCursor(122, 175);
        hal->gfx()->print("btnF to");
        hal->gfx()->setTextCursor(122, 190);
        hal->gfx()->print("refresh");
    }else{
        hal->gfx()->setTextColor(ui->getSuccessColor());
        hal->gfx()->setTextLeftAligned();
        hal->gfx()->setTextCursor(65, 185);
        hal->gfx()->setTextSize(3);
        hal->gfx()->print(data);
        if (info == "temp"){
            hal->gfx()->print("C");
        }else if (info == "hum"){
            hal->gfx()->print("%");
        }else if (info == "press"){
            hal->gfx()->print("mbar");
        }
    }
}

void OswAppGet::stop() {
    OswHal* hal = OswHal::getInstance();

    OswServiceAllTasks::wifi.disconnectWiFi();
    OswServiceAllTasks::wifi.disableWiFi();
}