#include "lib1.h"

class NDObject
{
public:
    NDObject(int w, int h, MicroOLED * oled);
    void begin();
    void setLoadImg(const uint8_t * img);
private:
    MicroOLED * oled;
    uint8_t * load_img;
    int width;
    int height;
};