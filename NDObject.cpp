#include "NDObject.h"

NDObject::NDObject(int w, int h, MicroOLED * oled)
{
    width = w;
    height = h;
    this->oled = oled;
}
void NDObject::begin()
{
    
}
void NDObject::setLoadImg(const uint8_t * img)
{
    memcpy(load_img,img,sizeof(img));
}