#include <Watchy.h> //include the Watchy library
#include "background.h"
#include <Technology48pt7b.h>
#include <Technology18pt7b.h>
        

class WatchFace : public Watchy { //inherit and extend Watchy class
  public:
    void drawWatchFace() { //override this method to customize how the watch face looks
      
      int16_t  x1, y1, lasty;
      uint16_t w, h;
      String textstring;
      
      //drawbg
      display.fillScreen(GxEPD_BLACK);
      display.drawBitmap(0, 0, background, 200, 200, GxEPD_WHITE);
      
      display.setFont(&Technology48pt7b);
      display.setTextColor(GxEPD_BLACK);
      display.setTextWrap(false);

      //draw time
      textstring = currentTime.Hour;
      if (currentTime.Minute < 10) {
        textstring += ":0";
      } else {
        textstring += ":";
      }
      textstring += currentTime.Minute;
      display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
      display.setCursor(100-w/2, 152);
      display.print(textstring);

      // draw battery
      float batt = (getBatteryVoltage()-3.3)/0.9;
      if (batt > 0) {
       display.fillRect(160,53,15*batt,6,GxEPD_BLACK);
      }                 
    }
};

WatchFace m; //instantiate your watchface

void setup() {
  m.init(); //call init in setup
}

void loop() {
  // this should never run, Watchy deep sleeps after init();
}
