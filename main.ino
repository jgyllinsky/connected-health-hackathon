
#include "NDObject.h"
#include "images.h"

#include "lib1.h"

#define PIN_RESET D0  // Connect RST to pin 9 (req. for SPI and I2C)
#define PIN_DC    D1  // Connect DC to pin 8 (required for SPI)
#define PIN_CS    A2 // Connect CS to pin 10 (required for SPI)
#define WIDTH     64
#define HEIGHT    48

//#define DC_JUMPER 0 // (I2C only) Set to either 0 or 1, matching the value of the DC Jumper

// Declare a MicroOLED object. The parameters include:
// 1 - Reset pin: Any digital pin
// 2 - D/C pin: Any digital pin (SPI mode only)
// 3 - CS pin: Any digital pin (SPI mode only, 10 recommended)
MicroOLED oled(MODE_SPI, PIN_RESET, PIN_DC, PIN_CS); // Example SPI Declaration
//MicroOLED oled(PIN_RESET, DC_JUMPER); // Example I2C Declaration

//NDObject dice(WIDTH,HEIGHT);

//images to use

uint8_t dice_img_2[WIDTH * HEIGHT];
uint8_t xr[WIDTH * HEIGHT];

void setup() {
    // Before you can start using the OLED, call begin() to init
    // all of the pins and configure the OLED.
    memcpy( dice_img_2, NDImages::no_dice_2, sizeof(NDImages::no_dice_2) );
    memcpy( xr, NDImages::no_x, sizeof(NDImages::no_x) );
    NDImages::flip_bytes_img(WIDTH, HEIGHT, dice_img_2);
    NDImages::flip_bytes_img(WIDTH, HEIGHT, xr);
    //dice.setLoadImg(dice_img_2);
    oled.begin();
    //dice.begin();
    NDImages::blit_pixels(WIDTH,HEIGHT,xr,dice_img_2);
}

int x = 0;
int dir = 1;
std::string msg = "NO DICE";

void loop() {

    oled.clear(0);
    oled.drawBitmap( xr );
    oled.drawBitmap( dice_img_2 );

    oled.setFontType(0);
    oled.setCursor(x,0);
    oled.print(msg.c_str());
    oled.display();
    
    delay(30);

    if (x > 64 - msg.size() * 6)
    {
        dir = -1;
    }
    if (x < 0)
    {
        dir = 1;
    }
    
    x += dir;
}
